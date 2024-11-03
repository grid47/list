
+++
authors = ["Crafted by Me"]
title = "Leetcode 1557: Minimum Number of Vertices to Reach All Nodes"
date = "2020-07-29"
description = "In-depth solution and explanation for Leetcode 1557: Minimum Number of Vertices to Reach All Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ca(n, 0);
        vector<int> ans;
        for(auto e: edges) {
            ca[e[1]]++;
        }
        for(int i = 0; i< n ; i++)
        if(ca[i] == 0) ans.push_back(i);
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube oEy0bzfioG4 >}}

"| 1558: Minimum Numbers of Function Calls to Make Target Array |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

