
+++
authors = ["Yasir"]
title = "Leetcode 765: Couples Holding Hands"
date = "2022-09-24"
description = "Solution to Leetcode 765"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/couples-holding-hands/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size();
        
        vector<int> pos(n, 0);
        vector<int> ptn(n, 0);
        
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
            ptn[i] = (i % 2 == 0) ? i + 1 : i - 1;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = ptn[pos[ptn[row[i]]]]; j != i; j = ptn[pos[ptn[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

