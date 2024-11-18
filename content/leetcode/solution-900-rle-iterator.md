
+++
authors = ["grid47"]
title = "Leetcode 900: RLE Iterator"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 900: RLE Iterator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Design","Counting","Iterator"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "69UElCwk6B4"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #901: Online Stock Span](https://grid47.xyz/leetcode/solution-901-online-stock-span/) |
| --- |
