
+++
authors = ["Yasir"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2019-10-23"
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

{{< highlight html >}}
class Solution {
public:
    bool checkIfPangram(string set) {
        bitset<26> bit;
        for(char x: set) bit.set(x - 'a');
        return bit.count() == 26;
    }
};
{{< /highlight >}}

