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
    struct MetaData {
        bool isBST = true;
        int sum = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
    };

    MetaData findMaxSum(TreeNode* node, int& maxSum) {
        if (!node) return MetaData();

        MetaData left = findMaxSum(node->left, maxSum);
        MetaData right = findMaxSum(node->right, maxSum);

        MetaData curr;
        if (left.isBST && right.isBST &&
            left.mx < node->val && right.mn > node->val) {
            curr.sum = left.sum + right.sum + node->val;
            curr.mn = min(left.mn, node->val);
            curr.mx = max(right.mx, node->val);
            maxSum = max(maxSum, curr.sum);
        } else {
            curr.isBST = false;
        }
        return curr;
    }

public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        findMaxSum(root, maxSum);
        return maxSum;
    }
};