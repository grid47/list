
+++
authors = ["Crafted by Me"]
title = "Leetcode 2860: Happy Students"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2860: Happy Students in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/happy-students/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size();
        int selected = 0;
        if(nums[0]!=0) ans = 1; // Not Selecting AnyOne
        for(int i=0;i<n;i++) {
            selected++;
            if(selected>nums[i]) {  // No. of Selected Students is strictly greater than nums[i].
                if(i+1<n && selected<nums[i+1]) // Considering from (i+1) to n Students is not Selected.
                    ans++; 
                else if(i+1==n) ans++;  // Last Student
            }
        }
        return ans;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2860.md" >}}
---
{{< youtube dDse65NWFt8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2861: Maximum Number of Alloys](https://grid47.xyz/posts/leetcode_2861) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
