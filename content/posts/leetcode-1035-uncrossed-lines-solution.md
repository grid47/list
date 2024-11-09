
+++
authors = ["grid47"]
title = "Leetcode 1035: Uncrossed Lines"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1035: Uncrossed Lines in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/uncrossed-lines/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<int> nums1, nums2;
    vector<vector<int>> memo;

    int dp(int i, int j) {
        if(i == m || j == n) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = INT_MIN;
        if(nums1[i] == nums2[j]) {
            ans = 1 + dp(i + 1, j + 1);
            return ans;
        }
        ans = max(dp(i + 1, j), dp(i, j + 1));
        return memo[i][j] = ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums1.size(), n = nums2.size();
        memo.resize(m+1, vector<int>(n+1, -1));
        
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1035.md" >}}
---
{{< youtube TFBZKlASq3g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1038: Binary Search Tree to Greater Sum Tree](https://grid47.xyz/posts/leetcode-1038-binary-search-tree-to-greater-sum-tree-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
