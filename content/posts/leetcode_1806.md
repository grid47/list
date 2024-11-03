
+++
authors = ["Crafted by Me"]
title = "Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation"
date = "2019-11-23"
description = "In-depth solution and explanation for Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1806.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1807: Evaluate the Bracket Pairs of a String](https://grid47.xyz/posts/leetcode_1807) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

