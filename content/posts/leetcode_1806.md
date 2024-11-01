
+++
authors = ["Crafted by Me"]
title = "Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation"
date = "2019-11-23"
description = "Solution to Leetcode 1806"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reinitializePermutation(int n) {
        
        vector<int> prem(n, 0), arr(n, 0);
        
        for(int i = 0; i < n; i++) {
            prem[i] = i;
        }
        int cnt = 1;
        while(1) {
        
            for(int i = 0; i < n; i++) {
                arr[i] = (i % 2) ? prem[n/2 + (i - 1)/2] : prem[i/2];
            }
            
            bool x = false;
            for(int i= 0; i < n; i++)
                if(arr[i] != i) x = true;
            
            if(!x) break;
            
            prem = arr;
            cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

