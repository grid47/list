
+++
authors = ["Crafted by Me"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2019-10-28"
description = "In-depth solution and explanation for Leetcode 1832: Check if the Sentence Is Pangram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkIfPangram(string set) {
        bitset<26> bit;
        for(char x: set) bit.set(x - 'a');
        return bit.count() == 26;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1833: Maximum Ice Cream Bars](https://grid47.xyz/posts/leetcode_1833) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

