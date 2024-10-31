
+++
authors = ["Crafted by Me"]
title = "Leetcode 1187: Make Array Strictly Increasing"
date = "2021-08-02"
description = "Solution to Leetcode 1187"
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

