
+++
authors = ["Crafted by Me"]
title = "Leetcode 380: Insert Delete GetRandom O(1)"
date = "2023-10-19"
description = "In-depth solution and explanation for Leetcode 380: Insert Delete GetRandom O(1) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| Next : [LeetCode #381: Insert Delete GetRandom O(1) - Duplicates allowed](https://grid47.xyz/posts/leetcode_381) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

