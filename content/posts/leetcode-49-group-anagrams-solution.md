
+++
authors = ["grid47"]
title = "Leetcode 49: Group Anagrams"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 49: Group Anagrams in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/group-anagrams/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/49.webp" 
    alt="A series of floating words forming gentle clusters, swirling around each other."
    caption="Solution to LeetCode 49: Group Anagrams Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube eDmxPfVa81k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #50: Pow(x, n)](https://grid47.xyz/posts/leetcode-50-powx-n-solution/) |
| --- |
