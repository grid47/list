
+++
authors = ["Crafted by Me"]
title = "Leetcode 1276: Number of Burgers with No Waste of Ingredients"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1276: Number of Burgers with No Waste of Ingredients in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> ans;
    map<int, map<int, bool>> mp;
    bool dp(int tmt, int chs, int one, int two) {
        if(tmt <= 0 || chs <= 0) {
            if(tmt == 0 && chs == 0) {
                ans = {one, two};
                return true;
            }
            return false;
        }
        
        if(mp.count(tmt) && mp[tmt].count(chs)) return mp[tmt][chs];
        
        if(tmt >= 4 && chs >= 1) {
            if(dp(tmt - 4, chs -1, one + 1, two))
                return mp[tmt][chs] = true;
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;
        } else if(tmt >= 2 && chs >= 1) {
            if(dp(tmt - 2, chs -1, one, two + 1))
                return mp[tmt][chs] = true;            
        }
        return mp[tmt][chs] = false;
    }
    
    vector<int> numOfBurgers(int tmt, int chs) {
        ans = {};
        // dp(tmt, chs, 0, 0);
        int net = chs;
        int jumbo = (tmt - 2 * chs ) / 2;
 
        if(((tmt - 2 * chs ) < 0) || ((tmt - 2 * chs ) % 2) || (net - jumbo < 0)) return ans;
        
        return {jumbo, net - jumbo};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1276.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1277: Count Square Submatrices with All Ones](https://grid47.xyz/posts/leetcode_1277) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
