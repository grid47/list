
+++
authors = ["grid47"]
title = "Leetcode 2526: Find Consecutive Integers from a Data Stream"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2526: Find Consecutive Integers from a Data Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Queue","Counting","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3VXPkJ8bInY"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3VXPkJ8bInY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/)

---
**Code:**

{{< highlight cpp >}}
class DataStream {
public:
    int val, k, cnt = 0;
    DataStream(int value, int k) {
        val = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(val == num) cnt = min(k, cnt+1);
        else {
            cnt = 0;
        }
        return k == cnt;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2526.md" >}}
---
{{< youtube 3VXPkJ8bInY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2527: Find Xor-Beauty of Array](https://grid47.xyz/leetcode/solution-2527-find-xor-beauty-of-array/) |
| --- |