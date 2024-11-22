
+++
authors = ["grid47"]
title = "Leetcode 1646: Get Maximum in Generated Array"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1646: Get Maximum in Generated Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "dy15GcCBdOc"
youtube_upload_date="2020-11-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/dy15GcCBdOc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    public int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        int max = 1;
        for(int i = 1; 2 * i + 1 < n + 1; i++) {
            nums[2 * i]     = nums[i];
            max = Math.max(nums[2 * i],     max);
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            max = Math.max(nums[2 * i + 1], max);
        }
        return max;
    }
}
{{< /highlight >}}
---

### Problem Statement

The task is to generate a sequence of numbers based on the input integer \( n \) and find the maximum number in that sequence. The sequence is defined as follows:

- \( nums[0] = 0 \)
- \( nums[1] = 1 \)
- For each integer \( i \) starting from 1, the following rules apply:
  - \( nums[2 \times i] = nums[i] \)
  - \( nums[2 \times i + 1] = nums[i] + nums[i + 1] \)

Your goal is to compute the maximum value in the generated sequence up to index \( n \).

### Approach

To solve this problem, we can take the following steps:

1. **Initialization**: Create an array `nums` to store the values of the sequence up to the \( n \)th index.

2. **Base Cases**: Set the base values \( nums[0] \) and \( nums[1] \).

3. **Iterative Calculation**: Use a loop to calculate values for even and odd indices based on the rules specified above. Maintain a variable to track the maximum value encountered in the process.

4. **Return the Result**: Finally, return the maximum value found in the array.

### Code Breakdown (Step by Step)

Let’s go through the provided code to explain how it works:

```java
class Solution {
    public int getMaximumGenerated(int n) {
```
- We define a class `Solution` and a public method `getMaximumGenerated` that takes an integer \( n \) as input.

```java
        if (n == 0) return 0;
```
- If \( n \) is 0, we immediately return 0 since that is the only element in the generated sequence.

```java
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
```
- We create an array `nums` of size \( n + 1 \) to store the sequence values. We initialize the first two values of the array according to the defined rules.

```java
        int max = 1;
```
- We initialize a variable `max` to keep track of the maximum value found in the sequence. Since \( nums[1] \) is initialized to 1, we start with `max` as 1.

```java
        for(int i = 1; 2 * i + 1 < n + 1; i++) {
```
- We use a `for` loop to iterate through the indices. The loop continues until \( 2 \times i + 1 \) exceeds \( n \), ensuring that we stay within the bounds of the array.

```java
            nums[2 * i]     = nums[i];
            max = Math.max(nums[2 * i],     max);
```
- For each \( i \), we calculate the value for the even index \( 2 \times i \) by assigning it the value of \( nums[i] \). We also update `max` if this new value is greater than the current maximum.

```java
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            max = Math.max(nums[2 * i + 1], max);
```
- Next, we calculate the value for the odd index \( 2 \times i + 1 \) by summing \( nums[i] \) and \( nums[i + 1] \). Again, we update `max` if the newly calculated value exceeds the current maximum.

```java
        }
        return max;
    }
}
```
- The loop continues until all applicable indices are calculated, and finally, we return the maximum value found in the sequence.

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \). This is because we are iterating through the array of size \( n \) and performing a constant amount of work for each index.

- **Space Complexity**: The space complexity is also \( O(n) \) due to the additional array `nums` that stores the generated sequence values.

### Conclusion

This solution effectively generates a sequence of numbers based on the specified rules and determines the maximum value in a single pass through the sequence. 

**Key Points**:
1. **Dynamic Programming Insight**: The approach leverages the properties of dynamic programming by building up the solution iteratively from smaller subproblems (previous indices) to solve for larger ones (the current index).
2. **Efficiency**: The algorithm efficiently computes the maximum value in linear time, making it suitable for larger inputs within practical limits.
3. **Clarity**: The separation of logic into distinct steps (initialization, calculation, and result retrieval) enhances code clarity and maintainability.

This method can serve as a foundational example for solving similar problems that involve generating sequences based on mathematical rules, allowing for intuitive expansions and adaptations for more complex scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/get-maximum-in-generated-array/description/)

---
{{< youtube dy15GcCBdOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
