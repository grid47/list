
+++
authors = ["grid47"]
title = "Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2829: Determine the Minimum Sum of a k-avoiding Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "EimziJ7mVdE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        vector<int> vis(51, 0);
        int i = 1;
        while(n > 0 && i <= k) {
            if(!vis[i] && !vis[k - i]) {
                n--;                
                sum += i;
                vis[i] = true;
            }
            i++;
        }
        while(n--) {
            sum += i++;
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2829.md" >}}
---
{{< youtube EimziJ7mVdE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2830: Maximize the Profit as the Salesman](https://grid47.xyz/leetcode/solution-2830-maximize-the-profit-as-the-salesman/) |
| --- |
