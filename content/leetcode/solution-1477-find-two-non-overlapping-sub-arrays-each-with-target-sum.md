
+++
authors = ["grid47"]
title = "Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uV_JsPPLK9o"
youtube_upload_date="2020-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uV_JsPPLK9o/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        int sum = 0, lsize = INT_MAX, result = INT_MAX;
        mp[0] = -1;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            mp[sum] = i;
        }
        sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(mp.count(sum - target)) 
            lsize = min(lsize, i - mp[sum-target]);

            if(mp.count(sum + target) && lsize < INT_MAX)
            result = min(result, mp[sum + target] -i +lsize);


        }

        return result == INT_MAX ? -1: result;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the minimum sum of the lengths of two non-overlapping subarrays in a given array `arr` such that the sum of each subarray equals a specified `target`. A subarray is defined as a contiguous portion of the array, and the lengths of the subarrays should not overlap.

### Approach

To solve this problem efficiently, we can use a combination of prefix sums and a hash map (unordered_map) to keep track of previously encountered sums. The overall approach can be broken down into the following key steps:

1. **Calculate Prefix Sums**: Traverse through the array while maintaining a cumulative sum, storing the last index where each cumulative sum is found in a hash map.

2. **Find Valid Subarrays**: For each index in the array, check if a subarray that sums to `target` can be formed using the previously stored sums in the hash map. This requires checking if the difference between the current sum and the `target` exists in the map.

3. **Update Minimum Lengths**: Whenever a valid subarray that sums to `target` is found, update the minimum length of the previously found subarray if it allows for a non-overlapping combination.

4. **Compute the Result**: Finally, compute the minimum sum of lengths of the two non-overlapping subarrays. If no valid combination is found, return -1.

### Code Breakdown (Step by Step)

Let's break down the provided code in detail:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - This starts the definition of the `Solution` class, which will contain our main logic.

2. **Method Declaration**:
   ```cpp
   int minSumOfLengths(vector<int>& arr, int target) {
   ```
   - The method `minSumOfLengths` is defined, which takes a vector of integers `arr` and an integer `target` as input parameters.

3. **Variable Initialization**:
   ```cpp
   unordered_map<int, int> mp;
   int sum = 0, lsize = INT_MAX, result = INT_MAX;
   mp[0] = -1;
   ```
   - An unordered map `mp` is initialized to store cumulative sums and their corresponding indices.
   - The variable `sum` is initialized to accumulate the sum as we iterate through the array.
   - `lsize` keeps track of the length of the last found valid subarray that sums to `target`, initialized to a large value (`INT_MAX`).
   - `result` will store the minimum sum of lengths of the two valid subarrays, also initialized to `INT_MAX`.
   - The entry `mp[0] = -1` is set to handle cases where a valid subarray starts from index 0.

4. **First Pass - Populate Prefix Sums**:
   ```cpp
   for(int i = 0; i < arr.size(); i++) {
       sum += arr[i];
       mp[sum] = i;
   }
   ```
   - This loop iterates over the `arr` array, updating the cumulative `sum` and storing it in the map `mp` with the current index `i`.

5. **Second Pass - Find Valid Subarrays**:
   ```cpp
   sum = 0;
   for(int i = 0; i < arr.size(); i++) {
       sum += arr[i];
       if(mp.count(sum - target)) 
           lsize = min(lsize, i - mp[sum-target]);
   ```
   - Here, we reset `sum` and start a new loop through `arr`. We again accumulate the `sum` for each index.
   - We check if the difference `sum - target` exists in the map `mp`. If it does, it means we have found a valid subarray, and we update `lsize` with the minimum length.

6. **Update the Result**:
   ```cpp
       if(mp.count(sum + target) && lsize < INT_MAX)
           result = min(result, mp[sum + target] -i + lsize);
   ```
   - Next, we check if `sum + target` exists in the map. If it does and `lsize` is valid (not `INT_MAX`), we update `result` with the minimum of the current `result` and the sum of the lengths of the two valid subarrays.

7. **Return the Result**:
   ```cpp
   return result == INT_MAX ? -1 : result;
   }
   ```
   - Finally, we check if `result` is still `INT_MAX`. If it is, it indicates that no valid combination was found, so we return -1. Otherwise, we return the computed `result`.

### Complexity

- **Time Complexity**:
  - The overall time complexity is \(O(n)\), where \(n\) is the length of the input array `arr`. This is due to the fact that each pass through the array (two passes in total) takes linear time, and hash map operations (insert and lookup) average to \(O(1)\).

- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the storage of the cumulative sums in the hash map. In the worst case, all sums could be unique and require space proportional to the length of the array.

### Conclusion

The `minSumOfLengths` method efficiently finds the minimum sum of lengths of two non-overlapping subarrays that each sum to a given target. The use of prefix sums combined with a hash map allows for a linear time solution, making it suitable for larger inputs.

Key takeaways from this implementation include:

1. **Efficiency**: The use of a hash map for quick lookups drastically reduces the time complexity compared to a naive approach that might involve nested loops.

2. **Simplicity**: The code is structured in a way that is easy to follow, with clear variable naming and logical segmentation of the steps.

3. **Versatility**: The approach can be adapted for similar problems that involve subarray sums and constraints, showcasing the utility of prefix sums in competitive programming and algorithm design.

In summary, this solution serves as an excellent example of optimizing problems involving sums of subarrays, demonstrating effective use of data structures for enhanced performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

---
{{< youtube uV_JsPPLK9o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
