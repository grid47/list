
+++
authors = ["Yasir"]
title = "Leetcode 118: Pascal's Triangle"
date = "2024-07-03"
description = "Solution to Leetcode 118"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pascals-triangle/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
          vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;      
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

