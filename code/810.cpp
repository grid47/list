class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int net = 0;
        for(int x: nums)
            net ^= x;
        return net == 0 || nums.size() % 2 == 0;
    }
};