
+++
authors = ["grid47"]
title = "Leetcode 1784: Check if Binary String Has at Most One Segment of Ones"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1784: Check if Binary String Has at Most One Segment of Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkOnesSegment(string s) {

        // without leading zeros mean starting with 1s
        // if another set of one comes, there be definitely a 01
        // thats all
        return string::npos == s.find("01");
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1784.md" >}}
---
{{< youtube CRjRphrOkNA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1785: Minimum Elements to Add to Form a Given Sum](https://grid47.xyz/posts/leetcode-1785-minimum-elements-to-add-to-form-a-given-sum-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
