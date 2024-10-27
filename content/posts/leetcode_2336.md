
+++
authors = ["Yasir"]
title = "Leetcode 2336: Smallest Number in Infinite Set"
date = "2018-06-06"
description = "Solution to Leetcode 2336"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)

---

**Code:**

{{< highlight html >}}
class SmallestInfiniteSet {
public:
    int cnt = 1;
    set<int> s;
    SmallestInfiniteSet() {
        s.clear();
        cnt = 1;
    }
    
    int popSmallest() {
        if(!s.empty()) {
            int tmp = *s.begin() ;
                s.erase(tmp);
            return tmp;            
        }
        return cnt++;
    }
    
    void addBack(int num) {
        if(num < cnt)
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
{{< /highlight >}}

