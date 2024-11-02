
+++
authors = ["Crafted by Me"]
title = "Leetcode 1603: Design Parking System"
date = "2019-06-13"
description = "Solution to Leetcode 1603"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

