
+++
authors = ["grid47"]
title = "Leetcode 2363: Merge Similar Items"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2363: Merge Similar Items in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Ordered Set"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-similar-items/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        map<int,int> m;
        for(int i=0;i<items1.size();i++)
        {
            m[items1[i][0]]=items1[i][1];
        }
        for(int i=0;i<items2.size();i++)
        {
            if(m.find(items2[i][0])!=m.end())
            {
                m[items2[i][0]]+=items2[i][1];
            }
            else
            {
                m[items2[i][0]]=items2[i][1];
            }
        }
        vector<vector<int>> ans;
        for(auto it : m)
        {
            ans.push_back({it.first,it.second});
        }
        return ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2363.md" >}}
---
{{< youtube KjqRqf4KZxE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2364: Count Number of Bad Pairs](https://grid47.xyz/leetcode/solution-2364-count-number-of-bad-pairs/) |
| --- |
