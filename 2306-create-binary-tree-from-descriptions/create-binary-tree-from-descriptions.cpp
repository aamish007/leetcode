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
    unordered_map<int,int>l,r;
    void build(TreeNode* root){
        if(l.find(root->val)!=l.end()){
            root->left=new TreeNode(l[root->val]);
            build(root->left);
        }
        if(r.find(root->val)!=r.end()){
            root->right=new TreeNode(r[root->val]);
            build(root->right);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int>use;
        for(auto v:descriptions){
            use.insert(v[1]);
            if(v[2])l[v[0]]=v[1];
            else r[v[0]]=v[1];
        }
        int start=-1;
        for(auto v:descriptions){
            if(!use.count(v[0])){
                start=v[0];
                break;
            }
        }
        TreeNode* root=new TreeNode(start);
        build(root);
        return root;
    }
};