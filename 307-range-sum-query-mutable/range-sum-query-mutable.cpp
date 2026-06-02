class NumArray {
    vector<int>tree;int n;
public:
    void build(vector<int>& nums, int start, int end, int ind){
        if(end==start){
            tree[ind]=nums[start];
        }
        else{
            int mid=(start+end)/2;
            build(nums, start, mid, 2*ind+1);
            build(nums, mid+1, end, 2*ind+2);
            tree[ind]=tree[2*ind+1]+tree[2*ind+2];
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        build(nums,0,n-1,0);
    }
    void upd(int index, int val, int s, int e, int i){
        int m=(s+e)/2;
        if(s==e){tree[i]=val;return;}
        if(index<=m)upd(index, val, s, m, 2*i+1);
        else upd(index, val,m+1, e, 2*i+2);
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }
    void update(int index, int val) {
        upd(index, val, 0, n-1, 0);
    }
    int sum(int l, int r, int start, int end, int i){
        if(l>end || start>r)return 0;
        else if(start<=l && end>=r)return tree[i];
        int mid=(l+r)/2;
        return sum(l, mid, start, end, 2*i+1)+sum(mid+1, r, start, end, 2*i+2);
    }
    int sumRange(int left, int right) {
        return sum(0, n-1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */