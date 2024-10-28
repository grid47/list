
+++
authors = ["Yasir"]
title = "Leetcode 2111: Minimum Operations to Make the Array K-Increasing"
date = "2019-01-18"
description = "Solution to Leetcode 2111"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), longest = 0;
        for(int i = 0; i < k; i++) {
            vector<int> lis;
            for(int j = i; j < n; j += k) {
                if(lis.empty() || lis.back() <= arr[j])
                    lis.push_back(arr[j]);
                else *upper_bound(lis.begin(), lis.end(), arr[j]) = arr[j];
            }
            longest += lis.size();
        }
        return n - longest;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

