
+++
authors = ["grid47"]
title = "Leetcode 1642: Furthest Building You Can Reach"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1642: Furthest Building You Can Reach in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zyTeznvXCtg"
youtube_upload_date="2024-02-17"
youtube_thumbnail="https://i.ytimg.com/vi/zyTeznvXCtg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/furthest-building-you-can-reach/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int furthestBuilding(vector<int>& h, int bri, int lad) {
        int n = h.size();
        vector<int> bc(n - 1, 0);
        
        for(int i = 0; i < n - 1; i++) {
            bc[i] = h[i + 1] - h[i] < 0 ? 0: h[i + 1] - h[i];
            // cout << bc[i] << " ";
        }
 
        // cout << "\n";
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, sum = 0;
        for(; i < n - 1; i++) {

            if(bc[i] == 0) continue;
            
            if(pq.size() < lad) {
                pq.push(bc[i]);
            } else {
                pq.push(bc[i]);
                if(sum + pq.top() <= bri)
                sum += pq.top();
                else return i;
                pq.pop();
            }
            
        }
        // cout << sum << " " << bri << " " << i;
        return n - 1;
        // Use ladders first
        // when ladders are over
        // check are them could be replaced with bricks
        // if yes, continue to assigning released ladder
        // else return where it had overflown
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1642.md" >}}
---
{{< youtube zyTeznvXCtg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1646: Get Maximum in Generated Array](https://grid47.xyz/leetcode/solution-1646-get-maximum-in-generated-array/) |
| --- |
