class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums)
        {
            heap.push(i);
            if(heap.size() > k)
                heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > k)
            heap.pop();
        return heap.top();
    }
};
