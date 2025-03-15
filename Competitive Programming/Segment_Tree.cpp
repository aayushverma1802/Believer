#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // Segment tree requires ~4*n space
        build(0, 0, n - 1, arr);
    }

    // 🔹 Build Segment Tree (Recursive)
    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start]; // Leaf node
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);  // Left child
            build(2 * node + 2, mid + 1, end, arr); // Right child
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Parent stores sum
        }
    }

    // 🔹 Query Sum in Range [L, R]
    int query(int L, int R) {
        return queryUtil(0, 0, n - 1, L, R);
    }

    int queryUtil(int node, int start, int end, int L, int R) {
        if (L > end || R < start) return 0; // No overlap
        if (L <= start && end <= R) return tree[node]; // Complete overlap

        int mid = (start + end) / 2;
        int leftSum = queryUtil(2 * node + 1, start, mid, L, R);
        int rightSum = queryUtil(2 * node + 2, mid + 1, end, L, R);
        return leftSum + rightSum; // Partial Overlap
    }

    // 🔹 Point Update at Index idx
    void update(int idx, int val) {
        updateUtil(0, 0, n - 1, idx, val);
    }

    void updateUtil(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val; // Update leaf node
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                updateUtil(2 * node + 1, start, mid, idx, val);
            else
                updateUtil(2 * node + 2, mid + 1, end, idx, val);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // Update parent node
        }
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; 
    SegmentTree segTree(arr);

    cout << "Sum of range [1,4]: " << segTree.query(1, 4) << endl; // Output: 24
    segTree.update(2, 10); // Update index 2 (5 → 10)
    cout << "Sum of range [1,4] after update: " << segTree.query(1, 4) << endl; // Output: 29

    return 0;
}
