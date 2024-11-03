
+++
authors = ["Crafted by Me"]
title = "Leetcode 2591: Distribute Money to Maximum Children"
date = "2017-09-29"
description = "In-depth solution and explanation for Leetcode 2591: Distribute Money to Maximum Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-money-to-maximum-children/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distMoney(int num, int kid) {
        if(num < kid) return -1;
        int avg = num / kid;
        if(avg > 8) return kid - 1;
        if(avg == 8) {
            if(num % kid == 0) return kid;
            return kid - 1;
        }
        if(avg > 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg == 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg < 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;            
        }
        
        return -1;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2592: Maximize Greatness of an Array](https://grid47.xyz/posts/leetcode_2592) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

