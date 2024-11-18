
+++
authors = ["grid47"]
title = "Leetcode 2748: Number of Beautiful Pairs"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2748: Number of Beautiful Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mjceDBNh7vg"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/mjceDBNh7vg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-beautiful-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int countBeautifulPairs(vector<int>& nums) {
    int cnt[10] = {}, res = 0;
    for(int i = 0; i < nums.size(); ++i) {
        for (int n = 1; n < 10; ++n)
            if (gcd(n, nums[i] % 10) == 1)
                res += cnt[n];
        while (nums[i] >= 10)
            nums[i] /= 10;
        ++cnt[nums[i]];
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2748.md" >}}
---
{{< youtube mjceDBNh7vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2750: Ways to Split Array Into Good Subarrays](https://grid47.xyz/leetcode/solution-2750-ways-to-split-array-into-good-subarrays/) |
| --- |
