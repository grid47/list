
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1870: Minimum Speed to Arrive on Time"
date = "2019-09-17"
description = "Solution to Leetcode 1870"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool canReach(int speed, vector<int>& dist, double hour) {
        
        double est = 0;
        
        for(int i = 0; i < dist.size(); i++) {
            if(i == (dist.size() - 1)) est += (double)dist[i]/ speed; 
            else est = ceil(est + (double)dist[i]/ speed);
        }
        // cout << speed << " " << est << " " << (est <= hour) << "\n";
        return est <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 0, r = INT_MAX - 1;
        
        int ans = INT_MAX;
        
        while(l <= r) {
            int speed = l + (r - l + 1)/2;
            
            if(canReach(speed, dist, hour)) {
                ans = speed;
                r = speed - 1;
            } else {
                l = speed + 1;
            }
        }
        return ans == INT_MAX? -1: ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
