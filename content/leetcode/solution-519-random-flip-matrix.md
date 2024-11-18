
+++
authors = ["grid47"]
title = "Leetcode 519: Random Flip Matrix"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 519: Random Flip Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "9JsC0Dg9oX8"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp"
+++



[`Problem Link`](https://leetcode.com/problems/random-flip-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/519.webp" 
    alt="A matrix where cells are randomly flipped, with each flipped cell softly glowing as it changes state."
    caption="Solution to LeetCode 519: Random Flip Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, int> mp;
    int row, col, lmt;
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        reset();
    }
    
    vector<int> flip() {
        int idx = rand()%lmt;
        lmt--;
        int x = mp.count(idx)? mp[idx] : idx;
        mp[idx] = mp.count(lmt)? mp[lmt]: lmt;
        return vector<int>{x/col, x%col};
    }
    
    void reset() {
        mp.clear();
        lmt = row*col;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/519.md" >}}
---
{{< youtube 9JsC0Dg9oX8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #520: Detect Capital](https://grid47.xyz/leetcode/solution-520-detect-capital/) |
| --- |
