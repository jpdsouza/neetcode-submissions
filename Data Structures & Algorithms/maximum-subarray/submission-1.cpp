class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            sum = max(x, sum + x);   // extend or restart subarray
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
