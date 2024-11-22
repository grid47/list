
+++
authors = ["grid47"]
title = "Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R8geTAz_yk8"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R8geTAz_yk8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length()); 
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves a string `boxes` consisting of '0's and '1's, where each character represents a box that may or may not contain a ball. The goal is to determine the minimum number of operations required to move all balls to each box. An operation consists of moving a ball from one box to another, and the cost of moving a ball is equal to the distance between the boxes. For each box, the output should be an integer indicating the total number of operations needed to move all balls to that specific box.

### Approach

The approach to solve this problem uses a two-pass technique that calculates the total operations needed for each box in a single scan from left to right and then another from right to left. The algorithm can be broken down into the following steps:

1. **Initialization**:
   - Create a result vector `res` initialized to the same length as `boxes`, which will hold the minimum operations for each box.
   - Use two counters: `ops` to track the total operations required and `cnt` to count the number of balls encountered.

2. **First Pass (Left to Right)**:
   - Iterate over each box from left to right.
   - For each box, add the current value of `ops` to the corresponding index in `res`.
   - If the current box contains a ball ('1'), increment `cnt`.
   - Update `ops` by adding the current count of balls to it.

3. **Second Pass (Right to Left)**:
   - Iterate over each box from right to left.
   - Again, add the current value of `ops` to the corresponding index in `res`.
   - Update `cnt` for balls similarly.
   - Update `ops` using the count of balls encountered during this pass.

4. **Return Result**:
   - Finally, return the result vector containing the minimum operations for each box.

This method is efficient as it ensures each box is processed only twice, yielding a linear time complexity relative to the length of the input string.

### Code Breakdown (Step by Step)

Below is a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
```
- The `Solution` class is defined with a public method `minOperations`, which takes a string `boxes` as input.

```cpp
        vector<int> res(boxes.length()); 
```
- A vector `res` is initialized with the same length as `boxes`. This vector will store the result, i.e., the minimum operations needed for each box.

```cpp
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
```
- A for loop begins to traverse `boxes` from the beginning to the end.
- Two variables are initialized: `ops` to track total operations and `cnt` to count the number of balls encountered.

```cpp
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
```
- For each box, the current value of `ops` is added to `res[i]`, which accounts for the operations needed to bring balls from all previous boxes to the current box.
- The count of balls (`cnt`) is updated; if the current box contains a ball ('1'), it increments by 1.
- `ops` is then updated by adding the current count of balls, which reflects the cumulative cost of moving all encountered balls to the current box.

```cpp
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
```
- A second for loop begins to traverse `boxes` from the end to the beginning.
- The same approach is applied as in the first pass, but this time calculating the operations needed to move balls from boxes to the left.

```cpp
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
```
- The operations from the second pass are also added to `res[i]`, further refining the total operations required to bring all balls to the current box from both sides.

```cpp
        return res;
    }
};
```
- Finally, the method returns the `res` vector, which contains the minimum operations needed for each box.

### Complexity

- **Time Complexity**: The overall time complexity is \(O(n)\), where \(n\) is the length of the `boxes` string. This is because each box is processed in two separate passes over the string.

- **Space Complexity**: The space complexity is \(O(n)\) due to the storage of the result vector `res`, which has the same length as the input string.

### Conclusion

The `minOperations` method efficiently computes the minimum number of operations required to move all balls to each box in a string representation. By employing a two-pass approach, it successfully accumulates the operations from both directions, ensuring a linear time complexity that is optimal for this problem.

This solution not only solves the problem efficiently but also demonstrates the power of using counters and cumulative sums in algorithm design. It can be applied in various scenarios where similar optimization problems exist, making it a valuable technique in algorithm development.

In summary, the implementation provided offers a clear, concise, and efficient way to tackle the task at hand, making it suitable for competitive programming and practical software applications alike. Understanding this method enhances one's problem-solving toolkit, especially for string manipulation and optimization challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

---
{{< youtube R8geTAz_yk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
