class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sgn = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                sgn = 0;
                break;
            } else if(nums[i] > 0) {
                
            } else if(nums[i] < 0) {
                sgn *= -1;
            }
        }
        return sgn;
    }
};