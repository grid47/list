
+++
authors = ["Yasir"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2020-08-26"
description = "Solution to Leetcode 1525"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
        
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

