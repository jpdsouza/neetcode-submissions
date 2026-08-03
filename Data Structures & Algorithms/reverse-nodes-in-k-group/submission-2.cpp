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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> arr;
        ListNode* cur = head;
        while(cur)
        {
            arr.push_back(cur);
            cur = cur->next;
        }
        int left;
        int right;
        int count = arr.size() / k;
        for(int i=0; i<count; i++)
        {
            left = i*k;
            right = (i + 1) * k - 1;
            
            while(left <= right)
            {
                swap(arr[left++]->val, arr[right--]->val);
            }
        }
        return head;
    }
};
