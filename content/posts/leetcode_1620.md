
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1620: Coordinate With Maximum Network Quality"
date = "2020-05-25"
description = "Solution to Leetcode 1620"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& tow, int rad) {
        
        int n = tow.size();
    
        int mx = INT_MIN;
        vector<vector<int>> res;
        
        for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++) {
            
            int sum = 0;
            for(int k = 0; k < n; k++) {
                int x = tow[k][0], y = tow[k][1];
                float r = sqrt((x - i) * (x - i) + (y - j) * (y - j));
                int ss = 0;
                if(r <= rad) {
                    ss = tow[k][2]/(1 + r);
                }
                sum += ss;
            }
            if(mx < sum) {
                mx = sum;
                res = {{i, j}};
            } else if(mx == sum) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

