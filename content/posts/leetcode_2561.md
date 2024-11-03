
+++
authors = ["Crafted by Me"]
title = "Leetcode 2561: Rearranging Fruits"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2561: Rearranging Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearranging-fruits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, int> c1;
        
        for(int x: b1) c1[x]++;
        for(int x: b2) c1[x]--;
        
        long long res = 0;
        
        vector<int> swaps;
        for(auto [k1, v1]: c1){
            if(v1 % 2) return -1;

            for(int i = 0; i < abs(v1) / 2; i++)
                swaps.push_back(k1);
        }
        
        int mn = c1.begin()->first;
        
        for(int i = 0; i < swaps.size() / 2; i++)
            res += min(swaps[i], mn * 2);

        return res;
    }
};
{{< /highlight >}}


---
{{< youtube 59weIxEmESg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2562: Find the Array Concatenation Value](https://grid47.xyz/posts/leetcode_2562) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

