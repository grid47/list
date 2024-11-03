
+++
authors = ["Crafted by Me"]
title = "Leetcode 2828: Check if a String Is an Acronym of Words"
date = "2017-02-04"
description = "In-depth solution and explanation for Leetcode 2828: Check if a String Is an Acronym of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        for(string w: words)
            res += w[0];
        return s == res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2829: Determine the Minimum Sum of a k-avoiding Array](https://grid47.xyz/posts/leetcode_2829) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

