
+++
authors = ["Crafted by Me"]
title = "Leetcode 1310: XOR Queries of a Subarray"
date = "2021-04-02"
description = "In-depth solution and explanation for Leetcode 1310: XOR Queries of a Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/xor-queries-of-a-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> xr(n +1,0);
        for(int i = 1; i < n +1; i++)
            xr[i] = xr[i - 1] ^ arr[i - 1];
        vector<int> res;
        for(int i = 0; i < q.size(); i++) {
            auto &v = q[i];
            res.push_back(xr[v[1]+1] ^ xr[v[0]]);
         }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1310.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1311: Get Watched Videos by Your Friends](https://grid47.xyz/posts/leetcode_1311) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

