
+++
authors = ["grid47"]
title = "Leetcode 1109: Corporate Flight Bookings"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1109: Corporate Flight Bookings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "geZPsJWEzfc"
youtube_upload_date="2019-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/geZPsJWEzfc/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/corporate-flight-bookings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int m) {

        vector<int> ans(m, 0);
        for(auto& v: bookings) {
            ans[v[0] - 1] += v[2];
            if(v[1] < m) ans[v[1]] -= v[2];
        }

        for(int j = 1; j < m; j++)
            ans[j] += ans[j-1];

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1109.md" >}}
---
{{< youtube geZPsJWEzfc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1110: Delete Nodes And Return Forest](https://grid47.xyz/leetcode/solution-1110-delete-nodes-and-return-forest/) |
| --- |
