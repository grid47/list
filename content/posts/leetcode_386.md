
+++
authors = ["Yasir"]
title = "Leetcode 386: Lexicographical Numbers"
date = "2023-10-08"
description = "Solution to Leetcode 386"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographical-numbers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int num;
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        num = n;
        d(1);
        return ans;
    }
    void d(int x) {
        if(x > num) return;
        ans.push_back(x);
        d(x * 10);
        if((x % 10) < 9) d(x + 1);
    }
};
{{< /highlight >}}

