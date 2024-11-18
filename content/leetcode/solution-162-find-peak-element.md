
+++
authors = ["grid47"]
title = "Leetcode 162: Find Peak Element"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 162: Find Peak Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-peak-element/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/162.webp" 
    alt="A smooth curve of numbers with the highest point glowing brightly, symbolizing the peak."
    caption="Solution to LeetCode 162: Find Peak Element Problem"
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
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            bool x = mid > 0? arr[mid - 1] < arr[mid] : true;
            bool y = mid < n -1 ? arr[mid + 1] < arr[mid] : true;
            
            if(x && y) return mid;
            if(!x && y) r = mid - 1;
            else if(x && !y) l = mid + 1;
            else r = mid - 1;            
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/162.md" >}}
---
{{< youtube 31foR5tJapQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #167: Two Sum II - Input Array Is Sorted](https://grid47.xyz/leetcode/solution-167-two-sum-ii-input-array-is-sorted/) |
| --- |
