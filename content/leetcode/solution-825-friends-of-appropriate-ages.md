
+++
authors = ["grid47"]
title = "Leetcode 825: Friends Of Appropriate Ages"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 825: Friends Of Appropriate Ages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "0_4H68f85HQ"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/friends-of-appropriate-ages/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for(int age: ages)
            cnt[age]++;

        int res = 0;
        for(auto a: cnt)
        for(auto b: cnt)
        if(request(a.first, b.first))
            res += a.second * (b.second - (a.first == b.first? 1: 0));
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/825.md" >}}
---
{{< youtube 0_4H68f85HQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #826: Most Profit Assigning Work](https://grid47.xyz/leetcode/solution-826-most-profit-assigning-work/) |
| --- |
