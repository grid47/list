
+++
authors = ["Crafted by Me"]
title = "Leetcode 2349: Design a Number Container System"
date = "2018-05-28"
description = "Solution to Leetcode 2349"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

