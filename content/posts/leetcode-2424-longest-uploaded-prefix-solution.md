
+++
authors = ["grid47"]
title = "Leetcode 2424: Longest Uploaded Prefix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2424: Longest Uploaded Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Union Find","Design","Binary Indexed Tree","Segment Tree","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2425: Bitwise XOR of All Pairings](https://grid47.xyz/posts/leetcode-2424-longest-uploaded-prefix-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
