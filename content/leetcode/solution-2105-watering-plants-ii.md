
+++
authors = ["grid47"]
title = "Leetcode 2105: Watering Plants II"
date = "2024-04-10"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2108: Find First Palindromic String in the Array](https://grid47.xyz/leetcode/solution-2108-find-first-palindromic-string-in-the-array/) |
| --- |
