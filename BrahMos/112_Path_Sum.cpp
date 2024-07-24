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
    int solve(TreeNode *root, int curr, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }
        curr += root->val;
        if (root->left == nullptr and root->right == nullptr)
        {
            return targetSum == curr;
        }
        bool l = solve(root->left, curr, targetSum);
        bool r = solve(root->right, curr, targetSum);

        return l or r;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int curr = 0;
        return solve(root, curr, targetSum);
    }
};