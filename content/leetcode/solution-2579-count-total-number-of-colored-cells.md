
+++
authors = ["grid47"]
title = "Leetcode 2579: Count Total Number of Colored Cells"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2579: Count Total Number of Colored Cells in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Gso3ss4daQI"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Gso3ss4daQI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-total-number-of-colored-cells/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2579.md" >}}
---
{{< youtube Gso3ss4daQI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2580: Count Ways to Group Overlapping Ranges](https://grid47.xyz/leetcode/solution-2580-count-ways-to-group-overlapping-ranges/) |
| --- |