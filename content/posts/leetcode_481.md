
+++
authors = ["Crafted by Me"]
title = "Leetcode 481: Magical String"
date = "2023-07-10"
description = "In-depth solution and explanation for Leetcode 481: Magical String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/magical-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.size() < n)
        s += string(s[i++] - '0', s.back() ^ 3);
        return count(s.begin(), s.begin() + n, '1');
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/481.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #482: License Key Formatting](https://grid47.xyz/posts/leetcode_482) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

