/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a.start < b.end;
        });
        int prevEnd = INT_MIN;

        for(auto& v : intervals)    
        {
            if(prevEnd > v.start)
                return false;

            else
                prevEnd = v.end;
        }
        return true;
    }
};
