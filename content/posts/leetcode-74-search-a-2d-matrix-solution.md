
+++
authors = ["grid47"]
title = "Leetcode 74: Search a 2D Matrix"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 74: Search a 2D Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-a-2d-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/74.webp" 
    alt="A soft, glowing grid with a pinpoint highlighting the search area."
    caption="Solution to LeetCode 74: Search a 2D Matrix Problem"
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
    bool searchMatrix(vector<vector<int>>& mtx, int target) {
        int m = mtx.size(), n = mtx[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l) /2;
            int rw = mid / n, c = mid % n, val = mtx[rw][c];
                 if(val == target) return true;
            else if(val  > target) r = mid - 1;
            else                   l = mid + 1;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/74.md" >}}
---
{{< youtube x-dYOtIudzc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #75: Sort Colors](https://grid47.xyz/posts/leetcode-75-sort-colors-solution/) |
| --- |
