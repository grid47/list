
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1186: Maximum Subarray Sum with One Deletion"
date = "2021-08-02"
description = "Solution to Leetcode 1186"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
        int curr_mx = arr[0], overall_mx = arr[0];
        vector<int> f(n), b(n);
        f[0] = arr[0];
        for(int i = 1; i < n; i++) {
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(curr_mx, overall_mx);
            f[i] = curr_mx;
        }
        
        curr_mx = overall_mx = b[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(overall_mx, curr_mx);
            b[i] = curr_mx;
        }
        
        res = overall_mx;
        for(int i = 1; i < n-1; i++) {
            res = max(res, f[i-1]+b[i+1]);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

