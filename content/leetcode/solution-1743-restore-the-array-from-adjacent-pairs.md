
+++
authors = ["grid47"]
title = "Leetcode 1743: Restore the Array From Adjacent Pairs"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1743: Restore the Array From Adjacent Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SGfdp6CFDrA"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/SGfdp6CFDrA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size() + 1;
        map<int, vector<int>> mp;
        for(auto e : ap) {
            int u = e[0], v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> ans;
        for(auto it: mp) {
            if(it.second.size() == 1) {
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }

        while(ans.size() < n) {
            auto tail = ans.back(), prv = ans[ans.size() - 2];
            auto &next = mp[tail];
            if(next[0] != prv)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }

        return ans;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1743.md" >}}
---
{{< youtube SGfdp6CFDrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1744: Can You Eat Your Favorite Candy on Your Favorite Day?](https://grid47.xyz/leetcode/solution-1744-can-you-eat-your-favorite-candy-on-your-favorite-day/) |
| --- |
