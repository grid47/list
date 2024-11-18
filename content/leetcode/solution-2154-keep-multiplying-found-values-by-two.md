
+++
authors = ["grid47"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2154: Keep Multiplying Found Values by Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-6Wf-ZShQQ"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-6Wf-ZShQQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};
        for(auto i:nums) h[i]++;
		
        while(o<=1000 && h[o])
            o*=2;
        
        return o;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2154.md" >}}
---
{{< youtube b-6Wf-ZShQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2155: All Divisions With the Highest Score of a Binary Array](https://grid47.xyz/leetcode/solution-2155-all-divisions-with-the-highest-score-of-a-binary-array/) |
| --- |
