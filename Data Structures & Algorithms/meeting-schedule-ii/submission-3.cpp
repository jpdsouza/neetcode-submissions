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
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;
        int count = 0;
        int maxCount = 0;

        for(auto& it : intervals)
        {
            start.push(it.start);
            end.push(it.end);
        }
        while(!start.empty() && !end.empty())
        {
            if(start.top() < end.top())
            {
                count++;
                start.pop();
            }
            else
            {
                count--;
                end.pop();
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
