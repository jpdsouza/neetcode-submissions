class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for(int i=0; i<k; i++)
        {
            if(nums.size() == 1) 
                return;
            int temp;
            for(int j=nums.size()-1; j>0; j--)
                swap(nums[j], nums[j-1]);

        }
    }
};