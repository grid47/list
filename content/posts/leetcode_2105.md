
+++
authors = ["Yasir"]
title = "Leetcode 2105: Watering Plants II"
date = "2019-01-23"
description = "Solution to Leetcode 2105"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/watering-plants-ii/description/)

---

**Code:**

{{< highlight html >}}
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

