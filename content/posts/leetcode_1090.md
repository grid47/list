
+++
authors = ["Crafted by Me"]
title = "Leetcode 1090: Largest Values From Labels"
date = "2021-11-08"
description = "In-depth solution and explanation for Leetcode 1090: Largest Values From Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-values-from-labels/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multimap<int, int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < values.size(); i++) 
            s.insert({values[i], labels[i]});
        int res = 0;
        for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
            if(++m[it->second] <= useLimit) {
                res += it->first;
                --numWanted;                
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1090.md" >}}
---
{{< youtube E0OkE3G95vU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1091: Shortest Path in Binary Matrix](https://grid47.xyz/posts/leetcode_1091) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

