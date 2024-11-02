
+++
authors = ["Crafted by Me"]
title = "Leetcode 831: Masking Personal Information"
date = "2021-07-24"
description = "Solution to Leetcode 831"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/masking-personal-information/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> country = {"", "+*-", "+**-", "+***-"};
    string maskPII(string s) {
        string res;
        int at = s.find('@');
        if(at != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10]  + "***-***-" + s.substr(s.size() - 4);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/831.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

