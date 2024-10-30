
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1717: Maximum Score From Removing Substrings"
date = "2020-02-18"
description = "Solution to Leetcode 1717"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if(y > x) {
            swap(a, b);
            swap(x, y);
        }
        
        auto s1 = greedy(s, a, b), s2 = greedy(s1,  b, a);
        
        return ((s.size() - s1.size()) / 2) * x + ((s1.size() - s2.size()) / 2) * y;
    }
    string greedy(string s, char a, char b) {
        
        string st;
        
        for(char c : s) {
            if(!st.empty() && st.back() == a && c == b)
                st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

