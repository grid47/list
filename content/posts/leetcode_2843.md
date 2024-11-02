
+++
authors = ["Crafted by Me"]
title = "Leetcode 2843:   Count Symmetric Integers"
date = "2016-01-20"
description = "Solution to Leetcode 2843"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-symmetric-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; ++i) {
            string s = to_string(i);
            int t = 0, n = s.size();
            for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
            if(n%2 == 0 && t == 0) ans++;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

