
+++
authors = ["Crafted by Me"]
title = "Leetcode 386: Lexicographical Numbers"
date = "2023-10-13"
description = "In-depth solution and explanation for Leetcode 386: Lexicographical Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/386.md" >}}
---
{{< youtube n4YGTbFfU-w >}}
| Next : [LeetCode #387: First Unique Character in a String](https://grid47.xyz/posts/leetcode_387) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

