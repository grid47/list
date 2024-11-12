
+++
authors = ["grid47"]
title = "Leetcode 2079: Watering Plants"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2079: Watering Plants in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/watering-plants/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wateringPlants(vector<int>& num, int cap) {
        int n = num.size();
        int rel = cap;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(num[i] > rel) {
                rel = cap;
                res += 2*i;
            } 
            rel -= num[i];            
        }
        return res + n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2079.md" >}}
---
{{< youtube 6GNga8RRNSQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2080: Range Frequency Queries](https://grid47.xyz/posts/leetcode-2080-range-frequency-queries-solution/) |
| --- |
