
+++
authors = ["Crafted by Me"]
title = "Leetcode 845: Longest Mountain in Array"
date = "2022-07-10"
description = "Solution to Leetcode 845"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-mountain-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        
        int n = arr.size();
        
        if(n < 3) return 0;

        vector<int> pre(n, 0), suf(n, 0);
        
        int cur = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i - 1])
                cur++;
            else cur = 0;
            pre[i] = cur;
        }

        cur = 0;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1])
                cur++;
            else cur = 0;
            suf[i] = cur;
        }
        
        for(int i = 0; i < n; i++)
            if(pre[i] > 0 && suf[i] > 0)
        res = max(pre[i] + suf[i] + 1, res);
        
        return res == 1? 0: res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/845.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

