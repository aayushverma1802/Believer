/* The functions which
builds the segment tree */
void buildSegementTree(int i, int l, int r, int segmentTree[], int arr[])
{
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    buildSegementTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegementTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}
int *constructST(int arr[], int n)
{
    // Your code here
    int *segmentTree = new int[4 * n];
    buildSegementTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}
int Query(int start, int end, int i, int l, int r, int segmentTree[])
{
    if (l > end or r < start)
    {
        return INT_MAX;
    }
    if (l >= start and r <= end)
    {
        return segmentTree[i];
    }
    int mid = l + (r - l) / 2;
// query acc to code 
    return min(Query(start, end, 2 * i + 1, l, mid, segmentTree), Query(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{

    // Your code here
    return Query(a, b, 0, 0, n - 1, st);
}