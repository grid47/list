
+++
authors = ["grid47"]
title = "Leetcode 1535: Find the Winner of an Array Game"
date = "2024-06-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1535: Find the Winner of an Array Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-winner-of-an-array-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        int cnt = 0;
        int j = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] < arr[j]) {
                cnt++;
            } else {
                cnt = 1;
                j = i;
            }
            if(cnt == k) return arr[j];            
        }
        return arr[j];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1535.md" >}}
---
{{< youtube v6On1TQfMTU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1536: Minimum Swaps to Arrange a Binary Grid](https://grid47.xyz/posts/leetcode-1536-minimum-swaps-to-arrange-a-binary-grid-solution/) |
| --- |
