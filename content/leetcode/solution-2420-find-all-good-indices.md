
+++
authors = ["grid47"]
title = "Leetcode 2420: Find All Good Indices"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2420: Find All Good Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-good-indices/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp1(n + 1, 1), dp2(n + 1, 1), ans;

        for(int i = 1; i < n; i++)
            if(a[i -1] >= a[i]) dp1[i] = dp1[i - 1]+1;
        for(int i = n -2; i > 0; i--)
            if(a[i] <= a[i +1]) dp2[i] = dp2[i +1]+1;

        for(int i = k; i< n-k; i++)
        if(dp1[i-1] >= k && dp2[i+1] >=k)
        ans.push_back(i);

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2420.md" >}}
---
{{< youtube 3JIMkdeoF1c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2423: Remove Letter To Equalize Frequency](https://grid47.xyz/leetcode/solution-2423-remove-letter-to-equalize-frequency/) |
| --- |
