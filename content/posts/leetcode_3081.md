
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3081: Replace Question Marks in String to Minimize Its Value"
date = "2016-05-24"
description = "Solution to Leetcode 3081"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> frq(26, 0), taken;

        int n = s.size();
        for(char c: s) if(c != '?') frq[c - 'a']++;

        for(int i = 0; i < n; i++) {
            if(s[i] != '?') continue;

            int mn = 0;
            for(int j = 0; j < 26; j++)
                if(frq[j] < frq[mn]) mn = j;

            taken.push_back(mn);
            frq[mn]++;
        }

        sort(taken.begin(), taken.end());

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?')
            s[i] = taken[idx++] + 'a';
        }

        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
