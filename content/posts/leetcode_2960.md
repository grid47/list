
+++
authors = ["Crafted by Me"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2016-09-24"
description = "Solution to Leetcode 2960"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-tested-devices-after-test-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for(auto b: batteryPercentages) ans += (b > ans)?1: 0;
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

