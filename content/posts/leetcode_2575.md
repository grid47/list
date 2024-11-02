
+++
authors = ["Crafted by Me"]
title = "Leetcode 2575: Find the Divisibility Array of a String"
date = "2017-10-15"
description = "Solution to Leetcode 2575"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n, 0);
        long num = 0;
        for(int i = 0; i < n; i++) {
            num = num * 10 + (word[i] - '0');
            num %= m;
            if(num % m == 0) ans[i] = 1;
            else ans[i] = 0;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

