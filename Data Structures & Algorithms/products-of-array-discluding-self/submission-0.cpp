class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        int n = nums.size();

        int leftToRight[n];
        int rightToLeft[n];

        leftToRight[0] = 1;
        rightToLeft[n-1] = 1;

        for(int i=1; i<n; i++)
            leftToRight[i] = leftToRight[i-1] * nums[i-1];

        for(int i=n-2; i> -1; i--)
            rightToLeft[i] = rightToLeft[i+1] * nums[i+1];

        for(int i=0; i<n; i++)
            result.push_back(leftToRight[i] * rightToLeft[i]);

        return result;
    }
};
