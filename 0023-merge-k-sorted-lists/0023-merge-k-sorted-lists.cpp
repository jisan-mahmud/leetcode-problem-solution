/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

private:

    ListNode* merge2Lists(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                cur->next = left;
                cur = left;
                left = left->next;
            }else{
                cur->next = right;
                cur = right;
                right = right->next;
            }
        }

        cur->next = (left == nullptr) ? right : left;

        return dummy->next;
    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];

        if(start + 1 == end) return merge2Lists(lists[start], lists[end]);

        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);

        return merge2Lists(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }

        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
};