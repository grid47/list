
+++
authors = ["Yasir"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2017-04-29"
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

**Code:**

{{< highlight html >}}
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

