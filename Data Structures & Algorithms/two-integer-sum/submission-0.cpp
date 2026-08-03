class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;  // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                // Return the pair with smaller index first
                int j = numMap[complement];
                return j < i ? vector<int>{j, i} : vector<int>{i, j};
            }

            // Add current number to map
            numMap[nums[i]] = i;
        }

        // As per problem statement, one solution always exists
        return {};
    }
};
