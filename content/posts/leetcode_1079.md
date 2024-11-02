
+++
authors = ["Crafted by Me"]
title = "Leetcode 1079: Letter Tile Possibilities"
date = "2020-11-18"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

