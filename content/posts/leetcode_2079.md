
+++
authors = ["Yasir"]
title = "Leetcode 2079: Watering Plants"
date = "2019-02-19"
description = "Solution to Leetcode 2079"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/watering-plants/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int wateringPlants(vector<int>& num, int cap) {
        int n = num.size();
        int rel = cap;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(num[i] > rel) {
                rel = cap;
                res += 2*i;
            } 
            rel -= num[i];            
        }
        return res + n;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

