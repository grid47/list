
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2384: Largest Palindromic Number"
date = "2018-04-22"
description = "Solution to Leetcode 2384"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-palindromic-number/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {}, mid = -1;
        string s;

        for(char c: num) cnt[c - '0']++;

        for(int i = 9; i > 0; i--) {
            if(cnt[i] == 0) continue;
            s.append(cnt[i]/2, i + '0');
            if(mid == -1 && (cnt[i]&1))
                    mid = i;
        }

        if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
        mid = mid == -1 && (cnt[0] & 1)? 0: mid;
        if(mid != -1) s.push_back(mid + '0');
        s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());

        return s != ""? s : "0";
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

