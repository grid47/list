
+++
authors = ["grid47"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2024-07-22"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1080: Insufficient Nodes in Root to Leaf Paths](https://grid47.xyz/posts/leetcode-1080-insufficient-nodes-in-root-to-leaf-paths-solution/) |
| --- |
