class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> result;
        int temp = NULL;
        for(int i=0; i< nums.size(); i++)
        {
            temp = NULL;
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] < nums[j])
                    temp = nums[j];
                if(temp != NULL)
                {
                    result.push_back(j-i);
                    break;
                }
                if(j == nums.size()-1 && temp == NULL)
                    result.push_back(0);
            }
        }
        result.push_back(0);
        return result;
    }
};
