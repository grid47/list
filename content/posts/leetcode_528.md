
+++
authors = ["Yasir"]
title = "Leetcode 528: Random Pick with Weight"
date = "2023-05-18"
description = "Solution to Leetcode 528"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-pick-with-weight/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    vector<int> wc;
    public:
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i = 1; i < n; i++)
            w[i] += w[i - 1];
        wc = w;
    }
    
    int pickIndex() {
        
        int x = rand() % wc.back()+1;//[(wc.size() - 1)];        
        int l = 0, r = wc.size() - 1;
    
        while(l < r) {

            int mid = l + (r - l) / 2;            
            if(wc[mid] == x) return mid;

            if(wc[mid] < x) l = mid + 1;
            else            r = mid;
        
        }
        
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
{{< /highlight >}}

