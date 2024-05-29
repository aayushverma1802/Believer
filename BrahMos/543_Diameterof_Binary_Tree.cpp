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
    int dia = 0;
    int ans(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = ans(root->left);
        int r = ans(root->right);
        dia = max(dia, l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int temp = ans(root);
        return dia - 1;
    }
};