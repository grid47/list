
+++
authors = ["grid47"]
title = "Leetcode 1823: Find the Winner of the Circular Game"
date = "2024-05-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1823: Find the Winner of the Circular Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Recursion","Queue","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PBBQgW_75e0"
youtube_upload_date="2024-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/PBBQgW_75e0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        
        while(q.size() != 1) {
            int x= k;
            while(x > 1) {
                int r = q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        
        return q.front();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1823.md" >}}
---
{{< youtube PBBQgW_75e0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1824: Minimum Sideway Jumps](https://grid47.xyz/leetcode/solution-1824-minimum-sideway-jumps/) |
| --- |
