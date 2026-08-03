class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int cur = heights[i];
            int left = i - 1;
            int right = i + 1;
            int count = 1;

            // Expand left
            while (left >= 0 && heights[left] >= cur) {
                count++;
                left--;
            }

            // Expand right
            while (right < heights.size() && heights[right] >= cur) {
                count++;
                right++;
            }

            maxArea = std::max(maxArea, cur * count);
        }

        return maxArea;
    }
};
