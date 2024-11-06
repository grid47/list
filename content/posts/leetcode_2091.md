
+++
authors = ["Crafted by Me"]
title = "Leetcode 2091: Removing Minimum and Maximum From Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2091: Removing Minimum and Maximum From Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int xi = 0, ni = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[xi] < nums[i])
                xi = i;
            if(nums[ni] > nums[i])
                ni = i;
        }
        if(xi == ni) return 1;
        int mx = (xi < ni)? ni: xi;
        int mn = (xi < ni)? xi: ni;

        int ans = (mx - 0 + 1);
        
        ans = min(ans, (n - mn));
        
        ans = min(ans, (n - mx) + (mn - 0 + 1));
                
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube OsaRrf_jDn4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2092: Find All People With Secret](https://grid47.xyz/posts/leetcode_2092) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

