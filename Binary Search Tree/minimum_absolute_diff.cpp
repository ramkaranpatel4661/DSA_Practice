class Solution {
public:
    void inorder(TreeNode* root, int& prev, int& ans) {
        if (root == nullptr) return;

        inorder(root->left, prev, ans);

        if (prev != INT_MIN) {
            ans = min(ans, abs(root->val - prev));
        }
        prev = root->val;

        inorder(root->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};
