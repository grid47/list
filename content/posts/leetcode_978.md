
+++
authors = ["Crafted by Me"]
title = "Leetcode 978: Longest Turbulent Subarray"
date = "2022-02-27"
description = "Solution to Leetcode 978"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-turbulent-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        vector<int> dp(2, 1);
        
        int res = 1, n = arr.size(), prv = 0;

        for(int i = 1; i < n; i++) {

            if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i] ) {
                dp[0] = dp[1] + 1;
                res = max(res, dp[0]);
                prv = 1;
            } else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i] ) {
                dp[1] = dp[0] + 1;
                res = max(res, dp[1]);
                prv = -1;
            }
            else if (arr[i - 1] == arr[i] ) {
                dp[0] = 1;
                dp[1] = 1;
                prv = 0;
            } else {
                dp[0] = 2;
                dp[1] = 2;
                prv = (arr[i - 1] < arr[i]) ? 1 : -1;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/978.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

