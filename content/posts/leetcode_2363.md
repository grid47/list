
+++
authors = ["Crafted by Me"]
title = "Leetcode 2363: Merge Similar Items"
date = "2024-11-01"
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


---
{{< youtube KjqRqf4KZxE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2364: Count Number of Bad Pairs](https://grid47.xyz/posts/leetcode_2364) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

