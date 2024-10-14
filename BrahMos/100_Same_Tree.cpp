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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL and q == NULL)
        {
            return true;
        }
        if (p == NULL and q != NULL)
        {
            return false;
        }
        if (p != NULL and q == NULL)
        {
            return false;
        }
        bool j = isSameTree(p->left, q->left);
        bool k = isSameTree(p->right, q->right);
        if (k == true and j == true and p->val == q->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
