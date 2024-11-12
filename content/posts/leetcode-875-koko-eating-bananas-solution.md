
+++
authors = ["grid47"]
title = "Leetcode 875: Koko Eating Bananas"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 875: Koko Eating Bananas in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/koko-eating-bananas/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 0, r = 1000000000;
        while(l <= r) {
            int k = l + (r - l) / 2;
            double h = 0;
            for(int x: piles)
                h += ceil((double) x / k);
            
            if(h > H)   l = k + 1;
            else        r = k - 1;
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/875.md" >}}
---
{{< youtube ceYZ5RgwQwQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #876: Middle of the Linked List](https://grid47.xyz/posts/leetcode-876-middle-of-the-linked-list-solution/) |
| --- |
