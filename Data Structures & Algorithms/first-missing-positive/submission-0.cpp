/*
int firstMissingPositive(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n; ) {
        int correct = arr[i] - 1;
        
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[correct]) {
            swap(arr[i], arr[correct]);
        } else {
            i++;
        }
    }

    // After placement, find the first index where index + 1 != value
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1)
            return i + 1;
    }

    return n + 1; // All numbers from 1 to n are present
}
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n;) {
            // Only place nums[i] if:
            // - it's in the range 1..n
            // - it's not already in the correct position
            // - it's not a duplicate at the target position
            int correct = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        // Find the first location where the index + 1 != value
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};
