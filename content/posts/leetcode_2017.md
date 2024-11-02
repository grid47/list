
+++
authors = ["Crafted by Me"]
title = "Leetcode 2017: Grid Game"
date = "2019-04-26"
description = "Solution to Leetcode 2017"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/grid-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom = 0;
        int n = grid[0].size();
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            top -= grid[0][i];
            ans = min(ans, max(top, bottom));
            bottom+= grid[1][i];
      }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube N4wDSOw65hI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

