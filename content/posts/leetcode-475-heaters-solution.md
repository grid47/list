
+++
authors = ["grid47"]
title = "Leetcode 475: Heaters"
date = "2024-09-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 475: Heaters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/heaters/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/475.webp" 
    alt="A grid where heaters light up and warm nearby houses, with each heater softly illuminating its effect."
    caption="Solution to LeetCode 475: Heaters Problem"
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
    int findRadius(vector<int>& home, vector<int>& warm) {
        sort(home.begin(), home.end());
        sort(warm.begin(), warm.end());
        int m = home.size(), n = warm.size();
        
        vector<int> res(m, INT_MAX);
        
        for(int h = 0, w = 0; h < m && w < n; ) {
            if (home[h] <= warm[w]) {
                res[h] = warm[w] - home[h];
                h++;
            } else w++;
        }
        
        for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
            if (home[h] >= warm[w]) {
                res[h] = min(res[h], home[h] - warm[w]);
                h--;
            } else w--;
        }
        
        return *max_element(res.begin(), res.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/475.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #477: Total Hamming Distance](https://grid47.xyz/posts/leetcode-477-total-hamming-distance-solution/) |
| --- |
