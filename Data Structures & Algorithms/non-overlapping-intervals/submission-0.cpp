class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int prevEnd = -1e9;
        int count = 0;

        for(vector<int>& v : intervals)    
        {
            if(prevEnd > v[0])
            {
                count++;
            }
            else
                prevEnd = v[1];
        }
        return count;
    }
};