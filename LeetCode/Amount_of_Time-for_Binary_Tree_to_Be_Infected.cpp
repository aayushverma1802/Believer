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
    TreeNode *createMapping(map<TreeNode *, TreeNode *> &nodeToParent, TreeNode *root, int target)
    {
        TreeNode *res = NULL;

        queue<TreeNode *> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front->val == target)
            {
                res = front;
            }

            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }

    int burnTree(TreeNode *root, map<TreeNode *, TreeNode *> &nodeToParent)
    {

        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = 0;

            for (int i = 0; i < size; i++)
            {

                TreeNode *front = q.front();
                q.pop();

                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = 1;
                }

                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = 1;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag = 1;
                }
            }

            if (flag == 1)
            {
                ans++;
            }
        }

        return ans;
    }

    int amountOfTime(TreeNode *root, int target)
    {
        map<TreeNode *, TreeNode *> nodeToParent;

        TreeNode *targetNode = createMapping(nodeToParent, root, target);

        int ans = burnTree(targetNode, nodeToParent);

        return ans;
    }
};