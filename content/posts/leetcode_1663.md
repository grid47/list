
+++
authors = ["Crafted by Me"]
title = "Leetcode 1663: Smallest String With A Given Numeric Value"
date = "2020-04-13"
description = "Solution to Leetcode 1663"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        while(k > 0) {
            ans[--n] += min(25, k);
            k -= min(25, k);
        }
        return ans;
    }
};
{{< /highlight >}}



---

{{< youtube o3MRJfsoUrw >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

