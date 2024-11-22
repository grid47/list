
+++
authors = ["grid47"]
title = "Leetcode 1674: Minimum Moves to Make Array Complementary"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1674: Minimum Moves to Make Array Complementary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uyV0p6zy9DU"
youtube_upload_date="2020-11-29"
youtube_thumbnail="https://i.ytimg.com/vi/uyV0p6zy9DU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMoves(vector<int>& num, int lmt) {
        int n = num.size();
        vector<int> dp(2*lmt +2,0);
        for(int i = 0; i < n/2; i++) {
            int a = num[i];
            int b = num[n-1-i];
            dp[2] += 2;
            dp[min(a,b)+1] -= 1;
            dp[a+b] -= 1;
            dp[a+b+1] += 1;
            dp[max(a,b) + lmt +1] += 1;
            
            }
        //for(int i = 1; i < n; i++)
           // dp[i] += dp[i - 1];
        
        int cur = 0, res = 2* n;
        for(int i = 2; i < 2 * lmt + 1; i++) {
            cur += dp[i];
            res = min(res, cur);
            }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the minimum number of moves to make all elements of a given array equal, with the added constraint that any element can be increased or decreased to any integer within a specified limit \( lmt \). The goal is to return the least number of moves required to achieve this uniformity across the array elements.

### Approach

To solve this problem efficiently, we can use a technique based on a frequency array (or a difference array) to keep track of the number of moves needed to achieve the target values. The general strategy is to calculate how many moves are needed to make the elements equal to each potential target value, then find the minimum among these calculations. Here's a detailed breakdown of the approach:

1. **Understanding Moves**: Each number can be adjusted to any number within the bounds dictated by the limit \( lmt \). Thus, if we know the sum of two numbers, we can infer the number of moves to adjust them towards that sum.

2. **Use of a Difference Array**: The idea is to maintain a difference array `dp` that helps in calculating how many numbers need to be changed to achieve specific target values. This array will help us efficiently compute the necessary moves without having to loop through the numbers multiple times.

3. **Calculating Required Moves**:
   - For each pair of numbers \( a \) and \( b \) in the array, calculate how many moves it would take to make them equal to various target values.
   - Update the difference array based on the computed ranges.

4. **Cumulative Sum**: After processing all pairs, a cumulative sum of the difference array will provide the number of moves required for each potential target value.

5. **Finding Minimum Moves**: Finally, iterate through the computed moves to find the minimum number of moves required to make all elements equal.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int minMoves(vector<int>& num, int lmt) {
```
- **Class and Method Definition**: We define the class `Solution` and the public method `minMoves`, which takes a vector of integers `num` and an integer `lmt`.

```cpp
        int n = num.size();
        vector<int> dp(2*lmt + 2, 0);
```
- **Initialization**: We store the size of the input array \( n \) and initialize a difference array `dp` of size \( 2 \times lmt + 2 \) with all elements set to zero. This size ensures we can accommodate all potential values.

```cpp
        for(int i = 0; i < n / 2; i++) {
            int a = num[i];
            int b = num[n - 1 - i];
```
- **Iterate Through Pairs**: We loop through half of the array (since we will be looking at pairs) to work with \( a \) and \( b \), which represent the \( i^{th} \) element from the start and the corresponding element from the end of the array.

```cpp
            dp[2] += 2;
            dp[min(a, b) + 1] -= 1;
            dp[a + b] -= 1;
            dp[a + b + 1] += 1;
            dp[max(a, b) + lmt + 1] += 1;
```
- **Updating the Difference Array**:
    - `dp[2] += 2;` increments the move count for making two numbers equal.
    - `dp[min(a, b) + 1] -= 1;` adjusts for the lower bound of moves needed for values below the minimum of \( a \) and \( b \).
    - `dp[a + b] -= 1;` signifies that moving towards \( a + b \) requires one less move.
    - `dp[a + b + 1] += 1;` adjusts the count for values just above \( a + b \).
    - `dp[max(a, b) + lmt + 1] += 1;` accounts for the upper limit of moves needed for values above the maximum of \( a \) and \( b \).

```cpp
        int cur = 0, res = 2 * n;
        for(int i = 2; i < 2 * lmt + 1; i++) {
            cur += dp[i];
            res = min(res, cur);
        }
```
- **Cumulative Count and Result Calculation**:
    - We initialize `cur` to zero and `res` to \( 2n \) (a large number).
    - We iterate through the `dp` array, maintaining a cumulative sum in `cur` and updating `res` to track the minimum moves required across all potential target values.

```cpp
        return res;
    }
};
```
- **Return Result**: Finally, we return the minimum number of moves found.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), where \( n \) is the number of elements in `num`. We make a single pass through half of the array and then through a fixed-size array \( dp \), leading to linear performance.

- **Space Complexity**: The space complexity is \( O(lmt) \), where \( lmt \) defines the range of possible target values. The difference array `dp` is sized based on this limit.

### Conclusion

The algorithm efficiently calculates the minimum number of moves required to make all elements of an array equal while adhering to a specified limit through the use of a difference array and cumulative sums. The main advantages of this approach include:

- **Efficiency**: The algorithm operates in linear time, making it suitable for large datasets.
- **Clarity**: Using a difference array simplifies the logic behind how moves are computed and accumulated.
- **Versatility**: This method can be easily adapted for other similar problems that require computing minimal transformations across an array.

This approach highlights the power of combining data structures with a mathematical understanding of ranges and sums to solve optimization problems effectively. The algorithm strikes a balance between performance and readability, making it an excellent solution for the given problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

---
{{< youtube uyV0p6zy9DU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
