
+++
authors = ["Crafted by Me"]
title = "Leetcode 2780: Minimum Index of a Valid Split"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2780: Minimum Index of a Valid Split in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int dom = -1;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(2 * mp[nums[i]] > n) {
                dom = nums[i];
            }
        }
        
        int frq = mp[dom];
        
        int l = 0, r = frq;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == dom) {
                l++;
                r--;
            }
            if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
                return i;
        }
        return -1;
    }
};
{{< /highlight >}}


---
{{< youtube qhvhUTBnYd8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2781: Length of the Longest Valid Substring](https://grid47.xyz/posts/leetcode_2781) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

