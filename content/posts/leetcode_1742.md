
+++
authors = ["Crafted by Me"]
title = "Leetcode 1742: Maximum Number of Balls in a Box"
date = "2020-01-26"
description = "In-depth solution and explanation for Leetcode 1742: Maximum Number of Balls in a Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        vector<int> box (46,0);
        for(int i = lowLimit;i<=highLimit;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp)
            {
                sum = sum + temp%10;
                temp = temp/10;
            }
            box[sum]++;
        }
        
        return *max_element(box.begin(),box.end());
    }
};
{{< /highlight >}}


---


"| 1743: Restore the Array From Adjacent Pairs |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

