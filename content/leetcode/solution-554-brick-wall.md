
+++
authors = ["grid47"]
title = "Leetcode 554: Brick Wall"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 554: Brick Wall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Kkmv2h48ekw"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/554.webp"
+++



[`Problem Link`](https://leetcode.com/problems/brick-wall/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/554.webp" 
    alt="A wall made of bricks where the minimum number of bricks to be removed is calculated, with the optimal brick removals glowing."
    caption="Solution to LeetCode 554: Brick Wall Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #556: Next Greater Element III](https://grid47.xyz/leetcode/solution-556-next-greater-element-iii/) |
| --- |
