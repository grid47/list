
+++
authors = ["Crafted by Me"]
title = "Leetcode 1432: Max Difference You Can Get From Changing an Integer"
date = "2019-12-01"
description = "Solution to Leetcode 1432"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int change(int num, int x, int y) {
        int tmp = 0, ten = 1;
        int digit;
        while(num) {
            digit = num % 10;
            if(digit == x) digit = y;
            tmp = ten * digit + tmp;
            num /= 10;
            ten *= 10;
        }
        return digit == 0? -1: tmp;
    }
    
    int maxDiff(int num) {
        int mn = num, mx = num;
        for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++) {
            if(i == j) continue;
            int ret = change(num, i, j);
            if(ret <= 0) continue;
            mn = min(mn, ret);
            mx = max(mx, ret);
        }
        cout << mx << " " << mn;
        return mx - mn;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

