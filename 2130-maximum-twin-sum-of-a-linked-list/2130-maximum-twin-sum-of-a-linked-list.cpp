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
    vector<int> sum;
public:
    int pairSum(ListNode* head) {
        

        ListNode* currentNode = head;
        ListNode* prevNode = nullptr;
        
        while(head != nullptr){
            sum.push_back(head->val);
            head = head->next;

            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = head;
        }

        int i = 0;

        while(prevNode != nullptr){
            sum[i] += prevNode->val;
            prevNode = prevNode->next;
            i++;
        }

        return *max_element(sum.begin(), sum.end());
    }
};