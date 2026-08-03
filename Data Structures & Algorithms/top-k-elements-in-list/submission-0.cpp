class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        for (int i : nums)
            numsMap[i]++;
        
        int n = nums.size();                     // ✅ fix here
        vector<vector<int>> temp(n + 1);         // ✅ fix here

        for (auto it : numsMap)
            temp[it.second].push_back(it.first);

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : temp[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};
