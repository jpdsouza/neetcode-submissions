class Solution {
public:
    vector<vector<int>> result;
    int n;
    void backtracking(vector<int>& nums, vector<int>& set, int i)
    {
        if(i == n)
        {
            result.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        backtracking(nums, set, i+1);

        set.pop_back();
        while(i+1 < n && nums[i] == nums[i+1])
            i++;
        backtracking(nums, set, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> set;
        backtracking(nums, set, 0);
        return result;
    }
};
