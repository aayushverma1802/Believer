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
class Solution
{
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    void solve(TreeNode *root, vector<int> &vec, int &i)
    {
        if (!root)
        {
            return;
        }
        solve(root->left, vec, i);
        if (root->val != vec[i])
        {
            root->val = vec[i];
        }
        i++;
        solve(root->right, vec, i);
    }

public:
    void recoverTree(TreeNode *root)
    {
        vector<int> vec;
        inorder(root, vec);
        sort(vec.begin(), vec.end());
        int i = 0;
        solve(root, vec, i);
    }
};