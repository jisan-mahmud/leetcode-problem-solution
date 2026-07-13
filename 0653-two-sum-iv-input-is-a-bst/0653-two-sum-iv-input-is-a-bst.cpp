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
    bool found = false;
    unordered_set<int> st;

    void find(TreeNode* root, int k){

        if(root == nullptr) return;

        if(st.count(k - root->val)){
            found = true;
            return;
        }

        st.insert(root->val);

        find(root->left, k);
        find(root->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        find(root, k);
        return found;
    }
};