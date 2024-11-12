
+++
authors = ["grid47"]
title = "Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy","Sliding Window"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1888.md" >}}
---
{{< youtube MOeuK6gaC2A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1893: Check if All the Integers in a Range Are Covered](https://grid47.xyz/posts/leetcode-1893-check-if-all-the-integers-in-a-range-are-covered-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
