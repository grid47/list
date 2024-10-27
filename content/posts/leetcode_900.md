
+++
authors = ["Yasir"]
title = "Leetcode 900: RLE Iterator"
date = "2022-05-12"
description = "Solution to Leetcode 900"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rle-iterator/description/)

---

**Code:**

{{< highlight html >}}
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

