
+++
authors = ["Yasir"]
title = "Leetcode 2575: Find the Divisibility Array of a String"
date = "2017-10-10"
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

{{< highlight html >}}
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

