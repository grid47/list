
+++
authors = ["grid47"]
title = "Leetcode 2960: Count Tested Devices After Test Operations"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2960: Count Tested Devices After Test Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation","Counting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2960.md" >}}
---
{{< youtube 77lcjZ2prk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2961: Double Modular Exponentiation](https://grid47.xyz/posts/leetcode-2961-double-modular-exponentiation-solution/) |
| --- |
