
+++
authors = ["Crafted by Me"]
title = "Leetcode 2069: Walking Robot Simulation II"
date = "2019-03-04"
description = "Solution to Leetcode 2069"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

