class Solution {
    int result = 0;
public:
    int height(TreeNode* root)
    {
        if (!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        result = max(result, lh + rh); // Diameter at this node
        return 1 + max(lh, rh);         // Height of this node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return result;
    }
};
