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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int prest, int prend, int inst, int innd, unordered_map<int, int>& mp){

        if(prest > prend || inst > innd) return nullptr;

        TreeNode* root = new TreeNode(preorder[prest]);

        if(prest == prend) return root;

        int inorder_root = mp[root->val];

        int leftSize = inorder_root - inst;

        root->left = buildTree(preorder, inorder, prest + 1, prest + leftSize, inst, inorder_root - 1, mp);

        root->right = buildTree(preorder, inorder, prest + leftSize + 1, prend, inorder_root + 1, innd, mp);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mp);
    }
};