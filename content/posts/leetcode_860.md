
+++
authors = ["Yasir"]
title = "Leetcode 860: Lemonade Change"
date = "2022-06-20"
description = "Solution to Leetcode 860"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lemonade-change/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int x : bills) {
                 if (x == 5) five++;
            else if (x == 10) {
                     if (five > 0) five--, ten++;
                else return false;
            } else {
                     if (five > 0 && ten > 0) five--, ten--;
                else if (five > 2) five -= 3;
                else return false;
            }
        }
        return true;
    }
};
{{< /highlight >}}

