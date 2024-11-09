
+++
authors = ["grid47"]
title = "Leetcode 380: Insert Delete GetRandom O(1)"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 380: Insert Delete GetRandom O(1) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Design","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insert-delete-getrandom-o1/description/)

---
**Code:**

{{< highlight cpp >}}
class RandomizedSet {
private:
    vector<int> a;
    unordered_map<int,int> m;
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if(m.find(val)!=m.end())
            return false;
        else{
            a.push_back(val);
            m[val]=a.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
            return false;
        else{
            int last=a.back(); 
            a[m[val]]=a.back();
            a.pop_back();
            m[last]=m[val];   
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/380.md" >}}
---
{{< youtube j4KwhBziOpg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #382: Linked List Random Node](https://grid47.xyz/posts/leetcode-380-insert-delete-getrandom-o1-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
