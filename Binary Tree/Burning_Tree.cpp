// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{

private:
    Node *createMapping(map<Node *, Node *> &nodeToParent, Node *root, int target)
    {
        Node *res = NULL;

        queue<Node *> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
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

    int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
    {

        map<Node *, bool> visited;
        queue<Node *> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = 0;

            for (int i = 0; i < size; i++)
            {

                Node *front = q.front();
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

public:
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> nodeToParent;

        Node *targetNode = createMapping(nodeToParent, root, target);

        int ans = burnTree(targetNode, nodeToParent);

        return ans;
    }
};