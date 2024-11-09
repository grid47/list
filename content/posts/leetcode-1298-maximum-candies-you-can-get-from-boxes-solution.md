
+++
authors = ["grid47"]
title = "Leetcode 1298: Maximum Candies You Can Get from Boxes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1298: Maximum Candies You Can Get from Boxes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Graph"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& ib) {

        vector<int> vis(status.size(), 0);
        set<int> box, magic;
        queue<int> open;
        int res = 0;
        for(int i = 0; i < ib.size(); i++) {
            if(status[ib[i]] == 1) {
                open.push(ib[i]);
                vis[ib[i]] = 1;
            } else box.insert(ib[i]);
        }

        while(!open.empty()) {
            int x = open.front();
            res += candies[x];
            open.pop();
            for(int key: keys[x]) {
                if(box.count(key)) {
                    status[key] = 1;
                    box.erase(key);
                    open.push(key);
                    vis[key] = 1;
                } else if(vis[key] != 1) {
                    magic.insert(key);
                }
            }
            
            for(int bx: containedBoxes[x]) {
                if(vis[bx]) continue;
                if(status[bx] == 1) {
                    if(magic.count(bx)) magic.erase(bx);
                    open.push(bx);
                    vis[bx] = 1;
                }else if(magic.count(bx)) {
                    status[bx] = 1;
                    magic.erase(bx);
                    open.push(bx);
                    vis[bx] = 1;
                } else {
                    box.insert(bx);
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1298.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1300: Sum of Mutated Array Closest to Target](https://grid47.xyz/posts/leetcode-1300-sum-of-mutated-array-closest-to-target-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
