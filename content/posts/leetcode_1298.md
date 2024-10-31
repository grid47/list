
+++
authors = ["Crafted by Me"]
title = "Leetcode 1298: Maximum Candies You Can Get from Boxes"
date = "2021-04-13"
description = "Solution to Leetcode 1298"
tags = [
    
]
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

