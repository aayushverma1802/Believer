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
    void inOrder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        vector<int> arr;
        inOrder(root, arr);

        int ans = 0, i = 0;
        cout << arr.size();
        while (i < arr.size())
        {
            if (arr[i] >= low and arr[i] <= high)
            {
                ans += arr[i];
            }
            i++;
        }
        return ans;
    }
};