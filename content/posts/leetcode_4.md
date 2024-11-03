
+++
authors = ["Crafted by Me"]
title = "Leetcode 4: Median of Two Sorted Arrays"
date = "2024-10-29"
description = "In-depth solution and explanation for Leetcode 4: Median of Two Sorted Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> A = (m < n)? nums1 : nums2;
        vector<int> B = (m < n)? nums2 : nums1;
        m = (nums1.size() < nums2.size())? nums1.size() : nums2.size();
        n = (nums1.size() < nums2.size())? nums2.size() : nums1.size();

        int imin = 0, imax = m, i, j;

        while(imin <= imax)
        {
            i = ((imin + imax) / 2);
            j = ((m + n + 1)/ 2) - i;

                 if((i < m) && (B[j - 1] > A[i]))
                    imin = i + 1;
            else if((i > 0) && (A[i - 1] > B[j]))
                    imax = i - 1;
            else
            {
                int lmax;
                     if(i == 0) lmax = B[j - 1];
                else if(j == 0) lmax = A[i - 1];
                else            lmax = max(A[i - 1], B[j - 1]);

                if(((m + n) % 2) == 1) return lmax;

                int rmin;
                     if(i == m) rmin = B[j];
                else if(j == n) rmin = A[i];
                else            rmin = min(A[i], B[j]);

                return (double)(lmax + rmin) / 2;
            }
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/4.md" >}}
---
{{< youtube q6IEA26hvXc >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

