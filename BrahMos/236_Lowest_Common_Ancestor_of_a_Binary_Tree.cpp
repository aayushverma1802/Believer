/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL or root == p or root == q)
        {
            return root;
        }
        TreeNode *t1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *t2 = lowestCommonAncestor(root->right, p, q);
        if (t1 == NULL)
        {
            return t2;
        }
        else if (t2 == NULL)
        {
            return t1;
        }
        else
        {
            return root;
        }
    }
};