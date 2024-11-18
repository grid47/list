
+++
authors = ["grid47"]
title = "Leetcode 1603: Design Parking System"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1603: Design Parking System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Simulation","Counting"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1604: Alert Using Same Key-Card Three or More Times in a One Hour Period](https://grid47.xyz/leetcode/solution-1604-alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/) |
| --- |
