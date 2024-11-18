
+++
authors = ["grid47"]
title = "Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R8geTAz_yk8"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R8geTAz_yk8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length()); 
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1769.md" >}}
---
{{< youtube R8geTAz_yk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1773: Count Items Matching a Rule](https://grid47.xyz/leetcode/solution-1773-count-items-matching-a-rule/) |
| --- |
