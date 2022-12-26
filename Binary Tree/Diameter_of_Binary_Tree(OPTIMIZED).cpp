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
class Solution {
public:
int ans=0;
int height(TreeNode *root){
   if(root==NULL){
            return 0; 
        }
        int left_Subtree=height(root->left);
        int right_Subtree=height(root->right);
        ans=max(ans,left_Subtree+right_Subtree+1);
        return max(left_Subtree,right_Subtree)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int data=height(root);
        return ans-1;
    }
};