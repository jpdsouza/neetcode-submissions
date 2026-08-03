//Boyer–Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(int i : nums)
        {
            if(count == 0)
                candidate = i;
            count += (i == candidate? 1 : -1);
        }
        return candidate;
    }
};