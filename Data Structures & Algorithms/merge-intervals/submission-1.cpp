class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // Min-heap sort by start time
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_pq;
        for(const vector<int>& v : intervals)
            min_pq.push(v);

        vector<vector<int>> result;
        result.push_back(min_pq.top());
        min_pq.pop();
        
        while(!min_pq.empty())
        {
            vector<int> top = min_pq.top();
            min_pq.pop();

            if(top[0] > result.back()[1]) {
                // No overlap → push as new
                result.push_back(top);
            } else {
                // Merge into last interval
                result.back()[1] = max(result.back()[1], top[1]);
            }
        }
        return result;
    }
};
