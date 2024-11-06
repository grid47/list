
+++
authors = ["Crafted by Me"]
title = "Leetcode 2961: Double Modular Exponentiation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2961: Double Modular Exponentiation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/double-modular-exponentiation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int power(long long b, long long p, int m){
    if(p <= 0) return 1;
    long long t = power(b, p/2, m);
    t = ((t * t)%m);
    return (p%2)?(t * b)%m : t;
}

vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
    vector<int> ans;
    for(int i = 0; i < v.size(); ++i){
        long long a = v[i][0]%10, b = v[i][1], c = v[i][2], m = v[i][3], t = 1;
        t = power(a, b, 10);
        t = power(t, c, m);
        if(t == target) ans.push_back(i);
    }
    return ans;
}
};
{{< /highlight >}}


---
{{< youtube I0NpbqgISas >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2962: Count Subarrays Where Max Element Appears at Least K Times](https://grid47.xyz/posts/leetcode_2962) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
