
+++
authors = ["Crafted by Me"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2960: Count Tested Devices After Test Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
{{< youtube 77lcjZ2prk8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2961: Double Modular Exponentiation](https://grid47.xyz/posts/leetcode_2961) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

