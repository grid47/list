
+++
authors = ["grid47"]
title = "Leetcode 1306: Jump Game III"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1306: Jump Game III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;
            int l = i - arr[i];
            int r = i + arr[i];
            arr[i] = -arr[i];
            if (l > -1 && arr[l] > -1) q.push(l);
            if (r < n  && arr[r] > -1) q.push(r);
        }
        
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1306.md" >}}
---
{{< youtube 9oUhzPLmLZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1310: XOR Queries of a Subarray](https://grid47.xyz/posts/leetcode-1310-xor-queries-of-a-subarray-solution/) |
| --- |
