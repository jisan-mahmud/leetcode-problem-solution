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
private:

    int result = -1;

    void find(TreeNode* root, int& k){
        if(root == nullptr || result != -1) return;

        find(root->left, k);

        if(--k == 0) {
            result = root->val;
            return;
        };

        find(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);

        return result;
    }
};