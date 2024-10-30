
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1300: Sum of Mutated Array Closest to Target"
date = "2021-04-10"
description = "Solution to Leetcode 1300"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        
        int n = A.size(), i = 0;
        while(i < n && target > A[i] * (n - i)) {
            target -= A[i++];
        }
        
        if (i == n) return A[n - 1];
        
        int res = target / (n - i);
        
        if (target - res * (n - i) > (res + 1) * (n - i) - target)
            res++;
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

