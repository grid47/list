
+++
authors = ["grid47"]
title = "Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day?"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1744: Can You Eat Your Favorite Candy on Your Favorite Day? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "F4JpJIntzbQ"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/F4JpJIntzbQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> canEat(vector<int>& nums, vector<vector<int>>& q) {
        typedef long long ll;
        vector<ll> cnt(nums.size() +1, 0);
        
        for(int i = 1; i < nums.size() +1; i++)
            cnt[i] += cnt[i - 1] + nums[i -1];
        
        vector<bool> res;
        for(auto & v : q) {
            ll type = v[0], day = v[1], cap = v[2];
            ll mn = cnt[type] / cap;
            ll mx = cnt[type + 1] - 1;

if (mn <= day && day <= mx) {
    res.push_back(true); }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array `nums` where `nums[i]` represents the number of candies of type `i`, and a list of queries `q`. Each query `q[i]` has three values `[type, day, cap]`, which asks if it is possible to eat a candy of type `type` on day `day` while consuming at most `cap` candies each day. The goal is to determine whether each query is feasible based on the candy consumption limits.

### Approach

To solve this, a prefix sum array `cnt` is used to store cumulative counts of candies available up to each type. This allows for quickly determining the minimum and maximum range of days when a candy of a specific type can be eaten.

For each query, given `type`, `day`, and `cap`, we:
1. Calculate the minimum possible day (`mn`) and maximum possible day (`mx`) when a candy of the given type can be consumed.
2. Check if the specified `day` falls within this range (`mn <= day <= mx`).
3. If so, return `true` for that query; otherwise, return `false`.

### Code Breakdown (Step by Step)

Let’s walk through the code in detail.

1. **Prefix Sum Calculation**:
   - Initialize a prefix sum array `cnt` of size `nums.size() + 1`.
   - Populate `cnt` such that `cnt[i]` represents the cumulative number of candies from type `0` to `i-1`.

   ```cpp
   typedef long long ll;
   vector<ll> cnt(nums.size() + 1, 0);
   for(int i = 1; i < nums.size() + 1; i++)
       cnt[i] += cnt[i - 1] + nums[i - 1];
   ```

   This ensures that `cnt[type]` gives the total number of candies available before type `type`, and `cnt[type + 1]` gives the cumulative count up to the next type.

2. **Processing Each Query**:
   - For each query `v`, calculate:
     - `type`: the type of candy in question.
     - `day`: the specific day on which we wish to eat the candy.
     - `cap`: the maximum number of candies that can be eaten per day.
   
   ```cpp
   vector<bool> res;
   for(auto & v : q) {
       ll type = v[0], day = v[1], cap = v[2];
       ll mn = cnt[type] / cap;
       ll mx = cnt[type + 1] - 1;
   ```

   - Calculate `mn`, the minimum possible day by dividing the cumulative candies up to `type` by the daily limit `cap`.
   - Calculate `mx`, the maximum possible day by finding the last day before reaching the next type's candies.

3. **Checking Feasibility**:
   - If `mn <= day <= mx`, it’s possible to eat a candy of the given type on `day` under the constraints, so `true` is added to `res`. Otherwise, `false` is added.

   ```cpp
   if (mn <= day && day <= mx) {
       res.push_back(true); 
   } else {
       res.push_back(false);
   }
   ```

4. **Returning the Result**:
   - The vector `res`, which holds the boolean results for each query, is returned.

   ```cpp
   return res;
   ```

### Complexity

- **Time Complexity**: \(O(N + Q)\), where \(N\) is the length of `nums` and \(Q\) is the number of queries. The prefix sum takes \(O(N)\), and each query check takes \(O(1)\), resulting in \(O(N + Q)\).
  
- **Space Complexity**: \(O(N + Q)\) for storing the prefix sums and results of each query.

### Conclusion

This solution efficiently checks the feasibility of each query by leveraging prefix sums for quick cumulative candy counts. This approach provides optimal performance with minimal computation per query, making it well-suited for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/)

---
{{< youtube F4JpJIntzbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
