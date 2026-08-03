class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return true;

        // Sort by start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        // Check for overlap
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false; // overlap found
            }
        }
        return true; // no overlaps
    }
};
