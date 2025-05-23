class Solution {
public:
    int inorder(TreeNode* root, int& k) {
        if (root == nullptr) return -1;

        // Search left subtree
        int left = inorder(root->left, k);
        if (k == 0) return left;

        // Visit current node
        k--;
        if (k == 0) return root->val;

        // Search right subtree
        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};
