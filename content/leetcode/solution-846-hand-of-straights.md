
+++
authors = ["grid47"]
title = "Leetcode 846: Hand of Straights"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 846: Hand of Straights in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "amnrMCVd2YI"
youtube_upload_date="2021-05-21"
youtube_thumbnail="https://i.ytimg.com/vi/amnrMCVd2YI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/hand-of-straights/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int x: hand) mp[x]++;
        
        for(auto it: mp) {
            if(mp[it.first] > 0)
            for(int i = 1; i < groupSize; i++){
                mp[it.first + i] -= mp[it.first];
                if(mp[it.first + i] < 0)
                    return false;
            }
            mp[it.first] = 0;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/846.md" >}}
---
{{< youtube amnrMCVd2YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #848: Shifting Letters](https://grid47.xyz/leetcode/solution-848-shifting-letters/) |
| --- |