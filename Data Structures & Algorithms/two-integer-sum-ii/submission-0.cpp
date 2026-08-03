class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        int sum;
        vector<int> result;
        while(left < right)
        {
            sum = numbers[left] + numbers[right];
            if(sum > target)
                right--;
            else if(sum == target)
            {
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            else
                left++;
        }
        return result;
    }
};
