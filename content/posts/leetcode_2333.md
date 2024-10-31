
+++
authors = ["Crafted by Me"]
title = "Leetcode 2333: Minimum Sum of Squared Difference"
date = "2018-06-13"
description = "Solution to Leetcode 2333"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-squared-difference/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<long long> diff(n, 0);
        for(int i = 0; i < n; i++)
        diff[i] = abs(nums1[i] - nums2[i]);

        long long m = *max_element(diff.begin(), diff.end());
        int k = k1 + k2;

        vector<long long> bck(m + 1, 0);
        for(int i = 0; i < n; i++)
            bck[diff[i]]++;

        for(int i = m; i > 0; i--)
            if (bck[i] > 0) {
                long long num     = min(bck[i], (long long) k);
                bck[i]     -= num;
                bck[i - 1] += num;
                k -= num;
                if (k == 0) break;
            }

        long long res = 0;
        for(long long i = 0; i < m + 1; i++)
         res += bck[i] * (i * i);

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

