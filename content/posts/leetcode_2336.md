
+++
authors = ["Crafted by Me"]
title = "Leetcode 2336: Smallest Number in Infinite Set"
date = "2018-06-11"
description = "In-depth solution and explanation for Leetcode 2336: Smallest Number in Infinite Set in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


"| 2337: Move Pieces to Obtain a String |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

