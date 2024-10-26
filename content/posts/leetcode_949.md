
+++
authors = ["Yasir"]
title = "Leetcode 949: Largest Time for Given Digits"
date = "2022-03-23"
description = "Solution to Leetcode 949"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-time-for-given-digits/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A), greater<int>());
        do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        while(prev_permutation(begin(A), end(A)));
            
        return "";
    }
};
{{< /highlight >}}

