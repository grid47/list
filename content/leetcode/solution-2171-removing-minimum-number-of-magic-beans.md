
+++
authors = ["grid47"]
title = "Leetcode 2171: Removing Minimum Number of Magic Beans"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2171: Removing Minimum Number of Magic Beans in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Enumeration","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MAECrl0V0xs"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/MAECrl0V0xs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long sum = accumulate(begin(beans), end(beans), 0L);
        sort(beans.begin(), beans.end());
        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, sum - (long long) (n - i) * beans[i]);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2171.md" >}}
---
{{< youtube MAECrl0V0xs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2176: Count Equal and Divisible Pairs in an Array](https://grid47.xyz/leetcode/solution-2176-count-equal-and-divisible-pairs-in-an-array/) |
| --- |
