
+++
authors = ["grid47"]
title = "Leetcode 2069: Walking Robot Simulation II"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2069: Walking Robot Simulation II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "10111CfY7GQ"
youtube_upload_date="2021-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/10111CfY7GQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/walking-robot-simulation-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Robot {
public:
    int w, h, i, j, dir, per;
    Robot(int width, int height) {
        w = width;
        h = height;
        i = 0;
        j = 0;
        dir = 0;
        per = 2 * (w + h - 2);
    }
    
    void step(int num) {
        if(num > per) {
            num %= per;
            if(i == 0 && j == 0 && dir == 0) dir = 3;
        }
        int mo[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(num) {
            int x = i + mo[dir][0], y = j + mo[dir][1];
            if(x >= w || y >= h || x < 0 || y < 0) {
                dir = (dir + 1) % 4;
            } else {
                i = x;
                j = y;
                num--;
            }
        }
        
    }
    
    vector<int> getPos() {
        return {i, j};
    }
    
    string getDir() {
        switch(dir) {
            case 0: return "East"   ; break;
            case 1: return "North"  ; break;    
            case 2: return "West"   ; break;    
            case 3: return "South"  ; break;
        }
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2069.md" >}}
---
{{< youtube 10111CfY7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2070: Most Beautiful Item for Each Query](https://grid47.xyz/leetcode/solution-2070-most-beautiful-item-for-each-query/) |
| --- |