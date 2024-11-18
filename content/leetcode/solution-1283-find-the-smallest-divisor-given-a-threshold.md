
+++
authors = ["grid47"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1283: Find the Smallest Divisor Given a Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KGlnb3yT8iY"
youtube_upload_date="2020-11-06"
youtube_thumbnail="https://i.ytimg.com/vi/KGlnb3yT8iY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, m , sum;
        while(left < right) {
            m = (left + right) / 2;
            sum = 0;
            for(int i: nums) sum += (i + m - 1)/m;
            if(sum > threshold) 
            left = m + 1;
            else right = m;
        }
        return left;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1283.md" >}}
---
{{< youtube KGlnb3yT8iY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1286: Iterator for Combination](https://grid47.xyz/leetcode/solution-1286-iterator-for-combination/) |
| --- |
