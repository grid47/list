
+++
authors = ["Crafted by Me"]
title = "Leetcode 2531: Make Number of Distinct Characters Equal"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2531: Make Number of Distinct Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isItPossible(string w1, string w2) {
        
        map<char, int> ma1, ma2;
        for(int x: w1)
            ma1[x]++;
        for(int x: w2)
            ma2[x]++;
        
        for(auto it1: ma1) {
            for(auto it2: ma2) {
                map<char, int> d1 = ma1, d2 = ma2;
                d1[it2.first]++;
                d2[it1.first]++;
                
                d1[it1.first]--;
                d2[it2.first]--;
                
                if(d1[it1.first] == 0)
                    d1.erase(it1.first);
                if(d2[it2.first] == 0)
                    d2.erase(it2.first);
                
                if(d1.size() == d2.size()) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}


---
{{< youtube MoYeUVe-xPY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2532: Time to Cross a Bridge](https://grid47.xyz/posts/leetcode_2532) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

