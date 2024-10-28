
+++
authors = ["Yasir"]
title = "Leetcode 820: Short Encoding of Words"
date = "2022-08-01"
description = "Solution to Leetcode 820"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

