
+++
authors = ["Crafted by Me"]
title = "Leetcode 1854: Maximum Population Year"
date = "2019-10-06"
description = "In-depth solution and explanation for Leetcode 1854: Maximum Population Year in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-population-year/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> sum(102, 0);
        
        for(auto v: logs) {
            sum[v[1] - 1950]--;
            sum[v[0] - 1950]++;
        }
        
        for(int i = 1; i < 102; i++) {
            sum[i] += sum[i - 1];
            cout << sum[i] << " ";
        }
        
        int mx = 0, yr = 2050;
        for(int i = 101; i >= 0; i--) {
            if(sum[i] >= mx) {
                yr = i + 1950;
                mx = sum[i];
            }
        }
        return yr;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1855: Maximum Distance Between a Pair of Values](https://grid47.xyz/posts/leetcode_1855) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

