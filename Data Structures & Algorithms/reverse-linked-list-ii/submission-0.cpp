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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> arr;
        ListNode* cur = head;
        while(cur)
        {
            arr.push_back(cur);
            cur = cur->next;
        }
        left = left - 1;
        right = right - 1;
        while(left <= right)
        {
            swap(arr[left++]->val, arr[right--]->val);
        }
        return head;
    }
};