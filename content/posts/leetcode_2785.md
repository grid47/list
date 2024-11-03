
+++
authors = ["Crafted by Me"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2017-03-19"
description = "In-depth solution and explanation for Leetcode 2785: Sort Vowels in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
    }
    string sortVowels(string s) {
        string v;
        copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
            return isVowel(tolower(ch)); 
        });
        sort(begin(v), end(v));
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(tolower(s[i])))
                s[i] = v[j++];
        return s;
    }
};
{{< /highlight >}}


---


"| 2786: Visit Array Positions to Maximize Score |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

