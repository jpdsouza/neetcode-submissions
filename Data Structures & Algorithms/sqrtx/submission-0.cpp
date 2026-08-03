class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int result = 0;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;

            if (square > x) {
                right = mid - 1;
            } else if (square < x) {
                result = mid;
                left = mid + 1;
            } else {
                return mid;  // Exact square root found
            }
        }

        return result;  // Return floor of sqrt(x)
    }
};
