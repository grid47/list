
+++
authors = ["Crafted by Me"]
title = "Leetcode 845: Longest Mountain in Array"
date = "2021-07-10"
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

