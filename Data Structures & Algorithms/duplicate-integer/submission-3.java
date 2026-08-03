class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        
        for (int i = 0; i < nums.length; i++) {
            if (!numSet.add(nums[i])){
                return true;
            }
        }
        return false;
    }

}