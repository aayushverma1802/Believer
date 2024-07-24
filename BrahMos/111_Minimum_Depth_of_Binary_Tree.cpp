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
public:
    int ans(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int l = ans(root->left);
        int r = ans(root->right);
        if (l == 0 && r != 0)
        {
            return 1 + r;
        }
        else if (r == 0 && l != 0)
        {
            return 1 + l;
        }
        return min(l, r) + 1;
    }
    int minDepth(TreeNode *root)
    {
        // This is just the opposite of the max
        // So just use the height code
        // And then use min;
        return ans(root);
    }
};