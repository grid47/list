
+++
authors = ["Yasir"]
title = "Leetcode 1310: XOR Queries of a Subarray"
date = "2021-03-29"
description = "Solution to Leetcode 1310"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

