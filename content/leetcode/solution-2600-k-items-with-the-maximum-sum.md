
+++
authors = ["grid47"]
title = "Leetcode 2600: K Items With the Maximum Sum"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2600: K Items With the Maximum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "HmEYKbfjCLA"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HmEYKbfjCLA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/k-items-with-the-maximum-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kItemsWithMaximumSum(int one, int zero, int neg, int k) {
        int sum = 0;
        sum += min(one, k);
        k -= min(one, k);
        if(k > 0) {
            k -= min(zero, k);
        }
        if(k > 0) {
            sum -= min(neg, k);
            k -= min(neg, k);
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2600.md" >}}
---
{{< youtube HmEYKbfjCLA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2601: Prime Subtraction Operation](https://grid47.xyz/leetcode/solution-2601-prime-subtraction-operation/) |
| --- |
