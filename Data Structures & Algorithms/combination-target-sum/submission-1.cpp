class Solution {
private:
    int n;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, vector<int>& comb, const int& target, int i, int sum)
    {
        if(sum == target)
            result.push_back(comb);
        else
        {
            if(i == n || sum > target)
                return;

            comb.push_back(nums[i]);
            backtracking(nums, comb, target, i, sum + nums[i]);
            comb.pop_back();
            backtracking(nums, comb, target, i+1, sum);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        n = nums.size();
        vector<int> comb;
        backtracking(nums, comb, target, 0, 0);
        return result;
    }
};
