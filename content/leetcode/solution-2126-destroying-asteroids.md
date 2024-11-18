
+++
authors = ["grid47"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2126: Destroying Asteroids in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2126.md" >}}
---
{{< youtube e9FIRRXjKJI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2129: Capitalize the Title](https://grid47.xyz/leetcode/solution-2129-capitalize-the-title/) |
| --- |
