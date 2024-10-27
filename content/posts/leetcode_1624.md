
+++
authors = ["Yasir"]
title = "Leetcode 1624: Largest Substring Between Two Equal Characters"
date = "2020-05-18"
description = "Solution to Leetcode 1624"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mp.count(s[i])) {
                ans = max(ans, i - mp[s[i]] - 1);
            }
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

