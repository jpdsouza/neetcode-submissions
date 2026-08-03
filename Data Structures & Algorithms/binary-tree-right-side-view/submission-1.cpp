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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> tempResult;

        if(!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp)
                {
                    level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            if(!level.empty())
            {
                tempResult.push_back(level);
            }
        }
        for(vector<int> v : tempResult)
        {
            result.push_back(v[v.size()-1]);
        }
        return result;
    }
};
