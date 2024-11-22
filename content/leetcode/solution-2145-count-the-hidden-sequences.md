
+++
authors = ["grid47"]
title = "Leetcode 2145: Count the Hidden Sequences"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2145: Count the Hidden Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kEhFfpz-qps"
youtube_upload_date="2022-01-22"
youtube_thumbnail="https://i.ytimg.com/vi/kEhFfpz-qps/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfArrays(vector<int>& diff, long lower, long upper) {
        // last - fist of n + 1 seq
        
        long mn = 0, mx = 0, x = 0;

        for(int k : diff) {
            x += k;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        int sum = mx - mn;
        if (upper - lower < sum)
            return 0;
        else {
            
            return (int)(upper - lower) - sum + 1;
            
        }
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the number of possible arrays that can be constructed given the difference array `diff`, along with specified lower and upper bounds. Each element in `diff` represents the difference between consecutive elements in the original array, and the goal is to find how many valid starting points exist within the given bounds.

### Approach

To solve this problem, we can break it down into the following steps:

1. **Understanding the Difference Array**: The `diff` array represents the differences between consecutive elements of an unknown array. By integrating these differences, we can derive the bounds of the unknown array.

2. **Calculating Minimum and Maximum Values**: By iterating through the `diff` array, we can calculate the cumulative sum of differences. This will help us find the maximum and minimum possible values in the unknown array.

3. **Determining the Valid Range**: Based on the calculated maximum and minimum values, we can then determine the valid range of the starting point of the unknown array. This is done by checking if the range defined by the lower and upper bounds can accommodate the range created by the differences.

4. **Counting Valid Starting Points**: Finally, if the range is valid, we compute the number of valid starting points that would satisfy both the lower and upper bounds of the unknown array.

### Code Breakdown (Step by Step)

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - The class `Solution` is defined, which contains the method to solve the problem.

2. **Number of Arrays Function**:
   ```cpp
   int numberOfArrays(vector<int>& diff, long lower, long upper) {
   ```
   - This function takes three parameters: the `diff` array, and two long integers representing the `lower` and `upper` bounds for the starting point of the original array.

3. **Variable Initialization**:
   ```cpp
   long mn = 0, mx = 0, x = 0;
   ```
   - Three long integers are initialized: `mn` and `mx` to track the minimum and maximum sums, respectively, and `x` to hold the cumulative sum of the differences.

4. **Calculating Cumulative Sums**:
   ```cpp
   for(int k : diff) {
       x += k;
       mx = max(mx, x);
       mn = min(mn, x);
   }
   ```
   - A loop iterates through each element `k` in the `diff` array. The cumulative sum `x` is updated, and the maximum (`mx`) and minimum (`mn`) cumulative sums are tracked.

5. **Determining the Range**:
   ```cpp
   int sum = mx - mn;
   if (upper - lower < sum)
       return 0;
   ```
   - The difference between `mx` and `mn` is calculated and stored in `sum`. If the difference between `upper` and `lower` is less than `sum`, it implies that it is impossible to form any valid array, so the function returns 0.

6. **Counting Valid Starting Points**:
   ```cpp
   else {
       return (int)(upper - lower) - sum + 1;
   }
   ```
   - If the range is valid, the number of valid starting points is calculated as the difference between `upper` and `lower`, adjusted for the calculated `sum`, and returned as an integer.

7. **End of Class**:
   ```cpp
   };
   ```
   - This closing brace signifies the end of the `Solution` class.

### Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of elements in the `diff` array.
  - The algorithm iterates through the `diff` array once to compute the cumulative sums, which is linear in time complexity.

- **Space Complexity**: \(O(1)\)
  - The algorithm uses a constant amount of additional space for variables, regardless of the size of the input.

### Conclusion

The `numberOfArrays` function effectively calculates the number of valid arrays that can be formed based on the provided difference array and specified bounds. 

The approach relies on cumulative sum calculations to derive the minimum and maximum possible values, followed by a straightforward check to determine the validity of potential starting points. This solution is both efficient and easy to understand, making it an excellent example of how to work with difference arrays and constraints in algorithm design.

Understanding this method not only helps in solving similar problems involving differences and boundaries but also reinforces concepts related to cumulative sums and range queries in array manipulation. Mastery of these techniques is invaluable in competitive programming and algorithmic challenges, enhancing your problem-solving skills significantly.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-hidden-sequences/description/)

---
{{< youtube kEhFfpz-qps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
