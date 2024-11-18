
+++
authors = ["grid47"]
title = "Leetcode 2424: Longest Uploaded Prefix"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2424: Longest Uploaded Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Union Find","Design","Binary Indexed Tree","Segment Tree","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8UaltcVnL5E"
youtube_upload_date="2022-10-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8UaltcVnL5E/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-uploaded-prefix/description/)

---
**Code:**

{{< highlight cpp >}}
class LUPrefix {
public:
    int i;
    vector<bool> arr;
    LUPrefix(int n) {
        arr.resize(n + 1);
        i = 1;
    }
    
    void upload(int vid) {
        arr[vid] = true;
        while(i < arr.size() && arr[i]) i++;
    }
    
    int longest() {
        return i - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2424.md" >}}
---
{{< youtube 8UaltcVnL5E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2425: Bitwise XOR of All Pairings](https://grid47.xyz/leetcode/solution-2425-bitwise-xor-of-all-pairings/) |
| --- |
