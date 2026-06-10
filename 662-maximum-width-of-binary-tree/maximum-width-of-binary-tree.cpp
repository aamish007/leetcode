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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            long long iq=q.front().second;
            long long left,right;
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [it,idx]=q.front();
                q.pop();
                idx-=iq;
                if(i==0)left=idx;
                if(i==s-1)right=idx;
                if(it->left){
                    q.push({it->left,2*idx+1});
                }
                if(it->right){
                    q.push({it->right, 2*idx+2});
                }
            }
            ans=max(ans,right-left+1);
        }
        return (int)ans;
    }
};