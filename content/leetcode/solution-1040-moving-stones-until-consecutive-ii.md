
+++
authors = ["grid47"]
title = "Leetcode 1040: Moving Stones Until Consecutive II"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1040: Moving Stones Until Consecutive II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "4Xhq2NDbA-I"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& pos) {
        sort(pos.begin(), pos.end());
        
        int low = INT_MAX;
        int j = 0, n = pos.size();
        for(int i = 0; i < n; i++) {
            while(pos[i] - pos[j] + 1 > n) j++;
            
            int cnt = i - j + 1;
            
            if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
                low = min(low, 2);
            else low = min(low, n - cnt);
        }
        return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1040.md" >}}
---
{{< youtube 4Xhq2NDbA-I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1042: Flower Planting With No Adjacent](https://grid47.xyz/leetcode/solution-1042-flower-planting-with-no-adjacent/) |
| --- |
