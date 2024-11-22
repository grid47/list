
+++
authors = ["grid47"]
title = "Leetcode 754: Reach a Number"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 754: Reach a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/754.webp"
youtube = "K8yXBn4cCQs"
youtube_upload_date="2020-12-28"
youtube_thumbnail="https://i.ytimg.com/vi/K8yXBn4cCQs/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/754.webp" 
    alt="A number line where the steps to reach a target number are traced, with each step glowing softly."
    caption="Solution to LeetCode 754: Reach a Number Problem"
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
    int reachNumber(int target) {
        target = abs(target);
        long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
        long long sum = n * (n + 1) / 2;
        if (sum == target) return n;
        long long res = sum - target;
        if((res &1) == 0)   return n;
        else                return n + ((n&1)? 2: 1);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum number of moves required to reach a given target number starting from 0, where in each move, we can either increase or decrease the current number by a step size of 1. The task is to determine the minimum number of moves needed to exactly reach the target, given that each move is either +1 or -1.

The catch here is that the target can be both positive and negative, and the solution should work efficiently without brute-forcing through each step, especially for large numbers.

### Approach

To solve this problem, we can leverage **mathematical insights** rather than iterating step by step. The idea is to recognize that the total distance we cover in `n` steps is the sum of the first `n` natural numbers. This sum can be represented as:

\[
S_n = \frac{n \times (n + 1)}{2}
\]

Where:
- `n` is the number of moves (steps).
- `S_n` is the total distance covered after `n` steps.

Our goal is to find the smallest `n` such that the sum `S_n` is either equal to the target or can be adjusted (through +/- operations) to exactly match the target.

### Key Observations:
1. **Sum of First n Numbers**: The total sum of the first `n` numbers grows quadratically as `n` increases. This can help us estimate how far we need to go in terms of the number of steps required.
  
2. **Adjusting the sum to match the target**:
   - Once we find the sum `S_n` for some `n`, we need to check if we can adjust it to match the target.
   - If `S_n` is exactly equal to the target, we have found the solution.
   - If `S_n` is greater than the target, the difference `S_n - target` must be adjusted. We can achieve this adjustment by flipping the sign of certain steps (i.e., using `-1` instead of `+1` for some of the moves). This difference must be even for such an adjustment to be possible.

3. **Mathematical Derivation**:
   - The formula used to compute `n` comes from solving for `n` in the quadratic equation derived from the sum of the first `n` integers.
   - Once we find the nearest `n`, we compute whether the difference between `S_n` and the target is even or odd. If the difference is even, no further moves are required; otherwise, we need to adjust the number of moves.

### Code Breakdown (Step by Step)

1. **Transform Target to Positive**:
   - First, we take the absolute value of the target. This simplifies the problem, as the behavior for positive and negative targets is symmetric. We don't need to consider the sign of the target in the subsequent calculations.
   ```cpp
   target = abs(target);
   ```

2. **Finding the Minimum n**:
   - We calculate the smallest `n` such that the sum of the first `n` numbers (`S_n`) is greater than or equal to the target. This is done by solving the quadratic equation:
   \[
   n = \lceil \frac{-1 + \sqrt{1 + 8 \times target}}{2} \rceil
   \]
   - The expression above is derived from the formula for the sum of the first `n` natural numbers. Using the `sqrt()` function ensures we are working with a floating-point approximation to get the smallest `n` that satisfies the condition.
   ```cpp
   long long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
   ```

3. **Calculate Sum of First n Numbers**:
   - Once we have `n`, we calculate the sum of the first `n` numbers using the formula:
   \[
   S_n = \frac{n \times (n + 1)}{2}
   \]
   - This sum is the total distance we can cover after `n` steps.
   ```cpp
   long long sum = n * (n + 1) / 2;
   ```

4. **Check if Sum Matches Target**:
   - If the sum of the first `n` numbers exactly equals the target, we return `n` as the result because we’ve found the minimum number of moves needed to reach the target.
   ```cpp
   if (sum == target) return n;
   ```

5. **Handle Adjustment**:
   - If `S_n` is greater than the target, we calculate the difference `res = sum - target`.
   - If this difference is even (`res & 1 == 0`), we can achieve the target by adjusting the signs of the moves. In this case, we return `n`.
   - If the difference is odd, we need one additional move to make the difference even, so we return `n + 1` or `n + 2` depending on whether `n` is odd or even:
   ```cpp
   long long res = sum - target;
   if ((res & 1) == 0) return n;
   else return n + ((n & 1) ? 2 : 1);
   ```

### Complexity Analysis

- **Time Complexity**:
   - The time complexity of the algorithm is **O(1)** since the number of operations involved (square root, division, and modulus checks) is constant. This is an optimal approach, as we don't need to perform iterative steps for large target values.
  
- **Space Complexity**:
   - The space complexity is also **O(1)** because the algorithm uses a constant amount of space to store the variables `n`, `sum`, and `res`.

### Conclusion

This solution efficiently solves the problem by using a mathematical approach rather than brute-forcing through every possible combination of moves. By leveraging the formula for the sum of the first `n` numbers and solving for the smallest `n`, we minimize the number of steps needed to reach the target.

The key insight is that the total distance covered by the first `n` moves grows quadratically, and the target can be adjusted if the difference between the sum and the target is even. This approach is both time-efficient and space-efficient, with constant time and space complexity.

This method ensures that even for large targets, the solution is computed quickly without the need for simulating each individual move. The algorithm effectively handles both positive and negative targets, making it robust and adaptable to various input cases.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reach-a-number/description/)

---
{{< youtube K8yXBn4cCQs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
