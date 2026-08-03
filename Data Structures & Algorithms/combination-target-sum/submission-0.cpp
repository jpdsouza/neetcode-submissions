class Solution {
public:
    vector<vector<int>> result;
    int n;
    void backtracking(vector<int>& nums, vector<int>& set, int i, const int& target, int sum)
    {
        if(sum == target)
        {
            result.push_back(set);
            return;
        }
        if(i == n || sum > target)
            return;
        else
        {
            set.push_back(nums[i]);
            // sum += nums[i];
            backtracking(nums, set, i, target, sum + nums[i]);

            // sum -= nums[i];
            set.pop_back();
            backtracking(nums, set, i+1, target, sum);

        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> set;
        n = nums.size();
        int sum = 0;
        backtracking(nums, set, 0, target, sum);
        return result;
    }
};
