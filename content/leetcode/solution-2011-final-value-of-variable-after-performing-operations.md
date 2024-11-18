
+++
authors = ["grid47"]
title = "Leetcode 2011: Final Value of Variable After Performing Operations"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2011: Final Value of Variable After Performing Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int X = 0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="X++")
            {
                X++;
            }
            else if(operations[i] == "++X")
            {
                ++X;
            }
            else if(operations[i] == "X--")
            {
                X--;
            }
            else if(operations[i] == "--X")
            {
                --X;
            }
        }
        return X;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2011.md" >}}
---
{{< youtube xPKIXpfxvZ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2012: Sum of Beauty in the Array](https://grid47.xyz/leetcode/solution-2012-sum-of-beauty-in-the-array/) |
| --- |
