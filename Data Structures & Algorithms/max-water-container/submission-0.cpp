class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int max = 0;
        int area;
        while(left < right)
        {
            area = (right - left) * min(heights[left], heights[right]);
            if(area > max)
                max = area;
            if(heights[left] > heights[right])
                right--;
            else
                left++;
        }
        return max;
    }
};
