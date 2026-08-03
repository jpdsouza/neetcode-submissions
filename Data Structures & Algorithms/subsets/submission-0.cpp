class Solution {
private:
    int n;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, vector<int>& comb, int i)
    {
        if(i == n)
            result.push_back(comb);
        else
        {
            comb.push_back(nums[i]);
            backtracking(nums, comb, i+1);
            comb.pop_back();
            backtracking(nums, comb, i+1);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> comb;
        n = nums.size();
        backtracking(nums, comb, 0);
        return result;
    }
};
