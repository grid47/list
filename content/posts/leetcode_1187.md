
+++
authors = ["Crafted by Me"]
title = "Leetcode 1187: Make Array Strictly Increasing"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1187: Make Array Strictly Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-array-strictly-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> arr1;
    vector<int> arr;
    int memo[2001][2001][2];
    int dp(int i, int j, bool master) {

        if(i >= arr1.size()) return 0;

        int prv = master? ((i == 0)? INT_MIN: arr1[i - 1]): arr[j];        
        j = upper_bound(arr.begin() + j, arr.end(), prv) - arr.begin();        
        if(memo[i][j][master] != -1) return memo[i][j][master];

        int ans = 2001;
        if(j < arr.size()) ans = dp(i + 1, j, false) + 1;

        if(prv < arr1[i]) ans = min(ans, dp(i + 1, j, true));

        return memo[i][j][master] = ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr) {

        sort(arr.begin(), arr.end());
        this->arr1 = arr1;
        this->arr = arr;

        memset(memo, -1, sizeof(memo));

        int ans= dp(0, 0, true);
        return ans >= 2001? -1: ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1187.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1188: Design Bounded Blocking Queue](https://grid47.xyz/posts/leetcode_1188) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

