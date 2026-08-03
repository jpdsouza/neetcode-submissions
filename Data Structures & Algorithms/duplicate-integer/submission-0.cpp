class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> repeat;
        for(int i : nums)
            repeat[i]++;
        for(int i : nums)
            if(repeat[i] > 1)
                return true;
        return false;
    }
};
