
+++
authors = ["Yasir"]
title = "Leetcode 49: Group Anagrams"
date = "2024-09-09"
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

{{< highlight html >}}
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

