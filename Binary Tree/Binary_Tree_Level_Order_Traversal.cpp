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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        queue<TreeNode *> q;
        vector<vector<int>> v;
        vector<int> j;
        q.push(root);
        while (q.empty() == false)
        {
            int n1 = q.size();
            j.clear();
            while (n1 != 0)
            {
                TreeNode *n = q.front();
                q.pop();
                j.push_back(n->val);

                if (n->left)
                {

                    q.push(n->left);
                }
                if (n->right)
                {
                    q.push(n->right);
                }
                n1--;
            }
            v.push_back(j);
        }
        return v;
    }
};