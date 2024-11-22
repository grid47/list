
+++
authors = ["grid47"]
title = "Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SG7VnKzhfjo"
youtube_upload_date="2021-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/SG7VnKzhfjo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        /* change one element to any other value in one move */
        /* get min diff between max and min value after performing atmost 3 moves */
        if(n < 5) return 0;
        sort(nums.begin(), nums.end());
        
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to minimize the difference between the maximum and minimum values of an array after performing a series of operations. Specifically, we are allowed to change any of the elements in the array up to three times, and our goal is to find the minimum possible difference between the maximum and minimum elements of the array after these changes.

### Approach

To tackle this problem, we can break down the solution into the following steps:

1. **Early Return for Small Arrays**: If the array contains fewer than 5 elements, it is impossible to create a significant difference between the maximum and minimum values through three operations, so we can directly return 0.

2. **Sorting the Array**: By sorting the array, we can easily access the smallest and largest elements. This will allow us to determine how the maximum and minimum values can be adjusted by changing elements.

3. **Consider All Combinations**: Since we can change up to three elements, we need to consider several configurations:
   - Decreasing the three largest elements (and keeping the smallest unchanged).
   - Decreasing the two largest and increasing the smallest.
   - Decreasing the largest and the second-largest, while increasing the two smallest.
   - Increasing the three smallest elements (and keeping the largest unchanged).

4. **Calculate Differences**: For each configuration, calculate the difference between the new maximum and minimum values, and return the minimum of these differences.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minDifference(vector<int>& nums) {
```
- We define a class `Solution` and the method `minDifference`, which takes a vector of integers `nums` as input.

```cpp
        int n = nums.size();
```
- We determine the size of the input array `n`.

```cpp
        /* change one element to any other value in one move */
        /* get min diff between max and min value after performing atmost 3 moves */
        if(n < 5) return 0;
```
- We check if the size of the array is less than 5. If it is, we can directly return 0 because it is impossible to achieve a meaningful difference with so few elements.

```cpp
        sort(nums.begin(), nums.end());
```
- We sort the array `nums` in non-decreasing order. This sorting step allows us to easily access the largest and smallest values in the array.

```cpp
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
```
- We calculate the minimum difference by evaluating four scenarios:
  - `nums[n - 1] - nums[3]`: This corresponds to reducing the three largest values.
  - `nums[n - 2] - nums[2]`: This represents reducing the two largest values while keeping the two smallest.
  - `nums[n - 3] - nums[1]`: Here we reduce the largest and second largest values while keeping the three smallest.
  - `nums[n - 4] - nums[0]`: This considers increasing the three smallest values.
  
- The `min` function takes the minimum of these four computed differences and returns it as the result.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is \(O(n \log n)\) due to the sorting step. The rest of the operations (calculating the differences) are constant time operations, \(O(1)\).

#### Space Complexity
- The space complexity is \(O(1)\) as we are only using a fixed amount of extra space for calculations and not allocating additional structures that scale with input size.

### Conclusion

This solution efficiently computes the minimum possible difference between the maximum and minimum elements of an array after performing a limited number of changes. 

**Key Takeaways**:
- **Sorting**: The solution heavily relies on sorting to easily determine the potential maximum and minimum values after modifications.
- **Combinatorial Logic**: By considering various combinations of which elements to modify, the algorithm ensures that it finds the optimal solution without unnecessary complexity.
- **Edge Cases**: The early return for small arrays demonstrates good handling of edge cases, simplifying the problem and avoiding unnecessary computation.

This algorithm showcases a clean and effective approach to minimizing differences in arrays, leveraging sorting and strategic analysis of possible outcomes based on allowed operations. Such techniques are valuable in competitive programming and algorithm design, where efficiency and clarity are paramount.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

---
{{< youtube SG7VnKzhfjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
