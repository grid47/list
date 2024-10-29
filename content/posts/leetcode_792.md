
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 792: Number of Matching Subsequences"
date = "2022-08-30"
description = "Solution to Leetcode 792"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-matching-subsequences/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> srch(26);

        for(int i = 0; i < s.size(); i++)
            srch[s[i] - 'a'].push_back(i);
        
        int res = 0;
        
        for(string word : words) {
            int x = -1;
            bool found = true;

            for(char c : word) {
                auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
                if(it == srch[c - 'a'].end()) {
                    found = false;
                    break;
                } else x = *it;
            }
            
            if(found) res++;
        }
                
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/792.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

