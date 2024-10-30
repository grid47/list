
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2017-05-02"
description = "Solution to Leetcode 2739"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-distance-traveled/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distanceTraveled(int mt, int at) {        
        int net = 0;
        
        while(mt > 0) {
            int red = min(5, mt);
            mt -= red;
            net += red * 10;
            if(red == 5 && at > 0) {
                mt += 1;
                at--;
            }
        }
        
        return net;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

