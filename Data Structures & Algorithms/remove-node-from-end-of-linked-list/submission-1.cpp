class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode* cur = head;

        while (cur) {
            arr.push_back(cur);
            cur = cur->next;
        }

        int index = arr.size() - n;

        // Case 1: only one node
        if (arr.size() == 1) return nullptr;

        // Case 2: removing head
        if (index == 0) return head->next;

        // Case 3: removing middle or last node
        arr[index - 1]->next = (index + 1 < arr.size()) ? arr[index + 1] : nullptr;

        return head;
    }
};
