/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            curA = curA->next;
            lenA++;
        }
        while (curB != nullptr) {
            curB = curB->next;
            lenB++;
        }
        curA = headA; curB = headB;
        if (lenA < lenB) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int diff = lenA - lenB;
        while (diff--) {
            curA = curA->next;
        }
        while (curA != nullptr && curB != nullptr) {
            if (curA == curB)
                return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};