class Solution {
public:
    int n;
    int length;

    bool backtracking(vector<int>& matchsticks, vector<int>& bucket, int start) {
        if (start == n) {
            // Check if all 4 sides equal length
            return bucket[0] == length && bucket[1] == length &&
                   bucket[2] == length && bucket[3] == length;
        }

        for (int i = 0; i < 4; i++) {
            if (bucket[i] + matchsticks[start] > length) continue;

            bucket[i] += matchsticks[start];
            if (backtracking(matchsticks, bucket, start + 1)) return true;
            bucket[i] -= matchsticks[start]; // backtrack
            
            if (bucket[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;

        length = total / 4;
        n = matchsticks.size();

        sort(matchsticks.rbegin(), matchsticks.rend()); // descending

        vector<int> bucket(4, 0);
        return backtracking(matchsticks, bucket, 0);
    }
};
