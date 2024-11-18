
+++
authors = ["grid47"]
title = "Leetcode 2760: Longest Even Odd Subarray With Threshold"
date = "2024-02-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2760: Longest Even Odd Subarray With Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_XNaJUXSh04"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/_XNaJUXSh04/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int longestAlternatingSubarray(vector<int>& n, int threshold) {
    int res = 0;
    for (int l = 0, cnt = 0; l < n.size(); ++l) {
        if (n[l] <= threshold)
            cnt = cnt == 0 ?
                n[l] % 2 == 0 :
                n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
        else
            cnt = 0;
        res = max(res, cnt);
    }
    return res;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2760.md" >}}
---
{{< youtube _XNaJUXSh04 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2761: Prime Pairs With Target Sum](https://grid47.xyz/leetcode/solution-2761-prime-pairs-with-target-sum/) |
| --- |
