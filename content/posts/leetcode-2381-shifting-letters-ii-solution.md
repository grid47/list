
+++
authors = ["grid47"]
title = "Leetcode 2381: Shifting Letters II"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2381: Shifting Letters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n = s.length();
        vector<int> net(n, 0);
        for(auto &x: sh) {
            int k = x[2] == 1? 1 : -1;
            net[x[0]] += k;
           // net[x[0]] %= 26;
            if(x[1] + 1 < n) {
            net[x[1] + 1] -= k;
           // net[x[1] + 1] %= 26;
                }



        }
        
        partial_sum(net.begin(), net.end(), net.begin());
        
        int i = 0;
        for(char &c : s) {
            
            int res = ((c - 'a') + net[i])% 26;
                     res = (res + 26)%26;
            c = 'a' + res;
            i++;
        }
        
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2381.md" >}}
---
{{< youtube dWp_egpuwbU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2383: Minimum Hours of Training to Win a Competition](https://grid47.xyz/posts/leetcode-2383-minimum-hours-of-training-to-win-a-competition-solution/) |
| --- |
