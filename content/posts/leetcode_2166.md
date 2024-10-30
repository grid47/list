
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2166: Design Bitset"
date = "2018-11-26"
description = "Solution to Leetcode 2166"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-bitset/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

