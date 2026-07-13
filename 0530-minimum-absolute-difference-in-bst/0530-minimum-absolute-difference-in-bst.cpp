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
    int minimum = INT_MAX;
    TreeNode* prev = nullptr;

    void minimumDiff(TreeNode* root){
        if(root == nullptr) return;

        minimumDiff(root->left);

        if(prev != nullptr)
            minimum = min(minimum, abs(prev->val - root->val));
        
        prev = root;


        minimumDiff(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        minimumDiff(root);
        return minimum;
    }
};