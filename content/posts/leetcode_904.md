
+++
authors = ["Yasir"]
title = "Leetcode 904: Fruit Into Baskets"
date = "2022-05-08"
description = "Solution to Leetcode 904"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fruit-into-baskets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // longest len of sub arr with at most two elements
        map<int, int> mp;
        int j = 0, res = 0, dst = 0;
        
        for(int i = 0; i < fruits.size(); i++) {
            mp[fruits[i]]++;
            if(mp[fruits[i]] == 1) dst++;

            if(dst <= 2) res = max(res, i - j + 1);

            while(dst > 2 && j < i) {
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0) dst--;
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

