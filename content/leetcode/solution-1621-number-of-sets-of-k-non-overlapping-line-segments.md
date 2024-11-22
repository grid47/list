
+++
authors = ["grid47"]
title = "Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Zl-atHgL8QY"
youtube_upload_date="2020-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/Zl-atHgL8QY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    int mod = (int) 1e9 + 7;
    int memo[1001][1001][2];
    int dp(int idx, int seg, bool startHere) {
        if(seg == 0) return 1;
        if(idx == n) return 0;

        if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
        
        int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
        if(startHere) {
            ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
        } else {
            ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
        }

        return memo[idx][seg][startHere] = ans;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the number of ways to partition a sequence of \( n \) elements into exactly \( k \) non-empty contiguous segments. Each segment must contain at least one element, and the segments must be formed by splitting the sequence without altering the order of the elements.

### Approach

The solution uses a dynamic programming approach with memoization to efficiently compute the number of valid ways to create these segments. Here are the key components of the approach:

1. **State Representation**: We define a recursive function \( dp(idx, seg, startHere) \) where:
   - `idx`: The current index in the sequence.
   - `seg`: The remaining number of segments that need to be formed.
   - `startHere`: A boolean that indicates whether we are starting a new segment at the current index.

2. **Base Cases**:
   - If \( seg = 0 \): This means we have successfully formed all required segments, and we return 1 as a valid configuration.
   - If \( idx = n \): This means we have reached the end of the sequence without forming enough segments, so we return 0.

3. **Memoization**: To optimize performance, we use a memoization table `memo[idx][seg][startHere]` to cache results of subproblems. If a state has been computed before, we can return the cached result instead of recalculating it.

4. **Recurrence Relation**:
   - We can choose to either continue the current segment or start a new segment:
     - **Continue the segment**: We move to the next index with the same number of segments.
     - **Start a new segment**: If we are allowed to start a new segment (i.e., if `startHere` is true), we can choose to start a new segment at the next index.
     - **End the current segment**: If we are not starting a new segment (i.e., if `startHere` is false), we can finish the current segment and decrease the segment count.

5. **Modulo Operation**: Since the number of ways can be very large, we take results modulo \( 10^9 + 7 \).

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the code:

```cpp
class Solution {
public:
    int n;
    int mod = (int) 1e9 + 7;
    int memo[1001][1001][2];
```
- We define a class `Solution` which contains the member variables:
  - `n`: the total number of elements.
  - `mod`: the modulo value.
  - `memo`: a 3D array for memoization, initialized to size [1001][1001][2] to cover all potential states.

```cpp
    int dp(int idx, int seg, bool startHere) {
        if(seg == 0) return 1;
        if(idx == n) return 0;
```
- The `dp` function is defined to take the current index, remaining segments, and a boolean indicating whether we can start a new segment.
- The base cases are checked:
  - If `seg` is zero, return 1 (successful partitioning).
  - If `idx` equals `n`, return 0 (not enough segments formed).

```cpp
        if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
```
- Check if the result for the current state has already been computed and stored in `memo`. If so, return that value.

```cpp
        int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
```
- Recursively call `dp` to continue the current segment by moving to the next index without changing the segment count.

```cpp
        if(startHere) {
            ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
        } else {
            ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
        }
```
- If we are allowed to start a new segment (`startHere` is true), we also explore the possibility of starting a new segment at the next index.
- If we are not starting a new segment (`startHere` is false), we explore the option of ending the current segment and decreasing the segment count.

```cpp
        return memo[idx][seg][startHere] = ans;
    }
```
- Store the computed value in the memoization table and return it.

```cpp
    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true);
    }
};
```
- The `numberOfSets` function initializes the total number of elements, resets the memoization table to -1, and calls the `dp` function starting from index 0 with `k` segments and the ability to start a new segment.

### Complexity

- **Time Complexity**: The time complexity is \( O(n \times k) \), where \( n \) is the number of elements and \( k \) is the number of segments. This is due to the recursive exploration of states combined with memoization.
  
- **Space Complexity**: The space complexity is \( O(n \times k) \) for the memoization table. The function also uses a constant amount of additional space for other variables.

### Conclusion

This solution effectively utilizes dynamic programming to solve the problem of counting the number of ways to partition a sequence into segments. By breaking the problem down into smaller subproblems and leveraging memoization, we achieve an efficient and scalable solution.

**Key Takeaways**:
1. **Dynamic Programming**: This technique is crucial for optimizing problems that involve overlapping subproblems, allowing us to avoid redundant calculations.
2. **Memoization**: Storing previously computed results significantly enhances performance, particularly in recursive algorithms.
3. **Modular Arithmetic**: When dealing with potentially large numbers, applying modular arithmetic ensures results remain manageable and within required bounds.

This approach can be applied to various combinatorial problems involving partitioning and grouping, and understanding the mechanics of state representation and recursive function calls can aid in tackling similar challenges in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/)

---
{{< youtube Zl-atHgL8QY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
