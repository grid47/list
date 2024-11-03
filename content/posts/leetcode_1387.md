
+++
authors = ["Crafted by Me"]
title = "Leetcode 1387: Sort Integers by The Power Value"
date = "2021-01-15"
description = "In-depth solution and explanation for Leetcode 1387: Sort Integers by The Power Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-power-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, int> memo;
    
    int dig(int num) {
        if(num == 1) return 0;
        if(memo.count(num)) return memo[num];
        if(num % 2 == 0)
            return memo[num] = dig(num / 2) + 1;
        return memo[num] = dig(3 * num + 1) + 1;        
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        for(int i = lo; i <= hi; i++) {
            int tmp = dig(i);
            ans.push_back({tmp, i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1].second;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1387.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1388: Pizza With 3n Slices](https://grid47.xyz/posts/leetcode_1388) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

