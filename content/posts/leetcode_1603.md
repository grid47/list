
+++
authors = ["Crafted by Me"]
title = "Leetcode 1603: Design Parking System"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1603: Design Parking System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-parking-system/description/)

---

**Code:**

{{< highlight cpp >}}
class ParkingSystem {
public:
    int bm, mm, sm;
    int bc, mc, sc;    
    ParkingSystem(int big, int medium, int small) {
        bm = big;
        mm = medium;
        sm = small;
        bc = 0;
        mc = 0;
        sc = 0;
    }
    
    bool addCar(int ct) {
        switch(ct) {
            case 1:
                if(bc < bm) {
                    bc++;
                    return true;
                }
                break;
            case 2:
                if(mc < mm) {
                    mc++;
                    return true;
                }                
                break;
            case 3:
                if(sc < sm) {
                    sc++;
                    return true;
                }
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1603.md" >}}
---
{{< youtube d5zCHesOrSk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1604: Alert Using Same Key-Card Three or More Times in a One Hour Period](https://grid47.xyz/posts/leetcode_1604) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

