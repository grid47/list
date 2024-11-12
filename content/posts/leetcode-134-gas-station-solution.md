
+++
authors = ["grid47"]
title = "Leetcode 134: Gas Station"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 134: Gas Station in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/gas-station/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/134.webp" 
    alt="A calm sequence of gas stations, each glowing softly, with the optimal starting point gently illuminated."
    caption="Solution to LeetCode 134: Gas Station Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int net = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i];
            net += cost[i];
        }
        if (net > tank) return -1;
        
        tank = 0;
        int res = -1;
        
        for(int i = 0; i < gas.size(); i++) {
            tank += gas[i];
            tank -= cost[i];
            if(tank < 0) {
                tank = 0;
                res = i;
            }
        }
        return res + 1;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/134.md" >}}
---
{{< youtube xmJZSYSvgfE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #136: Single Number](https://grid47.xyz/posts/leetcode-136-single-number-solution/) |
| --- |
