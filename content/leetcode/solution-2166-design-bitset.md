
+++
authors = ["grid47"]
title = "Leetcode 2166: Design Bitset"
date = "2024-04-04"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2166.md" >}}
---
{{< youtube FWv-b_VITvA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2169: Count Operations to Obtain Zero](https://grid47.xyz/leetcode/solution-2169-count-operations-to-obtain-zero/) |
| --- |
