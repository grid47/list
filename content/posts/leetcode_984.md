
+++
authors = ["Crafted by Me"]
title = "Leetcode 984: String Without AAA or BBB"
date = "2022-02-22"
description = "In-depth solution and explanation for Leetcode 984: String Without AAA or BBB in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-without-aaa-or-bbb/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if(B > A) return strWithout3a3b(B, A, b, a);
        while(A-- > 0) {
            res += a;
            if(A > B) res += a, A--;
            if(B-->0) res += b;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/984.md" >}}
---

| Next : [LeetCode #985: Sum of Even Numbers After Queries](https://grid47.xyz/posts/leetcode_985) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

