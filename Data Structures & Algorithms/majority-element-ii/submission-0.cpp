class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i : nums)
            freq[i]++;
        for(auto &it : freq)
        {
            if(it.second > n/3)
                result.push_back(it.first);
        }
        return result;
    }
};