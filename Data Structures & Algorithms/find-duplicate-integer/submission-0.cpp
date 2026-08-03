class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result;
        for(int i=0; i<nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
            {
                result = abs(nums[i]);
                break;
            }
            else
            {
                nums[index] *= -1;
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = abs(nums[i]);
        }
        return result;
    }
};
