
+++
authors = ["grid47"]
title = "Leetcode 1962: Remove Stones to Minimize the Total"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1962: Remove Stones to Minimize the Total in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "lLAvgl2voc4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < piles.size(); i++)
            pq.push(piles[i]);
        
        while(k--) {
            int top = pq.top();
            top = top - floor(top/2);
            pq.pop();
            if(top > 0)
            pq.push(top);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1962.md" >}}
---
{{< youtube lLAvgl2voc4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1963: Minimum Number of Swaps to Make the String Balanced](https://grid47.xyz/leetcode/solution-1963-minimum-number-of-swaps-to-make-the-string-balanced/) |
| --- |
