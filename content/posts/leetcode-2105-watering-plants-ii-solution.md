
+++
authors = ["grid47"]
title = "Leetcode 2105: Watering Plants II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2105: Watering Plants II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/watering-plants-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumRefill(vector<int>& plant, int capA, int capB) {
        int n = plant.size();
        int i = 0, j = n - 1;
        int cnt = 0;
        
        int alice = capA, bob = capB;
        
        while(i <= j) {
            if(i < j) {
                if(alice >= plant[i]) {
                    alice -= plant[i];
                } else {
                    cnt++;
                    alice = capA;
                    alice -= plant[i];
                }
                i++;
                
                if(bob >= plant[j]) {
                    bob -= plant[j];
                } else {
                    cnt++;
                    bob = capB;
                    bob -= plant[j];
                }
                j--;
            } else {
                if(alice >= bob) {
                    if(alice >= plant[i]) {
                        alice -= plant[i];
                    } else {
                        cnt++;
                        alice = capA;
                        alice -= plant[i];                        
                    }
                } else {
                    if(bob >= plant[i]) {
                        bob -= plant[i];
                    } else {
                        cnt++;
                        bob = capB;
                        bob -= plant[i];                        
                    }                    
                }
                i++, j--;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2105.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2108: Find First Palindromic String in the Array](https://grid47.xyz/posts/leetcode-2105-watering-plants-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
