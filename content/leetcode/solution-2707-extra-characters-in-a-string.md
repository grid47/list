
+++
authors = ["grid47"]
title = "Leetcode 2707: Extra Characters in a String"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2707: Extra Characters in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ONstwO1cD7c"
youtube_upload_date="2023-09-02"
youtube_thumbnail="https://i.ytimg.com/vi/ONstwO1cD7c/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/extra-characters-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<string> dic;
    string str;
    vector<int> memo;
    int n;
    
    int dp(int idx) {
        
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MAX;
        
        int len = 1;
        for(int i = idx; i < n; i++) {
            
            string s = str.substr(idx, len);
            
            if(dic.count(s)) {
                ans = min(ans, dp(idx + len));
            } else {
                ans = min(ans, len + dp(idx + len));                
            }
            
            len++;
        }
        
        return memo[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.size();
        str = s;
        memo.resize(n, -1);
        
        for(auto x: dictionary) {
            dic.insert(x);
        }
        
        return dp(0);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2707.md" >}}
---
{{< youtube ONstwO1cD7c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2708: Maximum Strength of a Group](https://grid47.xyz/leetcode/solution-2708-maximum-strength-of-a-group/) |
| --- |