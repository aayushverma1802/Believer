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
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        vector<int> arr;
        inOrder(root, arr);
        TreeNode *temp = new TreeNode(arr[0]);
        TreeNode *head = temp;
        for (int i = 1; i < arr.size(); i++)
        {
            TreeNode *n = new TreeNode(arr[i]);
            head->right = n;
            head->left = NULL;
            head = head->right;
        }
        return temp;
    }
};