
+++
authors = ["grid47"]
title = "Leetcode 1936: Add Minimum Number of Rungs"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1936: Add Minimum Number of Rungs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f_KA5C_13Oc"
youtube_upload_date="2021-07-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/f_KA5C_13Oc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/add-minimum-number-of-rungs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int rec(int cur, int idx, int dist, vector<int> &node) {
        if(cur + dist >= node[node.size() - 1]) return 0;
        
        if(cur + dist < node[idx]) {
            cur += dist;
            return 1 + rec(cur, idx, dist, node);
            
        } else {
            cur = node[idx];
            return rec(cur, idx + 1, dist, node);
        }
    }
    
    int addRungs(vector<int>& node, int dist) {
        int cur = 0, idx = 0, res = 0;
        
        int prv = 0;
        
        for(int i = 0; i < node.size(); i++) {
            if(node[i] - prv > dist) {
                res += (node[i] - prv - 1) / dist;
            }
            prv = node[i];
        }
        
        // while(cur + dist < node[node.size() - 1]) {
        //     if(cur + dist < node[idx]) {
        //         cur += dist;
        //         res++;
        //     } else {
        //         cur = node[idx];
        //         idx++;
        //     }
        // }
        
        return res;//rec(cur, idx, dist, node);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1936.md" >}}
---
{{< youtube f_KA5C_13Oc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1937: Maximum Number of Points with Cost](https://grid47.xyz/leetcode/solution-1937-maximum-number-of-points-with-cost/) |
| --- |