class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        long res = 0;

        for(int v: nums1)
            res += twoProd((long)v * v, nums2);
        for(int v: nums2)
            res += twoProd((long)v * v, nums1);

        return res;
    }
    
    
    long twoProd(long i, vector<int> &nums) {
        map<long, long> mp;
        
        int cnt = 0;
        for(int n : nums) {
            if(i % n == 0)
                cnt += mp[i / n];
            mp[n]++;
        }
        
        return cnt;
    }
};