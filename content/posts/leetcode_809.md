
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 809: Expressive Words"
date = "2022-08-14"
description = "Solution to Leetcode 809"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/expressive-words/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for(auto &w : words)
            if(check(s, w))
                res++;
        return res;
    }

    bool check(string s, string w) {
        int n = s.size(), m = w.size(), j = 0;
        for(int i = 0; i < n; i++)
            if(j < m && s[i] == w[j]) j++;
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
            else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
            else return false;
        return j == m;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/809.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

