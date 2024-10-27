
+++
authors = ["Yasir"]
title = "Leetcode 1362: Closest Divisors"
date = "2021-02-04"
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

{{< highlight html >}}
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

