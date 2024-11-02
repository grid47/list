
+++
authors = ["Crafted by Me"]
title = "Leetcode 2063: Vowels of All Substrings"
date = "2019-03-11"
description = "Solution to Leetcode 2063"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/vowels-of-all-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countVowels(string word) {
        long long res = 0, n = word.size();
        for(int i = 0; i < n; i++)
        if(string("aeiou").find(word[i]) != string::npos)
        res += (i + 1) * (n - i);
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

