class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // MinHeap storing {distance, point}
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        
        for (auto& point : points) {
            int dist = point[0]*point[0] + point[1]*point[1]; // no sqrt needed
            minHeap.push({dist, point});
        }

        vector<vector<int>> result;
        while (k-- > 0 && !minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};
