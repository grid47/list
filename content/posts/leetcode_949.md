
+++
authors = ["Crafted by Me"]
title = "Leetcode 949: Largest Time for Given Digits"
date = "2021-03-28"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/949.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

