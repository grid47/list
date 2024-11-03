
+++
authors = ["Crafted by Me"]
title = "Leetcode 554: Brick Wall"
date = "2023-04-28"
description = "In-depth solution and explanation for Leetcode 554: Brick Wall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/brick-wall/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edge_freq;
        int max_freq = 0;
        for(int row = 0; row < wall.size(); row++) {
            int edge_pos = 0;
            for(int brick_no = 0; brick_no < wall[row].size() - 1; brick_no++) {
                int curr_brick_length = wall[row][brick_no];
                edge_pos = edge_pos + curr_brick_length;
                edge_freq[edge_pos]++;
                max_freq = max(edge_freq[edge_pos], max_freq);
            }
        }
        return wall.size() - max_freq;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/554.md" >}}
---
{{< youtube Kkmv2h48ekw >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

