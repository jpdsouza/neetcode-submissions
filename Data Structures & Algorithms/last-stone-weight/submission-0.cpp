class Solution {
public:
    priority_queue<int> heap;
    int lastStoneWeight(vector<int>& stones) 
    {
        for(int stone : stones)
            heap.push(stone);
        while(heap.size() > 1 && !heap.empty())
        {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            if(stone1 == stone2)
                continue;
            else
                heap.push(abs(stone1 - stone2));
        }
        return heap.empty() ? 0 : heap.top();
    }
};
