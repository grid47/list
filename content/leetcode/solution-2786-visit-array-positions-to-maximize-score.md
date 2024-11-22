
+++
authors = ["grid47"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2786: Visit Array Positions to Maximize Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JtogyeIxGWE"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/JtogyeIxGWE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxScore(vector<int>& n, int x) {
        long long eve = n[0] - (n[0] % 2 ? x : 0);
        long long odd = n[0] - (n[0] % 2 ? 0 : x);
        for (int i = 1; i < n.size(); ++i)
            if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
            else            eve = n[i] + max(eve, odd - x);
        return max(eve, odd);
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the maximum score that can be achieved by considering a sequence of numbers where you alternate between adding even and odd numbers. You can apply a penalty to an odd number when it is added to the score. The problem specifies a score calculation where:
- If the number is **even**, you can add it without penalty.
- If the number is **odd**, you can add it to the score but you incur a penalty of `x` if it has been preceded by an even number, and no penalty if the odd number follows another odd number.

Given an array of integers `n` and a penalty value `x`, the goal is to maximize the total score based on these rules.

### Approach

To solve this problem, we need to manage the alternating sequence of even and odd numbers while accounting for penalties when switching between them. We use dynamic programming to maintain two potential outcomes for the score:
- The first is the score if the last number we added is even (`eve`).
- The second is the score if the last number we added is odd (`odd`).

We iterate through the numbers in the array, updating these two possibilities at each step depending on whether the current number is even or odd.

### Code Breakdown (Step by Step)

```cpp
long long maxScore(vector<int>& n, int x) {
    long long eve = n[0] - (n[0] % 2 ? x : 0);  // Initial score if first number is even
    long long odd = n[0] - (n[0] % 2 ? 0 : x);  // Initial score if first number is odd
```
- **Initialization:**
    - We start by considering the first number in the array, `n[0]`.
    - If `n[0]` is even, the score `eve` is simply `n[0]`.
    - If `n[0]` is odd, a penalty of `x` is applied, so the score `odd` starts as `n[0] - x`.
    - These two variables `eve` and `odd` will represent the best possible scores for an alternating sequence of even and odd numbers starting with `n[0]`.

```cpp
    for (int i = 1; i < n.size(); ++i)
        if (n[i] % 2)   // If n[i] is odd
            odd = n[i] + max(odd, eve - x);  // Choose best outcome: add n[i] or subtract penalty
        else            // If n[i] is even
            eve = n[i] + max(eve, odd - x);  // Choose best outcome: add n[i] or subtract penalty
```
- **Iteration and Dynamic Updates:**
    - We loop over the rest of the elements in the array starting from index 1.
    - If `n[i]` is **odd**, we compute the new possible `odd` score. We take the maximum of:
        - Adding `n[i]` to the previous `odd` score (no penalty since the last number was odd).
        - Adding `n[i]` to the `eve` score and subtracting the penalty `x` (because we are switching from even to odd).
    - If `n[i]` is **even**, we compute the new possible `eve` score. We take the maximum of:
        - Adding `n[i]` to the previous `eve` score (no penalty since the last number was even).
        - Adding `n[i]` to the `odd` score and subtracting the penalty `x` (because we are switching from odd to even).
        
    This dynamic updating ensures that we always choose the maximum possible score at each step, considering the penalties and alternations between even and odd numbers.

```cpp
    return max(eve, odd);
}
```
- **Return Result:**
    - After processing all the numbers in the array, we return the maximum of `eve` and `odd`.
    - This gives us the maximum possible score after considering all numbers in the array while alternating between even and odd numbers, applying penalties when necessary.

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(n)**, where `n` is the number of elements in the input array `n`.
    - We iterate over the array exactly once, and at each step, we perform constant time operations (comparisons, additions, and subtractions).
    - Hence, the time complexity is linear with respect to the size of the input array.

#### Space Complexity:
- The space complexity is **O(1)**, since we only use a constant amount of extra space to store the variables `eve`, `odd`, and a few temporary variables for computation. No additional data structures are required, making this a space-efficient solution.

### Conclusion

The solution leverages dynamic programming principles to track the maximum score achievable by alternating between even and odd numbers. We maintain two variables, `eve` and `odd`, which represent the best scores for sequences ending in an even or odd number, respectively. As we iterate through the array, we update these variables based on whether the current number is odd or even, considering the penalties for switching between odd and even numbers. 

The time complexity is **O(n)**, where `n` is the length of the array, and the space complexity is **O(1)**, making this approach both time-efficient and space-efficient. This solution provides an optimal way to maximize the score while adhering to the rules of penalties for odd numbers and the alternation between even and odd numbers.

[`Link to LeetCode Lab`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---
{{< youtube JtogyeIxGWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
