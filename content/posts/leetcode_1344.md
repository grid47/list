
+++
authors = ["Yasir"]
title = "Leetcode 1344: Angle Between Hands of a Clock"
date = "2021-02-23"
description = "Solution to Leetcode 1344"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/angle-between-hands-of-a-clock/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    double angleClock(int h, int minutes) {
        
        double mn = 360 *(double)minutes/60;
        
        double hrs = 360 * ((double)(h == 12? 0: h) / 12) + 30* ((double)minutes/60);
        cout << mn << " " << hrs;
            
        return min(abs(mn - hrs), 360 - (abs(mn - hrs)));
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

