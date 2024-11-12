
+++
authors = ["grid47"]
title = "Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& comp) {
        int n = comp.size();
        
        for(auto &c : comp)
            sort(c.begin(), c.end());
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int notSubset = true;
            
            for(int j = 0; j < n && notSubset; j++) {
                if(i == j) continue;
                
                notSubset = !includes(comp[j].begin(), comp[j].end(), comp[i].begin(), comp[i].end());
            }
            if(notSubset)
                res.push_back(i);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1452.md" >}}
---
{{< youtube Ok0jYAMnvQI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1456: Maximum Number of Vowels in a Substring of Given Length](https://grid47.xyz/posts/leetcode-1456-maximum-number-of-vowels-in-a-substring-of-given-length-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
