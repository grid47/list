
+++
authors = ["grid47"]
title = "Leetcode 525: Contiguous Array"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 525: Contiguous Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp"
youtube = "3dRoRxipjhY"
youtube_upload_date="2020-04-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3dRoRxipjhY/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp" 
    alt="A sequence where the contiguous subarrays that sum to zero are softly highlighted, glowing as they are identified."
    caption="Solution to LeetCode 525: Contiguous Array Problem"
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
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int score = 0, res = 0;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            score += nums[i]? 1: -1;

            if(score == 0) res = i + 1;
            else {

                if(mp.count(score))
                res = max(res, i - mp[score]);

                if(!mp.count(score)) mp[score] = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given a binary array `nums` containing only 0s and 1s, find the maximum length of a contiguous subarray with an equal number of 0s and 1s.

### Approach

This solution leverages a cumulative "score" approach, where we treat each `0` as `-1` and each `1` as `+1`. By doing this, any subarray with an equal number of 0s and 1s will have a total score of `0`. 

### Code Breakdown (Step by Step)

1. **Initialize Variables**: 

   ```cpp
   int n = nums.size();
   int score = 0, res = 0;
   map<int, int> mp;
   ```

   - `n` stores the size of `nums`.
   - `score` keeps a running total based on the values in `nums` (adding `1` for `1`s and subtracting `1` for `0`s).
   - `res` keeps track of the maximum length of a subarray with an equal number of `0`s and `1`s.
   - `mp` is a map that tracks the first index where each cumulative score was seen.

2. **Iterate Through the Array**:

   ```cpp
   for(int i = 0; i < n; i++) {
       score += nums[i] ? 1 : -1;
   ```

   - Loop through `nums`. For each `1` encountered, increment `score` by `1`; for each `0`, decrement `score` by `1`.
   - This cumulative score helps identify sections of the array where the count of 0s equals the count of 1s.

3. **Check for Balanced Subarrays**:

   ```cpp
   if(score == 0) res = i + 1;
   ```

   - If `score` is `0`, then from the start of the array to the current index `i`, we have an equal count of 0s and 1s. Update `res` to `i + 1` (the entire length so far).

4. **Check Map for Previous Score Occurrences**:

   ```cpp
   if(mp.count(score))
       res = max(res, i - mp[score]);
   ```

   - If `score` has been seen before at a previous index, then the subarray between that index and the current index `i` has an equal count of 0s and 1s. We update `res` to the maximum length found.

5. **Store First Occurrence of Each Score**:

   ```cpp
   if(!mp.count(score)) mp[score] = i;
   ```

   - If `score` hasn’t been seen before, we store it in `mp` with the current index `i`. This ensures that only the first occurrence of each score is stored, which helps maximize the length of any valid subarray found later.

6. **Return the Result**:

   ```cpp
   return res;
   ```

   - The result `res` contains the maximum length of a contiguous subarray with an equal count of 0s and 1s.

### Complexity

- **Time Complexity**: `O(n)`, as we only iterate through `nums` once.
- **Space Complexity**: `O(n)`, due to the usage of the map `mp`, which can store up to `n` entries.

### Conclusion

This solution efficiently solves the problem by converting it into a cumulative score tracking problem. By mapping each score’s first occurrence, we quickly find the longest subarray with an equal number of 0s and 1s. The solution has optimal time and space complexity for handling large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/contiguous-array/description/)

---
{{< youtube 3dRoRxipjhY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
