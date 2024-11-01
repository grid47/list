
+++
authors = ["Crafted by Me"]
title = "Leetcode 900: RLE Iterator"
date = "2022-05-17"
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
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

