
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating"
date = "2019-08-29"
description = "Solution to Leetcode 1888"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1 = "", s2 = "";
        for(int i = 0; i < s.size(); i++) {
            s1 += i % 2? '0': '1';
            s2 += i % 2? '1': '0';
        }
        
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for(int i = 0; i < s.size(); i++) {
            if(s1[i] != s[i]) ans1++;
            if(s2[i] != s[i]) ans2++;
            if(i >= n) {
                if(s1[i - n] != s[i - n]) ans1--;
                if(s2[i - n] != s[i - n]) ans2--;
            }
            if(i >= n - 1)
                ans = min({ans1, ans2, ans});
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

