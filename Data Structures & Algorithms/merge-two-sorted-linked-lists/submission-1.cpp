class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode result;               // dummy node
        ListNode* node = &result;      // pointer to build the new list

        while (t1 && t2) {
            if (t1->val < t2->val) {
                node->next = t1;
                t1 = t1->next;
            } else {
                node->next = t2;
                t2 = t2->next;
            }
            node = node->next;
        }

        // Attach remaining nodes
        if (t1)
            node->next = t1;
        if (t2)
            node->next = t2;

        return result.next;  // skip dummy node
    }
};
