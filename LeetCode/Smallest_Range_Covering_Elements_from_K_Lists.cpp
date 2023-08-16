class Node
{
public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node *, vector<Node *>, compare> minHeap;
        int k = nums.size();
        for (int i = 0; i < k; i++)
        {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0));
        }
        int start = mini;
        int end = maxi;
        while (!minHeap.empty())
        {
            Node *temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;
            if (maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }
            if (temp->col + 1 < nums[temp->row].size())
            {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minHeap.push(new Node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};