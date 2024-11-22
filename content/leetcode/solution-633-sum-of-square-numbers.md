
+++
authors = ["grid47"]
title = "Leetcode 633: Sum of Square Numbers"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 633: Sum of Square Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp"
youtube = "B0UrG_X2faA"
youtube_upload_date="2024-06-17"
youtube_thumbnail="https://i.ytimg.com/vi/B0UrG_X2faA/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/633.webp" 
    alt="A series of squares where the sum of square numbers is calculated and softly glowing as it’s computed."
    caption="Solution to LeetCode 633: Sum of Square Numbers Problem"
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
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long res = left * left + right * right;
            if(res < c)
            left++;
            else if(res > c) 
            right--;
            else return true;
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine whether a given integer `c` can be expressed as the sum of the squares of two non-negative integers. Specifically, the task is to check if there exist two integers `a` and `b` such that:

\[
a^2 + b^2 = c
\]

For example:
- For `c = 5`, the answer is `true` because \( 1^2 + 2^2 = 5 \).
- For `c = 3`, the answer is `false` because no two squares sum up to 3.

### Approach

The approach to solving this problem revolves around using two pointers to search for pairs of numbers whose squares sum up to `c`. The basic idea is to check all possible pairs of numbers `a` and `b`, where `a` is incremented and `b` is decremented as needed to find a valid pair. This method is efficient due to the use of a two-pointer technique, which avoids checking all possible pairs exhaustively and helps reduce time complexity.

### Code Breakdown (Step by Step)

Let’s break down the code step by step to understand how it works:

#### 1. **Initial Setup:**
   ```cpp
   long left = 0, right = sqrt(c);
   ```
   - We initialize two variables, `left` and `right`. The `left` pointer starts at `0`, and the `right` pointer starts at the integer square root of `c`, i.e., \( \text{sqrt}(c) \). 
   - The reason we start with `right = sqrt(c)` is that if the square of any number exceeds `c`, then it can no longer be part of the sum \( a^2 + b^2 = c \). Thus, the maximum possible value for `b` would be `sqrt(c)`.

#### 2. **The While Loop:**
   ```cpp
   while(left <= right) {
       long res = left * left + right * right;
   ```
   - We enter a while loop that continues as long as the `left` pointer is less than or equal to the `right` pointer.
   - Inside the loop, we compute the sum of squares of `left` and `right` as `res = left * left + right * right`.

#### 3. **Comparing the Sum of Squares:**
   ```cpp
   if(res < c)
       left++;
   else if(res > c) 
       right--;
   else return true;
   ```
   - If `res < c`, it means that the sum of squares is too small, and we need to increase the value of `left` to try and get closer to `c`. Therefore, we increment `left`.
   - If `res > c`, the sum of squares is too large, and we need to decrease the value of `right` to try and get closer to `c`. Therefore, we decrement `right`.
   - If `res == c`, we have found a valid pair where \( a^2 + b^2 = c \), and we return `true`.

#### 4. **Return Statement:**
   ```cpp
   return false;
   ```
   - If we exit the while loop without finding a valid pair, it means that no such pair of integers exists that satisfy the condition \( a^2 + b^2 = c \), so we return `false`.

### Complexity

#### Time Complexity:

The time complexity of the solution is **O(sqrt(c))**, where `c` is the given integer. This is because the `left` pointer starts at 0 and increments until it reaches \( \sqrt{c} \), and the `right` pointer starts at \( \sqrt{c} \) and decrements until it reaches `left`. The total number of iterations is proportional to the square root of `c`.

- The loop runs at most \( \sqrt{c} \) iterations because both the `left` and `right` pointers move towards each other from opposite ends of the possible range. Each iteration involves constant-time operations such as calculating the sum of squares, comparison, and pointer adjustments.
- Therefore, the time complexity is **O(sqrt(c))**.

#### Space Complexity:

The space complexity of this solution is **O(1)**. The algorithm uses only a constant amount of extra space for storing the variables `left`, `right`, and `res`. No additional data structures are used that would grow with the size of the input.

### Conclusion

This solution efficiently checks if a given integer `c` can be represented as the sum of two squares by using the two-pointer technique. The two pointers (`left` and `right`) are adjusted based on the sum of their squares, effectively narrowing down the search space for a valid pair. By starting from the smallest and largest possible values for `a` and `b`, we ensure that we check only valid pairs, and the algorithm runs in **O(sqrt(c))** time, which is optimal for this problem.

The solution is both time-efficient and space-efficient, making it a great choice for large values of `c`. The key takeaway is the use of the two-pointer technique, which reduces unnecessary computations and ensures that the algorithm works efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-square-numbers/description/)

---
{{< youtube B0UrG_X2faA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
