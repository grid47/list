
+++
authors = ["grid47"]
title = "Leetcode 1105: Filling Bookcase Shelves"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1105: Filling Bookcase Shelves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/filling-bookcase-shelves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + books[i][1];
            int sum = 0, height = 0;
            for(int j = i; j >= 0; j--) {
                sum += books[j][0];
                if(sum > shelfWidth) break;
                else {
                    height = max(height, books[j][1]);
                    dp[i + 1] = min(dp[j] + height, dp[i+1]);
                }
            }
        }
        return dp[n];        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1105.md" >}}
---
{{< youtube lFYPPPTp8qE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1106: Parsing A Boolean Expression](https://grid47.xyz/posts/leetcode-1106-parsing-a-boolean-expression-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}