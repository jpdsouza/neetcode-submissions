class Solution {
public:
    void merge(vector<int>& nums, int start, int end, int mid) {
        int i = start;
        int j = mid + 1;
        vector<int> temp;

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= end)
            temp.push_back(nums[j++]);

        // Copy back to nums
        for (int k = 0; k < temp.size(); k++) {
            nums[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, end, mid);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);  // ✅ fixed
        return nums;
    }
};
