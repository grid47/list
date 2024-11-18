
+++
authors = ["grid47"]
title = "Leetcode 1942: The Number of the Smallest Unoccupied Chair"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1942: The Number of the Smallest Unoccupied Chair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "LqhxcaCctCc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t) {
        int tt = a[t][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserve;
        priority_queue<int, vector<int>, greater<int>> avail;
        sort(a.begin(), a.end());
        for(auto &t : a) {
            
            while(!reserve.empty() && reserve.top().first <= t[0]) {
                
                avail.push(reserve.top().second);
                reserve.pop();
                
            }
            
            if(t[0] == tt) break;
            if (!avail.empty()) {
                
                reserve.push({t[1], avail.top()});
                             
               avail.pop();
                
            } else {
                
                reserve.push({t[1], reserve.size()});
                
            }
            
        }
        
        return avail.empty()? reserve.size() : avail.top();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1942.md" >}}
---
{{< youtube LqhxcaCctCc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1943: Describe the Painting](https://grid47.xyz/leetcode/solution-1943-describe-the-painting/) |
| --- |
