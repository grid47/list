
+++
authors = ["grid47"]
title = "Leetcode 2961: Double Modular Exponentiation"
date = "2024-01-15"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2961.md" >}}
---
{{< youtube I0NpbqgISas >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2962: Count Subarrays Where Max Element Appears at Least K Times](https://grid47.xyz/posts/leetcode-2962-count-subarrays-where-max-element-appears-at-least-k-times-solution/) |
| --- |
