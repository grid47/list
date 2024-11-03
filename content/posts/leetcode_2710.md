
+++
authors = ["Crafted by Me"]
title = "Leetcode 2710: Remove Trailing Zeros From a String"
date = "2017-06-02"
description = "In-depth solution and explanation for Leetcode 2710: Remove Trailing Zeros From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int cnt = 0;
        int len;
        for( len = 1; len <= n; len++) {
            if(num[n - len] == '0') cnt++;
            else break;
        }
        return num.substr(0, n - cnt);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

