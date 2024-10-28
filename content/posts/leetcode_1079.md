
+++
authors = ["Yasir"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2021-11-15"
description = "Solution to Leetcode 1079"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/letter-tile-possibilities/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

