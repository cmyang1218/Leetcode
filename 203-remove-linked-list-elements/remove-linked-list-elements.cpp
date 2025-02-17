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
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dHead = new ListNode();
        dHead->next = head;
        ListNode* curr = dHead;
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }else {
                curr = curr->next;
            }
        }
        return dHead->next;
    }
};