
+++
authors = ["Crafted by Me"]
title = "Leetcode 1572: Matrix Diagonal Sum"
date = "2020-07-14"
description = "In-depth solution and explanation for Leetcode 1572: Matrix Diagonal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/matrix-diagonal-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += mat[i][i] + mat[n - 1 - i][i];
        if(n % 2) sum -= mat[n/2][n/2];
        return sum;
    }
};
{{< /highlight >}}


---
{{< youtube 5TLlr3y3Iww >}}

"| 1573: Number of Ways to Split a String |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

