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
    vector<int> ans;
    vector<vector<int>> final;

    void dfs(TreeNode *root, int target, int sum)
    {
        if (root == nullptr)
            return;
        sum += root->val;
        ans.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr and sum == target)
        {
            final.push_back(ans);
        }
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        dfs(root, targetSum, 0);
        return final;
    }
};