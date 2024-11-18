
+++
authors = ["grid47"]
title = "Leetcode 3005: Count Elements With Maximum Frequency"
date = "2024-01-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3005: Count Elements With Maximum Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ydihp-cBFqw"
youtube_upload_date="2024-01-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ydihp-cBFqw/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frq;
        int mx = 0;
        for (int num : nums) {
            frq[num]++;
            mx = max(mx, frq[num]);
        }

        int cnt = 0;
        for (auto it : frq) {
            if (it.second == mx)
                cnt++;
        }

        int net = mx * cnt;

        return net;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3005.md" >}}
---
{{< youtube ydihp-cBFqw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3026: Maximum Good Subarray Sum](https://grid47.xyz/leetcode/solution-3026-maximum-good-subarray-sum/) |
| --- |
