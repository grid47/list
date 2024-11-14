
+++
authors = ["grid47"]
title = "Leetcode 670: Maximum Swap"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 670: Maximum Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-swap/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/670.webp" 
    alt="A number where the maximum swap is performed, with each swap softly glowing as it occurs."
    caption="Solution to LeetCode 670: Maximum Swap Problem"
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
    int maximumSwap(int num) {

        vector<int> idx(10, 0);

        string nm = to_string(num);
        for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

        for(int i = 0; i < nm.size(); i++)
        for(int j = 9; j > nm[i] - '0'; j--) {
            if(idx[j] > i) {
                swap(nm[idx[j]], nm[i]);
                return stoi(nm);
            }
        }

        return num;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/670.md" >}}
---
{{< youtube arecn8VuQL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #672: Bulb Switcher II](https://grid47.xyz/posts/leetcode-672-bulb-switcher-ii-solution/) |
| --- |
