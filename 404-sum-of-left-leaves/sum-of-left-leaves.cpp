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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        TreeNode* l=root->left;
        if(l){
            if(!l->left && !l->right)ans+=l->val;
            else ans=sumOfLeftLeaves(l);
        }
        if(root->right)ans+=sumOfLeftLeaves(root->right);
        return ans;
    }
};