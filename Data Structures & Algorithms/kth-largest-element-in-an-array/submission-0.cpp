class Solution {
public:
    priority_queue<int> heap;
    int findKthLargest(vector<int>& nums, int k) {
        for(int num : nums)
            heap.push(num);
        while(k>0 && !heap.empty())
        {
            if(k == 1)
                return heap.top();
            heap.pop();
            k--;
        }
        return 0;
    }
};
