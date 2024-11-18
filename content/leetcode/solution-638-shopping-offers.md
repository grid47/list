
+++
authors = ["grid47"]
title = "Leetcode 638: Shopping Offers"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 638: Shopping Offers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Memoization","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "t6atP4Yv7_4"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/638.webp"
+++



[`Problem Link`](https://leetcode.com/problems/shopping-offers/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/638.webp" 
    alt="A set of shopping offers with discounts, where each offer is softly glowing based on its value."
    caption="Solution to LeetCode 638: Shopping Offers Problem"
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
{{< youtube t6atP4Yv7_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #640: Solve the Equation](https://grid47.xyz/leetcode/solution-640-solve-the-equation/) |
| --- |
