
+++
authors = ["Crafted by Me"]
title = "Leetcode 2739: Total Distance Traveled"
date = "2017-05-04"
description = "In-depth solution and explanation for Leetcode 2739: Total Distance Traveled in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| Next : [LeetCode #2740: Find the Value of the Partition](https://grid47.xyz/posts/leetcode_2740) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

