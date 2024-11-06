
+++
authors = ["Crafted by Me"]
title = "Leetcode 2166: Design Bitset"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2166: Design Bitset in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-bitset/description/)

---

**Code:**

{{< highlight cpp >}}
class Bitset {
    string s, flipp;
    int ones = 0, size = 0;
public:
    Bitset(int size) {
        s = string(size, '0');
        flipp = string(size, '1');
        ones = 0;
        this->size = size;
    }
    
    void fix(int idx) {
        if(s[idx] == '0') ones++;
        s[idx] = '1';
        flipp[idx] = '0';
    }
    
    void unfix(int idx) {
        if(s[idx] == '1') ones--;
        s[idx] = '0';
        flipp[idx] = '1';        
    }
    
    void flip() {
        ones = size - ones;
        s.swap(flipp);
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
{{< /highlight >}}


---
{{< youtube FWv-b_VITvA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2167: Minimum Time to Remove All Cars Containing Illegal Goods](https://grid47.xyz/posts/leetcode_2167) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
