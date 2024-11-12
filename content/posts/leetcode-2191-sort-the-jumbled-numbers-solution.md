
+++
authors = ["grid47"]
title = "Leetcode 2191: Sort the Jumbled Numbers"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2191: Sort the Jumbled Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-jumbled-numbers/description/)

---
**Code:**

{{< highlight cpp >}}
#include <string.h>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> tmp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int num = nums[i];
            
            string str = to_string(num);
            string formed = "";
            for(int j = 0; j < str.size(); j++)
                formed += to_string(mapping[str[j]- '0']);
            int val = stoi(formed);
            tmp.push_back({ val, i });
            
        }
        
        sort(tmp.begin(), tmp.end());
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            ans.push_back(nums[tmp[i].second]);
        
        return ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2191.md" >}}
---
{{< youtube rmkF2mxPoZM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2192: All Ancestors of a Node in a Directed Acyclic Graph](https://grid47.xyz/posts/leetcode-2192-all-ancestors-of-a-node-in-a-directed-acyclic-graph-solution/) |
| --- |
