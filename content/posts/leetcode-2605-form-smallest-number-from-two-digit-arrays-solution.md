
+++
authors = ["grid47"]
title = "Leetcode 2605: Form Smallest Number From Two Digit Arrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2605: Form Smallest Number From Two Digit Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int num1 = nums1[0];
        set<int> cnt;
        int mn = 10;

        for(int i = 0; i < nums1.size(); i++) {
            cnt.insert(nums1[i]);
            num1 = min(nums1[i], num1);
        }
        
        int num2 = nums2[0];
        for(int i = 0; i < nums2.size(); i++) {
            if(cnt.count(nums2[i])) {
                mn = min(mn, nums2[i]);
            };
            num2 = min(nums2[i], num2);
        }
        if(mn < 10) return mn;
        if(num1 < num2) {
            return num1 * 10 + num2;
        } else {
            return num2 * 10 + num1;            
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2605.md" >}}
---
{{< youtube ZlVNO8BFBCY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2606: Find the Substring With Maximum Cost](https://grid47.xyz/posts/leetcode-2606-find-the-substring-with-maximum-cost-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}