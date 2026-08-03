class Solution {
public:
    vector<vector<int>> result;
    int n;
    void backtracking(vector<int>& nums, vector<int>& perm, vector<bool>& pick)
    {
        if(perm.size() == n)
        {
            result.push_back(perm);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(pick[i])
                continue;
            if (i > 0 && nums[i] == nums[i-1] && !pick[i-1]) 
                continue;

            perm.push_back(nums[i]);
            pick[i] = true;
            backtracking(nums, perm, pick);
            perm.pop_back();
            pick[i] = false;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> perm;
        vector<bool> pick(n, false);
        backtracking(nums, perm, pick);
        return result;
    }
};