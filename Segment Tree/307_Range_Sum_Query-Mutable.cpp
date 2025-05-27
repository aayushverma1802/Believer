class NumArray
{
public:
    int n;
    vector<int> segmentTree;
    void buildSegmentTree(int i, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            segmentTree[i] = nums[l]; // Correct index
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    void updateSegmentTree(int index, int val, int i, int l, int r)
    {
        int mid = l + (r - l) / 2;
        if (l == r)
        {
            segmentTree[i] = val;
            return;
        }
        if (index <= mid)
        {
            updateSegmentTree(index, val, 2 * i + 1, l, mid);
        }
        else
        {
            updateSegmentTree(index, val, 2 * i + 2, mid + 1, r);
        }
        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }
    int querySegmentTree(int left, int right, int i, int l, int r)
    {
        if (l > right or r < left)
        {
            return 0;
        }
        if (l >= left and r <= right)
        {
            return segmentTree[i];
        }
        int mid = l + (r - l) / 2;
        return querySegmentTree(left, right, 2 * i + 1, l, mid) + querySegmentTree(left, right, 2 * i + 2, mid + 1, r);
    }
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segmentTree.resize(4 * n); // always use 4*n for upper bound
        buildSegmentTree(0, 0, n - 1, nums);
    }

    void update(int index, int val)
    {
        updateSegmentTree(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right)
    {
        return querySegmentTree(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */