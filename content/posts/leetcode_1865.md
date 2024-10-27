
+++
authors = ["Yasir"]
title = "Leetcode 1865: Finding Pairs With a Certain Sum"
date = "2019-09-20"
description = "Solution to Leetcode 1865"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/)

---

**Code:**

{{< highlight html >}}
class FindSumPairs {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> mtx;
    map<int, int> mp;
    int m, n;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums2.size(), n = nums1.size();
        for(int i = 0; i < nums2.size(); i++) {
                mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int key = nums2[index];
        nums2[index] += val;
        mp[key]--;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += mp[tot - nums1[i]];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
{{< /highlight >}}

