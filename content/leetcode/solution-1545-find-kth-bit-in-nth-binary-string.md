
+++
authors = ["grid47"]
title = "Leetcode 1545: Find Kth Bit in Nth Binary String"
date = "2024-06-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1545: Find Kth Bit in Nth Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Recursion","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "34QYE5HAFy4"
youtube_upload_date="2020-10-12"
youtube_thumbnail="https://i.ytimg.com/vi/34QYE5HAFy4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char findKthBit(int n, int k) {

        string s = "0";
        
        for(int i = 2; i <= n; i++) {
            string tmp = s;
            s += '1';
            for(int j = tmp.size() - 1; j >= 0; j--) {
                
                s += (tmp[j] == '0') ? '1':'0';
                
            }
        }

        return s[k-1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1545.md" >}}
---
{{< youtube 34QYE5HAFy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1546: Maximum Number of Non-Overlapping Subarrays With Sum Equals Target](https://grid47.xyz/leetcode/solution-1546-maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/) |
| --- |