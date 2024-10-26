
+++
authors = ["Yasir"]
title = "Leetcode 457: Circular Array Loop"
date = "2023-07-28"
description = "Solution to Leetcode 457"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-array-loop/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;

            int j = i, k = getIdx(i, nums);
            while(nums[k] * nums[i] > 0 && nums[getIdx(k, nums)] * nums[i] > 0) {
                if(j == k) {
                    if(j == getIdx(j, nums)) break;
                    return true;
                }
                j = getIdx(j, nums);
                k = getIdx(getIdx(k, nums), nums);
            }

            j = i;
            int val = nums[i];
            while(nums[j] * val > 0) {
                int next = getIdx(j, nums);
                nums[j] = 0;
                j = next;
            }
        }
        return false;
    }

    int getIdx(int i, vector<int> &nums) {
        int n = nums.size();
        return i + nums[i] >= 0? (i + nums[i]) % n: n + ((i + nums[i]) % n);
    }
};
{{< /highlight >}}

