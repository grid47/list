
+++
authors = ["Crafted by Me"]
title = "Leetcode 49: Group Anagrams"
date = "2024-09-14"
description = "Solution to Leetcode 49"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/group-anagrams/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    string code(string x) {
        vector<int> q(26, 0);
        for(int i = 0; i < x.size(); i++) {
            q[x[i] - 'a']++;
        }
        stringstream ss;
        for(int i = 0; i < 26; i++) {
            if(i != 0) ss << ',';
            ss << q[i];
        }
        return ss.str();
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ma;
        for(string x: strs) {
            string mask = code(x);
            ma[mask].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto [key, val]: ma)
            ans.push_back(val);
        
        return ans;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/49.md" >}}
- by gpt
        
---
{{< youtube eDmxPfVa81k >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

