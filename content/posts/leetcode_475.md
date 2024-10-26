
+++
authors = ["Yasir"]
title = "Leetcode 475: Heaters"
date = "2023-07-10"
description = "Solution to Leetcode 475"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/heaters/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findRadius(vector<int>& home, vector<int>& warm) {
        sort(home.begin(), home.end());
        sort(warm.begin(), warm.end());
        int m = home.size(), n = warm.size();
        
        vector<int> res(m, INT_MAX);
        
        for(int h = 0, w = 0; h < m && w < n; ) {
            if (home[h] <= warm[w]) {
                res[h] = warm[w] - home[h];
                h++;
            } else w++;
        }
        
        for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
            if (home[h] >= warm[w]) {
                res[h] = min(res[h], home[h] - warm[w]);
                h--;
            } else w--;
        }
        
        return *max_element(res.begin(), res.end());
    }
};
{{< /highlight >}}

