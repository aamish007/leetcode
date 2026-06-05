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
    int maxXor(int i){
        int res=0;node* curr=root;
        for(int j=31;j>=0;j--){
            int bit=1 & (i>>j);
            if(curr->next[1-bit]){
                res|=(1<<j);
                curr=curr->next[1-bit];
            }
            else curr=curr->next[bit];
        }
        return res;
    }
    int findMaximumXOR(vector<int>& nums) {
        root=new node();
        for(int i: nums){
            insert(i);
        }
        int ans=INT_MIN;
        for(int i:nums){
            ans=max(ans,maxXor(i));
        }
        return ans;
    }
};