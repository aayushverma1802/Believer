vector<int> topView(Node *root)
{
    // Your code here
    queue<pair<Node *, int>> q;
    map<int, int> topnode;
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    q.push({Node, 0});
    while (q.empty() == false)
    {
        pair<Node *, int> temp = q.fornt();
        int frontNode = q.first;
        int hd = q.second;
        if (topnode.find(hd) == topnode.end())
        {
            topnode[hd] = frontnode->data;
        }
        q.pop();
        if (topnode->left)
        {
            q.push({topnode->left, -1});
        }
        if (topnode->right)
        {
            q.push({topnode->right, +1});
        }
    }
    for (i : topnode)
    {
        ans.push_back(i);
    }
    return ans;
}