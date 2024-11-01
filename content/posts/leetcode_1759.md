
+++
authors = ["Crafted by Me"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2020-01-09"
description = "Solution to Leetcode 1759"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHomogenous(string s) {
        long long j = 0, cnt = 0, n = s.size();
        int mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[j] == s[i]) continue;
            else {
                long long len = i - j;
                cnt += len * (len + 1) / 2;
                j = i;                
            }
        }
        long long len = n - j;
        cnt += len * (len + 1) / 2; 
        return cnt % mod;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

