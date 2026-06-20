class Solution {
public:
    int cnt = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;

        int left = kthSmallest(root->left, k);
        if (left != -1) return left;

        cnt++;
        if (cnt == k) return root->val;

        return kthSmallest(root->right, k);
    }
};