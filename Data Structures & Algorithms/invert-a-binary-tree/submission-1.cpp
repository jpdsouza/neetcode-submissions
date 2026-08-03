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
    // vector<int> result;
    void invert(TreeNode* root)
    {
        if(root)
        {
            swap(root->left, root->right);
            invert(root->left);
            invert(root->right);
        }
    }
    // void preorder(TreeNode* root)
    // {
    //     if(root)
    //     {
    //         result.push_back(root->val);
    //         preorder(root->left);
    //         preorder(root->right);
    //     }
    // }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        // preorder(root);
        return root;
    }
};
