
+++
authors = ["Crafted by Me"]
title = "Leetcode 2349: Design a Number Container System"
date = "2018-05-29"
description = "In-depth solution and explanation for Leetcode 2349: Design a Number Container System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2350: Shortest Impossible Sequence of Rolls](https://grid47.xyz/posts/leetcode_2350) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

