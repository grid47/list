
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2358: Maximum Number of Groups Entering a Competition"
date = "2018-05-16"
description = "Solution to Leetcode 2358"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGroups(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int cur_people = 1;
        int cur_grade  = nums[0];
        int tmp_people = 0;
        int tmp_grade = 0;
        int total = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(tmp_people <= cur_people || tmp_grade <= cur_grade) {
                tmp_grade += nums[i];
                tmp_people += 1;
            } else {
                total += 1;
                cur_people = tmp_people;
                cur_grade = tmp_grade;
                tmp_people = 1;
                tmp_grade = nums[i];
            }
        }
        return (tmp_people > cur_people && tmp_grade > cur_grade)? total + 1: total;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

