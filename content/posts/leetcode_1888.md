
+++
authors = ["Crafted by Me"]
title = "Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating"
date = "2019-09-02"
description = "In-depth solution and explanation for Leetcode 1888: Minimum Number of Flips to Make the Binary String Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---
{{< youtube MOeuK6gaC2A >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

