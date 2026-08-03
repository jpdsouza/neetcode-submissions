class Solution {
private:
    int n;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, vector<bool>& pick, vector<int>& perm, int i)
    {
        if(i == n)
        {
            result.push_back(perm);
        }
        else
        {
            for(int j=0; j<n; j++)
            {
                if(!pick[j])
                {
                    pick[j] = true;
                    perm.push_back(nums[j]);
                    backtracking(nums, pick, perm, i+1);
                    pick[j] = false;
                    perm.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n = nums.size();
        vector<bool> pick(n, false);
        vector<int> perm;
        backtracking(nums, pick, perm, 0);
        return result;
    }
};
