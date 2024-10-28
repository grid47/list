
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1157: Online Majority Element In Subarray"
date = "2021-08-29"
description = "Solution to Leetcode 1157"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/online-majority-element-in-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int, vector<int>> mp;
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        for(int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    int frq(int num, int l, int r) {
        if(!mp.count(num)) return 0;
        auto it = lower_bound(mp[num].begin(), mp[num].end(), l);
        if(it == mp[num].end()) return 0;
        auto it2 = upper_bound(mp[num].begin(), mp[num].end(), r);
        return it2 - it;
    }
    
    int idx(int l, int r) {
        return rand() % (r - l + 1) + l;
    }
    
    int query(int left, int right, int thq) {

        for(int i = 0; i < 20; i++) {
            int num = arr[idx(left, right)];
            if(frq(num, left, right) >= thq)
                return num;
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

