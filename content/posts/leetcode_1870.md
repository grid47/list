
+++
authors = ["Crafted by Me"]
title = "Leetcode 1870: Minimum Speed to Arrive on Time"
date = "2019-09-20"
description = "In-depth solution and explanation for Leetcode 1870: Minimum Speed to Arrive on Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1870.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1871: Jump Game VII](https://grid47.xyz/posts/leetcode_1871) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

