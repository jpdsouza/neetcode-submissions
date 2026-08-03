class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int i : nums)
            numSet.insert(i);
        int sequence = 0;
        for(int i : numSet)
        {
            int count = 1;
            if(!numSet.count(i-1))
            {
                while(numSet.count(i+count))
                    count++;
            }
            if(count>sequence) 
                sequence = count;
        }
        return sequence;
    }
};
