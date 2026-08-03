class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        for(char task : tasks)
            freqMap[task]++;
        
        // Max heap of frequencies
        priority_queue<int> maxHeap;
        for(auto& it : freqMap)
            maxHeap.push(it.second);
        
        // Queue to simulate cooldown: pair<remaining freq, available time>
        queue<pair<int, int>> cooldown;
        int time = 0;
        
        while(!maxHeap.empty() || !cooldown.empty()) {
            time++;
            
            // Add task back to heap if cooldown is over
            if(!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }

            if(!maxHeap.empty()) {
                int freq = maxHeap.top(); maxHeap.pop();
                freq--;
                if(freq > 0) {
                    cooldown.push({freq, time + n + 1});  // Cooldown till time+n
                }
            }
        }
        
        return time;
    }
};
