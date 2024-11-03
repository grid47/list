
+++
authors = ["Crafted by Me"]
title = "Leetcode 1807: Evaluate the Bracket Pairs of a String"
date = "2019-11-22"
description = "In-depth solution and explanation for Leetcode 1807: Evaluate the Bracket Pairs of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1807.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1808: Maximize Number of Nice Divisors](https://grid47.xyz/posts/leetcode_1808) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

