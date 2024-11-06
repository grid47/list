
+++
authors = ["Crafted by Me"]
title = "Leetcode 2011: Final Value of Variable After Performing Operations"
date = "2024-11-01"
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


---
{{< youtube xPKIXpfxvZ8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2012: Sum of Beauty in the Array](https://grid47.xyz/posts/leetcode_2012) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
