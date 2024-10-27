
+++
authors = ["Yasir"]
title = "Leetcode 2579: Count Total Number of Colored Cells"
date = "2017-10-06"
description = "Solution to Leetcode 2579"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-total-number-of-colored-cells/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long coloredCells(int n) {
        long long x = 1;
        long long y = 4;
        while(--n) {
            x += y;
            y += 4;
        }
        // 0 4 8 12
        return x;
        
        queue<pair<int, int>> q;
        unordered_map<int, unordered_map<int, int>> mp;
        long long cnt = 1;
        q.push({0,0});
        mp[0][0] = true;
        int dir[] = {0,1,0,-1,0};
        while(--n) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                // cout << it.first << " " << it.second << "\n";
                for(int i = 0; i < 4; i++) {
                    int x = it.first + dir[i], y = it.second + dir[i + 1];
                    if(mp.count(x) && mp[x].count(y)) continue;
                    mp[x][y] = true;
                    cnt++;
                    q.push({x, y});
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

