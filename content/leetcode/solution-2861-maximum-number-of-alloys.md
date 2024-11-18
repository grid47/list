
+++
authors = ["grid47"]
title = "Leetcode 2861: Maximum Number of Alloys"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2861: Maximum Number of Alloys in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "0lK_WWukTyA"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-alloys/description/)

---
**Code:**

{{< highlight cpp >}}
using ll = long long;
class Solution {
public:
    bool func(ll mid, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
    {
        ll minCost = INT_MAX;
        for (int i = 0; i < composition.size(); ++i)
        {
            ll currCost = 0;
            for (int j = 0; j < composition[i].size(); ++j)
            {
                ll curr = mid * composition[i][j];
                if (stock[j] >= curr)
                    continue;
                else
                {
                    ll extra = (curr - stock[j]) * cost[j];
                    currCost += extra;
                }
            }
            minCost = min(currCost, minCost);
        }
        return (minCost <= budget);
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll low = 0, high = 1e9, ans = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (func(mid, budget, composition, stock, cost))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2861.md" >}}
---
{{< youtube 0lK_WWukTyA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2864: Maximum Odd Binary Number](https://grid47.xyz/leetcode/solution-2864-maximum-odd-binary-number/) |
| --- |
