
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1807: Evaluate the Bracket Pairs of a String"
date = "2019-11-18"
description = "Solution to Leetcode 1807"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for(auto e: knowledge)
        mp[e[0]] = e[1];
        string res = "";
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(') {
                i++;
                string key = "";
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if(mp.count(key)) {
                    res += mp[key];
                    // mp.erase(key);
                }
                else res += '?';
                i++;
            } else res += s[i++];
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

