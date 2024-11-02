
+++
authors = ["Crafted by Me"]
title = "Leetcode 1433: Check If a String Can Break Another String"
date = "2019-11-30"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

