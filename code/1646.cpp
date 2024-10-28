class Solution {
    public int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        int max = 1;
        for(int i = 1; 2 * i + 1 < n + 1; i++) {
            nums[2 * i]     = nums[i];
            max = Math.max(nums[2 * i],     max);
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            max = Math.max(nums[2 * i + 1], max);
        }
        return max;
    }
}