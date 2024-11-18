
+++
authors = ["grid47"]
title = "Leetcode 735: Asteroid Collision"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 735: Asteroid Collision in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/735.webp"
youtube = "LN7KjRszjk4"
youtube_upload_date="2021-02-10"
youtube_thumbnail="https://i.ytimg.com/vi/LN7KjRszjk4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/asteroid-collision/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/735.webp" 
    alt="Asteroids moving in space, where collisions are detected, and the remaining asteroids glow softly after the impact."
    caption="Solution to LeetCode 735: Asteroid Collision Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {

        int dir = 0, n = ast.size();
        vector<int> stk;

        for(int a : ast) {

            bool eq = false;
                while(!stk.empty()                  && 
                      (((double)stk.back()/a) < 0 && a < 0)  && 
                      (abs(stk.back()) < abs(a))) {
                    
           
                    stk.pop_back();
                    
                }
            
 
            
            if(!stk.empty() && (stk.back() == -a && a < 0)) { 

           // cout << stk.back();                
                
                stk.pop_back();                
                
                continue; 
            }

            if (stk.empty() || ((double)stk.back()/a > 0) || ((double)stk.back()/a < 0 && a > 0))
                stk.push_back(a);
            
        }
        return stk;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/735.md" >}}
---
{{< youtube LN7KjRszjk4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #738: Monotone Increasing Digits](https://grid47.xyz/leetcode/solution-738-monotone-increasing-digits/) |
| --- |
