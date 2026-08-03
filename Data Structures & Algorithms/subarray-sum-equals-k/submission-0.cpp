class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> PSFreq;
        int count = 0;
        int sum = 0;

        PSFreq[0] = 1; // to count subarrays starting from index 0

        for (int num : nums) {
            sum += num;
            int diff = sum - k;

            // If a prefix sum existed such that sum - prefix = k
            if (PSFreq.count(diff))
                count += PSFreq[diff];

            // Add current prefix sum to the map
            PSFreq[sum]++;
        }

        return count;
    }
};
