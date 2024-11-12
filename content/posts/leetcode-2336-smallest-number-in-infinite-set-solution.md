
+++
authors = ["grid47"]
title = "Leetcode 2336: Smallest Number in Infinite Set"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2336: Smallest Number in Infinite Set in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Design","Heap (Priority Queue)","Ordered Set"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2336.md" >}}
---
{{< youtube _gGX_2ZNa2E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2337: Move Pieces to Obtain a String](https://grid47.xyz/posts/leetcode-2337-move-pieces-to-obtain-a-string-solution/) |
| --- |
