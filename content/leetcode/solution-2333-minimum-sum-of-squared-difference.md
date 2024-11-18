
+++
authors = ["grid47"]
title = "Leetcode 2333: Minimum Sum of Squared Difference"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2333: Minimum Sum of Squared Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wp8lV0aP6aU"
youtube_upload_date="2022-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/wp8lV0aP6aU/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2333.md" >}}
---
{{< youtube wp8lV0aP6aU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2335: Minimum Amount of Time to Fill Cups](https://grid47.xyz/leetcode/solution-2335-minimum-amount-of-time-to-fill-cups/) |
| --- |
