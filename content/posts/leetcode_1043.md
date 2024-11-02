
+++
authors = ["Crafted by Me"]
title = "Leetcode 1043: Partition Array for Maximum Sum"
date = "2020-12-24"
description = "Solution to Leetcode 1043"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-for-maximum-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    vector<int> arr;
    int k;
    int dp(int i) {
        if(i == arr.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int res = 0, mx = 0;
        for(int j = i; j < min((int)arr.size(), i + k); j++) {
            mx = max(mx, arr[j]);
            res = max(res, mx * (j - i + 1) + dp(j + 1));
        }
        return memo[i] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        memo.resize(arr.size(), -1);
        return dp(0);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

