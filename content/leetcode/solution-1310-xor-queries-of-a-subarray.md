
+++
authors = ["grid47"]
title = "Leetcode 1310: XOR Queries of a Subarray"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1310: XOR Queries of a Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "1Q4lxfSlbPs"
img_src = ""
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
{{< youtube 1Q4lxfSlbPs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1311: Get Watched Videos by Your Friends](https://grid47.xyz/leetcode/solution-1311-get-watched-videos-by-your-friends/) |
| --- |
