
+++
authors = ["grid47"]
title = "Leetcode 2178: Maximum Split of Positive Even Integers"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2178: Maximum Split of Positive Even Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fM7MJFhrm-8"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fM7MJFhrm-8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> ans;
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> tmp;
        if(sum % 2 == 1) return ans;
        
        int cur = 2;
        while(sum >= cur) {
            ans.push_back(cur);
            sum -= cur;
            cur += 2;
        }
        if(sum > 0) ans[ans.size() - 1] += sum;
        
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2178.md" >}}
---
{{< youtube fM7MJFhrm-8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2180: Count Integers With Even Digit Sum](https://grid47.xyz/leetcode/solution-2180-count-integers-with-even-digit-sum/) |
| --- |
