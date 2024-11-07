
+++
authors = ["Crafted by Me"]
title = "Leetcode 900: RLE Iterator"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 900: RLE Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Counting","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rle-iterator/description/)

---
**Code:**

{{< highlight cpp >}}
class RLEIterator {
    vector<int> arr;
    int idx = 0;
public:
    RLEIterator(vector<int>& encoding) {
        arr = encoding;
        idx = 0;
    }
    
    int next(int n) {
        while(idx < arr.size()) {
            if(n > arr[idx]) {
                n -= arr[idx];
                idx += 2;
            } else {
                arr[idx] -= n;
                return arr[idx + 1];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/900.md" >}}
---
{{< youtube 69UElCwk6B4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #901: Online Stock Span](https://grid47.xyz/posts/leetcode_901) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
