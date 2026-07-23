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
    class MetaData{
        public:
            bool isBST;
            int sum;
            int mn;
            int mx;

            MetaData(){
                isBST = true;
                sum = 0;
                mn = INT_MAX;
                mx = INT_MIN;
            }

    };

    MetaData* findMaxSum(TreeNode* currNode, int& maxSum){
        if(currNode == nullptr){
            return new MetaData();
        }

        MetaData* left = findMaxSum(currNode->left, maxSum);
        MetaData* right = findMaxSum(currNode->right, maxSum);

        if(left->isBST && right->isBST && left->mx < currNode->val && right->mn > currNode->val){
            MetaData* currNodeMetaData = new MetaData();
            currNodeMetaData->sum = left->sum + right->sum + currNode->val;
            currNodeMetaData->mn = min(left->mn, currNode->val);
            currNodeMetaData->mx = max(right->mx, currNode->val);

            maxSum = max(maxSum, currNodeMetaData->sum);
            return currNodeMetaData;
        }

        MetaData* currNodeMetaData = new MetaData();
        currNodeMetaData->isBST = false;
        return currNodeMetaData;
    }

public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        findMaxSum(root, maxSum);
        return maxSum;
    }
};