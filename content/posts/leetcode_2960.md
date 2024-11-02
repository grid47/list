
+++
authors = ["Crafted by Me"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2016-09-25"
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

