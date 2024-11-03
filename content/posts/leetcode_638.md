
+++
authors = ["Crafted by Me"]
title = "Leetcode 638: Shopping Offers"
date = "2023-02-03"
description = "In-depth solution and explanation for Leetcode 638: Shopping Offers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shopping-offers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<vector<int>, int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp[needs]) return mp[needs];
        int best = calculate(price, needs);
        for(auto &sp: special) {
            sub(needs, sp);
            if(noneg(needs)) {
                int woffer = sp.back() + shoppingOffers(price, special, needs);
                best = min(best, woffer);
            }
            add(needs, sp);
        }        
        return mp[needs] = best;
    }
    
    int calculate(vector<int> &prices, vector<int> &needs) {
        int res = 0;
        for(int i = 0; i < needs.size(); i++) {
            res += (needs[i] * prices[i]);
        }
        return res;        
    }
    void add(vector<int> &needs, vector<int> &sp) {
        for(int i = 0; i < needs.size(); i++) {
            needs[i] += sp[i];
        }     
    }    
    void sub(vector<int> &needs, vector<int> &sp) {
        for(int i = 0; i < needs.size(); i++) {
            needs[i] -= sp[i];
        }
    }
    bool noneg(vector<int> &needs) {
        for(int i = 0; i < needs.size(); i++) {
            if(needs[i] < 0) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/638.md" >}}
---


"| 639: Decode Ways II |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

