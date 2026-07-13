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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(seen.count(k - node->val)) return true;

            seen.insert(node->val);

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        return false;
    }
};