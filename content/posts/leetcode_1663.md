
+++
authors = ["Crafted by Me"]
title = "Leetcode 1663: Smallest String With A Given Numeric Value"
date = "2020-04-14"
description = "In-depth solution and explanation for Leetcode 1663: Smallest String With A Given Numeric Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

"| 1664: Ways to Make a Fair Array |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

