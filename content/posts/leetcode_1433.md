
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1433: Check If a String Can Break Another String"
date = "2020-11-28"
description = "Solution to Leetcode 1433"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-can-break-another-string/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.size();
        string a = s1 < s2 ? s2: s1;
        string b = s1 < s2 ? s1: s2;   
        // cout << a << "\n"<< b;
        for(int i = 0; i < n; i++) {
            if(a[i] < b[i]) return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

