
+++
authors = ["grid47"]
title = "Leetcode 1433: Check If a String Can Break Another String"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1433: Check If a String Can Break Another String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1433.md" >}}
---
{{< youtube H8_hAPOW5UE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1434: Number of Ways to Wear Different Hats to Each Other](https://grid47.xyz/posts/leetcode-1434-number-of-ways-to-wear-different-hats-to-each-other-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
