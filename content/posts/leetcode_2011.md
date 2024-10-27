
+++
authors = ["Yasir"]
title = "Leetcode 2011: Final Value of Variable After Performing Operations"
date = "2019-04-27"
description = "Solution to Leetcode 2011"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/)

---

**Code:**

{{< highlight html >}}
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

