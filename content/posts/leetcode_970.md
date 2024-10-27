
+++
authors = ["Yasir"]
title = "Leetcode 970: Powerful Integers"
date = "2022-03-03"
description = "Solution to Leetcode 970"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powerful-integers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}

