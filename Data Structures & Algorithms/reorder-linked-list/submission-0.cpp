class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        vector<ListNode*> arr;        
        ListNode* cur = head;

        while (cur) {
            arr.push_back(cur);
            cur = cur->next;
        }

        ListNode result;
        ListNode* node = &result;
        int left = 0, right = arr.size() - 1;
        bool turn = true;

        while (left <= right) {
            if (turn) {
                node->next = arr[left++];
            } else {
                node->next = arr[right--];
            }
            node = node->next;
            turn = !turn;
        }

        node->next = nullptr;
    }
};
