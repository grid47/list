
+++
authors = ["Crafted by Me"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2017-11-24"
description = "Solution to Leetcode 2169"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

