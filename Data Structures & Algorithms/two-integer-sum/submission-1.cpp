class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (numMap.count(complement)) {
                int j = numMap[complement];
                return j < i ? vector<int>{j, i} : vector<int>{i, j};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};
