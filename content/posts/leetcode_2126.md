
+++
authors = ["Crafted by Me"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2126: Destroying Asteroids in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destroying-asteroids/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        int n = ast.size();
        long long mss = mass;
        for(int i = 0;i < n; i++) {
            if(mss >= ast[i])
                mss += ast[i];
            else return false;
        }
        return true;
    }
};
{{< /highlight >}}


---
{{< youtube e9FIRRXjKJI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2127: Maximum Employees to Be Invited to a Meeting](https://grid47.xyz/posts/leetcode_2127) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

