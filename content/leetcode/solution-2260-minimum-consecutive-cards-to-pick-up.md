
+++
authors = ["grid47"]
title = "Leetcode 2260: Minimum Consecutive Cards to Pick Up"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2260: Minimum Consecutive Cards to Pick Up in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BIHnh-MH6CQ"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BIHnh-MH6CQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n = cards.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; i++){
            if(mp.count(cards[i])) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;            
        }
        
        return ans == n + 1? -1: ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2260.md" >}}
---
{{< youtube BIHnh-MH6CQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2261: K Divisible Elements Subarrays](https://grid47.xyz/leetcode/solution-2261-k-divisible-elements-subarrays/) |
| --- |