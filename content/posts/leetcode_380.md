
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 380: Insert Delete GetRandom O(1)"
date = "2023-10-16"
description = "Solution to Leetcode 380"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
