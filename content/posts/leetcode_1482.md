
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1482: Minimum Number of Days to Make m Bouquets"
date = "2020-10-09"
description = "Solution to Leetcode 1482"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isValid(vector<int> &bloom, int m, int mid, int k) {
        int bough = 0, cnt = 0;
        
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] > mid) {
                cnt = 0;
            } else if(++cnt >= k) {
                cnt = 0;
                bough++;
            }
        }
        if(bough >= m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)m * k > n) return -1;
        
        int l = 1, r = (int) 1e9, result;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(bloom, m, mid, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
