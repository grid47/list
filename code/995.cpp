class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flipped = 0, res = 0;
        vector<int> hasFlipped(n, 0);
        vector<int> tmp = nums;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) flipped ^= hasFlipped[i - k];
            if (flipped == nums[i]) {
                if (i + k > nums.size()) return -1;
                flipped ^= 1;
                hasFlipped[i] = 1;
                res++;
            }
        }
        return res;
    }
};