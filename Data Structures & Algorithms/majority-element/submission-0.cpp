class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numsMap;
        for(int i : nums)
            numsMap[i]++;
        auto temp = numsMap.begin();
        for(auto &it : numsMap)
        {
            if(temp->second < it.second)
                temp=numsMap.find(it.first);
        }
        return temp->first;
    }
};