
+++
authors = ["grid47"]
title = "Leetcode 658: Find K Closest Elements"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 658: Find K Closest Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sliding Window","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp"
youtube = "o-YDQzHoaKM"
youtube_upload_date="2022-01-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/o-YDQzHoaKM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-k-closest-elements/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/658.webp" 
    alt="A set of elements with the k closest ones glowing softly as they are identified."
    caption="Solution to LeetCode 658: Find K Closest Elements Problem"
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else r = m;
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/658.md" >}}
---
{{< youtube o-YDQzHoaKM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #659: Split Array into Consecutive Subsequences](https://grid47.xyz/leetcode/solution-659-split-array-into-consecutive-subsequences/) |
| --- |