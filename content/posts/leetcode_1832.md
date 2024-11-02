
+++
authors = ["Crafted by Me"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2019-10-28"
description = "Solution to Leetcode 1832"
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

