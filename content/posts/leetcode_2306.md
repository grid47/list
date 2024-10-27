
+++
authors = ["Yasir"]
title = "Leetcode 2306: Naming a Company"
date = "2018-07-06"
description = "Solution to Leetcode 2306"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/naming-a-company/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> count[26];
        for (auto& s: ideas)
            count[s[0] - 'a'].insert(s.substr(1));
        long long res = 0;
        for(int i = 0; i < 26; ++i)
            for(int j = i + 1; j < 26; ++j) {   
                long long c1 = 0L, c2 = 0L;
                for (auto& c: count[i])
                    if (!count[j].count(c)) c1++;
                for (auto& c: count[j])
                    if (!count[i].count(c)) c2++;
                res += c1 * c2;
            }
        return res * 2;
    }
};
{{< /highlight >}}

