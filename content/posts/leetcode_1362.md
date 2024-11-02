
+++
authors = ["Crafted by Me"]
title = "Leetcode 1362: Closest Divisors"
date = "2020-02-09"
description = "Solution to Leetcode 1362"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-divisors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> closestDivisors(int num) {
        
        for(int a = sqrt(num + 2); a > 0; a--) {
            if((num + 1) % a == 0) return vector<int>{a, (num + 1) / a};
            if((num + 2) % a == 0) return vector<int>{a, (num + 2) / a};            
        }
        return vector<int>{};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

