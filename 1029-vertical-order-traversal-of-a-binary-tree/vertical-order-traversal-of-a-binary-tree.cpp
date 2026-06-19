/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<tuple<int,int,int>>vec;
    void dfs(int r, int c, TreeNode* root){
        if(root==NULL)return;
        vec.push_back({c,r,root->val});
        dfs(r+1, c-1, root->left);
        dfs(r+1, c+1, root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(0,0,root);
        sort(vec.begin(),vec.end());
        int n=vec.size();
        vector<vector<int>>res;int prev=INT_MIN;vector<int>v;
        for(int i=0;i<n;i++){
            auto [x,y,z]=vec[i];
            if(x!=prev){
                prev=x;
                if(i!=0)res.push_back(v);
                v.clear();
            }
            v.push_back(z);
        }
        res.push_back(v);
        return res;
    }
};