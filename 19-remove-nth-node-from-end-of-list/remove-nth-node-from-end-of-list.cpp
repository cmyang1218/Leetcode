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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dHead = new ListNode(-1);
        dHead->next = head;
        ListNode *fast = dHead, *slow = dHead;
        for (int i = 0; i <= n && fast != nullptr; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* targ = slow->next;
        slow->next = slow->next->next;
        delete targ;
        head = dHead->next;
        delete dHead;
        return head;
    }
};