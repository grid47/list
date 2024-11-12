
+++
authors = ["grid47"]
title = "Leetcode 2349: Design a Number Container System"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2349: Design a Number Container System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-a-number-container-system/description/)

---
**Code:**

{{< highlight cpp >}}
class NumberContainers {
    map<int, set<int>> mp;
    map<int, int> in;
public:
    NumberContainers() {
        
    }
    
    void change(int idx, int num) {
        if(in.count(idx)) {
            
            int x = in[idx];
            mp[x].erase(idx);


        } 
        in[idx] = num;
        mp[num].insert(idx);
         
    }
    
    int find(int num) {
        if(mp.count(num) && !mp[num].empty()) {
            return *begin(mp[num]);
        } return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2349.md" >}}
---
{{< youtube mzU9eVB62hA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2351: First Letter to Appear Twice](https://grid47.xyz/posts/leetcode-2351-first-letter-to-appear-twice-solution/) |
| --- |
