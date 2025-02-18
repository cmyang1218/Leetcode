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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dHead = new ListNode(-1);
        dHead->next = head;
        ListNode* curr = dHead;
        while (curr->next != nullptr && curr->next->next != nullptr) {
            ListNode* tmp = curr->next;
            ListNode* tmp1 = curr->next->next->next;
            curr->next = tmp->next;
            curr->next->next = tmp;
            tmp->next = tmp1;

            curr = curr->next->next;
        }
        ListNode* res = dHead->next;
        delete dHead;
        return res;
    }
};