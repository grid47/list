
+++
authors = ["Yasir"]
title = "Leetcode 1807: Evaluate the Bracket Pairs of a String"
date = "2019-11-17"
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

{{< highlight html >}}
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

