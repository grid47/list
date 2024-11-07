
+++
authors = ["Crafted by Me"]
title = "Leetcode 904: Fruit Into Baskets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 904: Fruit Into Baskets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fruit-into-baskets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // longest len of sub arr with at most two elements
        map<int, int> mp;
        int j = 0, res = 0, dst = 0;
        
        for(int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
            if(mp[fruits[i]] == 1) dst++;

            if(dst <= 2) res = max(res, i - j + 1);

            while(dst > 2 && j < i) {
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0) dst--;
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/904.md" >}}
---
{{< youtube GVecnelW8mA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #907: Sum of Subarray Minimums](https://grid47.xyz/posts/leetcode_907) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
