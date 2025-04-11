class Solution {
public:
    bool solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                flag = true;
            } else {
                if (flag) return false; 
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true; 
    }

    bool isCompleteTree(TreeNode* root) {
        return solve(root);
    }
};
    