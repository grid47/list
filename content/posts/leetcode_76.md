
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 76: Minimum Window Substring"
date = "2024-08-15"
description = "Solution to Leetcode 76"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-window-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for(char x: t) mp[x]++;

        int cnt = t.size();
        int lo, len = s.size() + 1;
        
        int i = 0;
        
        for(int j = 0; j < s.size(); j++) {
            
            if(mp.count(s[j])) {
                mp[s[j]]--;
                if(mp[s[j]] >= 0) cnt--;
            }
            
            while(cnt == 0 && i <= j) {
                if(len > j - i + 1) {
                    lo = i;
                    len = j - i + 1;
                }
                if(mp.count(s[i])) {
                    mp[s[i]]++;
                    if(mp[s[i]] >= 1) cnt++;
                }
                i++;                
            }
        }

        return len == (s.size() + 1)? "" : s.substr(lo, len);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/76.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
