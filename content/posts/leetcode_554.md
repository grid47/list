
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 554: Brick Wall"
date = "2023-04-26"
description = "Solution to Leetcode 554"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

