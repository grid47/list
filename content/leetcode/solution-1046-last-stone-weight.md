
+++
authors = ["grid47"]
title = "Leetcode 1046: Last Stone Weight"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1046: Last Stone Weight in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "bmcFr1AdiJg"
youtube_upload_date="2023-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/bmcFr1AdiJg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/last-stone-weight/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for(int x: stones) {
            pq.push(x);
        }
        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if(pq.empty()) return x;
            
            int y = pq.top();
             pq.pop();
             if(y == x) {}
             else {
                    pq.push(abs(y-x));
             }            
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1046.md" >}}
---
{{< youtube bmcFr1AdiJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1048: Longest String Chain](https://grid47.xyz/leetcode/solution-1048-longest-string-chain/) |
| --- |
