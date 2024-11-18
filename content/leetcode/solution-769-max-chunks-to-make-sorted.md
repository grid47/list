
+++
authors = ["grid47"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 769: Max Chunks To Make Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Sorting","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "b3Mf8c7hKjk"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/769.webp"
+++



[`Problem Link`](https://leetcode.com/problems/max-chunks-to-make-sorted/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/769.webp" 
    alt="A sequence where chunks are sorted, with each sorted chunk glowing softly as the process completes."
    caption="Solution to LeetCode 769: Max Chunks To Make Sorted Problem"
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
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();

        int res = 0, mx = arr[0];

        for(int i = 0; i < n; i++) {
            
            mx = max(mx, arr[i]);
            res += (mx == i);
            
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/769.md" >}}
---
{{< youtube b3Mf8c7hKjk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #775: Global and Local Inversions](https://grid47.xyz/leetcode/solution-775-global-and-local-inversions/) |
| --- |
