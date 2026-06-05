class Solution {
    struct node{
        node* next[2];
        node(){
            next[0]=next[1]=nullptr;
        }
    };
    node* root;
public:
    void insert(int j){
        node* curr=root;
        for(int i=31;i>=0;i--){
            int k=(j>>i) & 1;
            if(!curr->next[k])curr->next[k]=new node();
            curr=curr->next[k];
        }
    }
    int maxXor(int x){
        int res=0;node* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(x>>i) & 1;
            if(curr->next[1-bit]){
                res|=1<<i;
                curr=curr->next[1-bit];
            }
            else curr=curr->next[bit];
        }
        return res;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root=new node();vector<tuple<int,int,int>>list;int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<int>res(queries.size());int idx=0;
        for(auto v:queries){
            list.push_back({v[1], v[0], idx});
            idx++;
        }
        sort(list.begin(), list.end());int i=0;
for(auto &[m, x, idx] : list){
    while(i<n && nums[i] <= m){
        insert(nums[i]);
        i++;
    }

    if(i==0) res[idx] = -1;
    else res[idx] = maxXor(x);
}
        return res;
    }
};