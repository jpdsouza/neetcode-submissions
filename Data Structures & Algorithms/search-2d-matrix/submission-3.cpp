class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector v : matrix)
        {
            if(v[0] <= target && target <= v[v.size()-1])
            {
                int start = 0;
                int end = v.size()-1;
                int mid;
                while(start <= end)
                {
                    mid = start + (end-start)/2;
                    if(v[mid] == target)
                        return true;
                    if(v[mid] > target)
                        end = mid-1;
                    else
                        start = mid+1;
                }
                return false;
            }
        }
        return false;
    }
};
