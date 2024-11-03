
+++
authors = ["Crafted by Me"]
title = "Leetcode 820: Short Encoding of Words"
date = "2022-08-05"
description = "In-depth solution and explanation for Leetcode 820: Short Encoding of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/short-encoding-of-words/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        unordered_set<string> s(words.begin(), words.end());
        
        for(string w: words)
        for(int i = 1; i < w.size(); i++)
            s.erase(w.substr(i));

        int res = 0;        
        for(string sk: s)
        res += (sk.size() + 1);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/820.md" >}}
---


"| 821: Shortest Distance to a Character |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

