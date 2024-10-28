class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<long, int> mp;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int a = nums[j--];
            int b = nums[i++];
            long c = a + b;
            mp[c] = 1;
        }
        return mp.size();
    }
};