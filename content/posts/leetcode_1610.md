
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1610: Maximum Number of Visible Points"
date = "2020-06-03"
description = "Solution to Leetcode 1610"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-visible-points/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int visiblePoints(vector<vector<int>>& pts, int angle, vector<int>& loc) {
        vector<double> arr;
        int cnt = 0;
        for(auto it: pts) {
            int x2 = it[0], y2 = it[1];
            int x1 = loc[0], y1 = loc[1];
            
            double dx = x2 - x1, dy = y2 - y1;
            
            if(dy == 0 && dx == 0) {
                cnt++;
                continue;
            }
            double ang = atan2(dy, dx) * 180/M_PI;
            // cout << ang << " ";
            arr.push_back(ang);
        }
        // cout<< M_PI;
        
        sort(arr.begin(), arr.end());
        vector<double> tmp(arr.begin(), arr.end());
        // cout << tmp.size() << " " << arr.size();
        for(int i = 0; i < arr.size(); i++)
            tmp.push_back(arr[i] + 360);
        arr = tmp;
        int mx = cnt;
        // cout << tmp.size() << " " << arr.size();        
        int j = 0;
        for(int i = 0; i < arr.size(); i++) {
            // cout << arr[i] << " ";
            while(arr[i] - arr[j] > angle) j++;
            mx = max(mx, cnt + i - j + 1);
        }
        
        return mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
