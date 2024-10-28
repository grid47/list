class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);        
        for(int i = n; i > 1; i--) {
            int k = i - 1;
            for(int j = k - 1; j >= 0; j--)
                arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
            
            nums = arr;
        }
        
        return nums[0];
    }
};