/**
 * Definition for a binary tree n.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return nullptr;
        }
        vector<int> level;
        queue<TreeNode *> q;
        q.push(root);
        while (q.empty() == false)
        {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                int num = n->val;
                sum += num;
                q.pop();
                if (n->left != nullptr)
                {
                    q.push(n->left);
                }
                if (n->right != nullptr)
                {
                    q.push(n->right);
                }
            }
            level.push_back(sum);
        }
        int k = 1;
        q.push(root);
        root->val = 0; // This is done because root has no cosuins ;
        while (q.empty() == false)
        {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();

                q.pop();
                // int sib = n->left != NULL ? n->left->val : 0;
                // sib += n->right != NULL ? n->right->val : 0;
                int sib = (n->left != NULL ? n->left->val : 0) + (n->right != NULL ? n->right->val : 0);

                if (n->left != nullptr)
                {
                    n->left->val = level[k] - sib;
                    q.push(n->left);
                }
                if (n->right != nullptr)
                {
                    n->right->val = level[k] - sib;
                    q.push(n->right);
                }
            }
            k++;
        }
        return root;
    }
};