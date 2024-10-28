
+++
authors = ["Yasir"]
title = "Leetcode 831: Masking Personal Information"
date = "2022-07-21"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

