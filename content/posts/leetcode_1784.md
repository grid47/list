
+++
authors = ["Crafted by Me"]
title = "Leetcode 1784: Check if Binary String Has at Most One Segment of Ones"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1784: Check if Binary String Has at Most One Segment of Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1785: Minimum Elements to Add to Form a Given Sum](https://grid47.xyz/posts/leetcode_1785) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

