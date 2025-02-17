class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(nullptr) {};
    };

    ListNode* dHead;
    int size = 0;

    MyLinkedList() {
        dHead = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index > size-1 || index < 0)
            return -1;
        ListNode* curr = dHead->next;
        while(index--) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dHead->next;
        dHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curr = dHead;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0)
            return;
        if (index == size) {
            addAtTail(val);
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* curr = dHead;
        while (index--) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) 
            return;
        ListNode* curr = dHead;
        while (index--) {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        tmp = nullptr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */