
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1838: Frequency of the Most Frequent Element"
date = "2019-10-19"
description = "Solution to Leetcode 1838"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxFrequency(vector<int>& A, int t) {
        int i = 0, j;
        long k = t;
        sort(A.begin(), A.end());
        for (j = 0; j < A.size(); ++j) {
            k += A[j];
            if (k < (long)A[j] * (j - i + 1))
                k -= A[i++];
        }
        return j - i;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

