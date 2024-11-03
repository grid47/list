
+++
authors = ["Crafted by Me"]
title = "Leetcode 1610: Maximum Number of Visible Points"
date = "2020-06-06"
description = "In-depth solution and explanation for Leetcode 1610: Maximum Number of Visible Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1611: Minimum One Bit Operations to Make Integers Zero](https://grid47.xyz/posts/leetcode_1611) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

