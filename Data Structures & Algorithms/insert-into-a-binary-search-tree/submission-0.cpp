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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // TreeNode result(val);
        TreeNode* node = new TreeNode(val);
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        if(!root)
            return node;
        while(cur)
        {
            prev = cur;
            if(cur->val < val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        if(val > prev->val)
            prev->right = node;
        else
            prev->left = node;
        return root;
    }
};