
+++
authors = ["Crafted by Me"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1079: Letter Tile Possibilities in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/letter-tile-possibilities/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> ans;
        set<int> seen;

        gen(tiles, 0, "", ans, seen);
        return ans.size();
    }

    void gen(string tiles, int idx, string res, set<string> &ans, set<int> &vis ) {
        if(idx == tiles.size()) return;
        for(int i = 0; i < tiles.size(); i++) {
            if(!vis.count(i)) {
                vis.insert(i);
                ans.insert(res + tiles[i]);
    gen(tiles, idx + 1, res + tiles[i], ans, vis);
                vis.erase(i);
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1079.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1080: Insufficient Nodes in Root to Leaf Paths](https://grid47.xyz/posts/leetcode_1080) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
