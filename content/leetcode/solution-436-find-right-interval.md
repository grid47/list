
+++
authors = ["grid47"]
title = "Leetcode 436: Find Right Interval"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 436: Find Right Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-right-interval/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/436.webp" 
    alt="A series of intervals, with each right interval softly lighting up as it is found for each point."
    caption="Solution to LeetCode 436: Find Right Interval Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& iv) {
        map<int, int> mk;
        
        int n = iv.size();
        for(int i = 0; i < n; i++)
            mk[iv[i][0]] = i;
        
        vector<int> ans(n, -1);
        for(int j = 0; j < n; j++) {
            auto i= iv[j];
            if(mk.lower_bound(i[1]) != end(mk))
                ans[j] = mk.lower_bound(i[1])->second;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/436.md" >}}
---
{{< youtube VEBbumHmps8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #437: Path Sum III](https://grid47.xyz/leetcode/solution-437-path-sum-iii/) |
| --- |
