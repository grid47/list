class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
        for(int num: nums1) cnt1 += num == 0, sum1 += num;
        for(int num: nums2) cnt2 += num == 0, sum2 += num;

        if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
            cnt2 == 0 && cnt1 + sum1 > sum2)
                return -1;

        return max(sum1 + cnt1, sum2 + cnt2);

    }
};