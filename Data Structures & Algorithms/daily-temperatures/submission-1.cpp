//Stack implementation
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> st;
        vector<int> result(nums.size(), 0); // initialize with 0s

        for (int i = 0; i < nums.size(); i++) {

            while (!st.empty() && nums[i] > nums[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex; 
            }
            st.push(i); 
        }

        return result;
    }
};
