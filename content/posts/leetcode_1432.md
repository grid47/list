
+++
authors = ["Yasir"]
title = "Leetcode 1432: Max Difference You Can Get From Changing an Integer"
date = "2020-11-26"
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

{{< highlight html >}}
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

