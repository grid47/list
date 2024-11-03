
+++
authors = ["Crafted by Me"]
title = "Leetcode 1035: Uncrossed Lines"
date = "2022-01-02"
description = "In-depth solution and explanation for Leetcode 1035: Uncrossed Lines in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

