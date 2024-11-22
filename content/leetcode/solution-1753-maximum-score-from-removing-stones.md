
+++
authors = ["grid47"]
title = "Leetcode 1753: Maximum Score From Removing Stones"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1753: Maximum Score From Removing Stones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PfcEkLJ725o"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PfcEkLJ725o/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // a > b > c
        if(a < b)
        return maximumScore(b, a, c);
        if(b < c)
        return maximumScore(a, c, b);

        return b == 0? 0 : 1 + maximumScore(a - 1, b - 1, c);
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to calculate the maximum score obtainable by repeatedly performing a specific operation on three integers \(a\), \(b\), and \(c\). The operation consists of selecting two of the three integers (let's say \(a\) and \(b\)), reducing both of them by 1, and adding 1 to the score. This process continues until it is no longer possible to perform the operation, meaning at least one of the integers becomes zero.

### Approach

To tackle this problem, the solution relies on a recursive approach that ensures we always work with the integers in a specific order, specifically ensuring \(a \geq b \geq c\) throughout the calculations. The core idea is to recursively reduce the counts of the two largest integers until one of them reaches zero. The steps can be outlined as follows:

1. **Ordering the Integers**: If the integers are not in the desired order (\(a\), \(b\), and \(c\)), we swap them to ensure the largest integer is always first.

2. **Base Case**: If the second largest integer \(b\) is zero, no further operations can be performed, and the score is zero.

3. **Recursive Case**: If both \(a\) and \(b\) are greater than zero, we can perform the operation, reducing both by one and incrementing the score by one, followed by a recursive call to continue the process.

### Code Breakdown (Step by Step)

Here’s a step-by-step breakdown of the implementation in the `maximumScore` function:

1. **Class Definition**: The function is defined within a class called `Solution`.

   ```cpp
   class Solution {
   ```

2. **Public Method**: The `maximumScore` method takes three integers as input and returns the maximum score achievable.

   ```cpp
   public:
       int maximumScore(int a, int b, int c) {
   ```

3. **Ordering the Integers**: The first conditional checks if \(a\) is less than \(b\) and swaps their values if necessary. This ensures that \(a\) is always the largest.

   ```cpp
   if(a < b)
       return maximumScore(b, a, c);
   ```

4. **Further Ordering**: The second conditional checks if \(b\) is less than \(c\) and swaps their values accordingly to maintain the order \(a \geq b \geq c\).

   ```cpp
   if(b < c)
       return maximumScore(a, c, b);
   ```

5. **Base Case**: If \(b\) is zero, this means no more operations can be performed, and the score is zero.

   ```cpp
   return b == 0 ? 0 : 1 + maximumScore(a - 1, b - 1, c);
   ```

6. **Recursive Call**: If the base case is not reached, the function proceeds to reduce both \(a\) and \(b\) by one and adds one to the score, recursively calling `maximumScore` with the new values.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(a + b + c)\) in the worst case because each recursive call reduces at least one of the integers \(a\) or \(b\) by one, leading to a total of at most \(a + b\) recursive calls until one of them reaches zero.

- **Space Complexity**: The space complexity is \(O(h)\), where \(h\) is the height of the recursion stack. In the worst case, this could also be \(O(a + b + c)\) if the recursion goes deep without hitting a base case.

### Conclusion

In conclusion, this solution provides an elegant way to compute the maximum score achievable by reducing the two largest integers among three given integers through a series of operations. The recursive approach ensures that the calculations remain straightforward and efficient by maintaining the order of the integers. Additionally, this method handles various input scenarios, including cases where one or more integers may initially be zero. Overall, the algorithm effectively demonstrates how recursion can be utilized to simplify problems involving iterative reductions, making it a valuable technique in both competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-score-from-removing-stones/description/)

---
{{< youtube PfcEkLJ725o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
