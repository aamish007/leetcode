class Solution {
    struct node{
        bool isEnd;
        node* next[26];
        node(){
            isEnd=false;
            for(int i=0;i<26;i++)next[i]=nullptr;
        }
    };
    node* root;
public:
    void insert(string word){
        node* curr=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!curr->next[idx])curr->next[idx]=new node();
            curr=curr->next[idx];
        }
        curr->isEnd=true;
        return;
    }
    bool check(string s){
        node* curr=root;
        for(char ch:s){
            int idx=ch-'a';
            if(!curr->next[idx])return false;
            curr=curr->next[idx];
            if(!curr->isEnd)return false;
        }
        return true;
    }
    string longestWord(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        root=new node();
        int large=0;string s="";
        for(string str:nums)insert(str);
        for(string str:nums){
            if(str.size()>large){
                if(check(str)){
                    s=str;
                    large=str.size();
                }
            }
        }
        return s;
    }
};