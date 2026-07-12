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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int prest, int prend, int inst, int innd){

        if(prest > prend || inst > innd) return nullptr;

        TreeNode* root = new TreeNode(preorder[prest]);

        if(prest == prend) return root;

        int inorder_root;

        for(inorder_root = inst; inorder_root < innd; inorder_root++){
            if(inorder[inorder_root] == preorder[prest]) break;
        }

        root->left = buildTree(preorder, inorder, prest + 1, prend, inst, inorder_root - 1);

        root->right = buildTree(preorder, inorder, prest + inorder_root - inst + 1, prend, inorder_root + 1, innd);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};