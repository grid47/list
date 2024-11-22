
+++
authors = ["grid47"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2024-08-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 926: Flip String to Monotone Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tMq9z5k3umQ"
youtube_upload_date="2023-01-17"
youtube_thumbnail="https://i.ytimg.com/vi/tMq9z5k3umQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0, cnt_flip = 0;
        for(char c: s) {
            if(c == '1') cnt_one++;
            else         cnt_flip++;
            cnt_flip = min(cnt_one, cnt_flip);
        }
        return cnt_flip;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to make a binary string `s` monotonically increasing by flipping the fewest number of characters. A binary string is considered monotonically increasing if all `'0'`s come before all `'1'`s in the string. The task is to return the minimum number of flips required to make `s` satisfy this condition.

### Approach

To solve this, we use a **dynamic counting approach** to track the minimum flips necessary. The main idea is to keep two counters as we iterate through `s`:

1. **Count of '1's (`cnt_one`)**:
   - This counter keeps track of the number of `'1'` characters encountered so far.
   - It represents the minimum number of flips required if we decided to convert all future characters to `'1'` to maintain a monotonically increasing sequence.

2. **Count of Flips (`cnt_flip`)**:
   - This counter tracks the minimum number of flips needed to make the sequence monotonically increasing up to the current character.
   - It is updated at each character by taking the minimum of `cnt_one` and `cnt_flip`.
   - If we encounter a `'0'` and `cnt_one` is greater, we would consider flipping the `'0'` to `'1'` to keep the string increasing.

3. **Updating Counters**:
   - As we iterate through `s`:
     - If the character is `'1'`, we increment `cnt_one` to reflect that there’s an additional `'1'`.
     - If the character is `'0'`, it’s a potential place where the string could break the increasing order. We increment `cnt_flip` and then update it to the minimum between `cnt_one` and `cnt_flip`, ensuring we take the fewest flips to maintain monotonicity.

4. **Returning Result**:
   - Once we finish iterating through `s`, `cnt_flip` contains the minimum number of flips needed to make the entire string monotonically increasing.

### Code Breakdown (Step by Step)

1. **Initialize Counters**:
   ```cpp
   int cnt_one = 0, cnt_flip = 0;
   ```
   - `cnt_one` is initialized to 0 to track the number of `'1'` characters encountered so far.
   - `cnt_flip` is initialized to 0 to store the minimum flips needed to make the string monotonic up to each point.

2. **Iterate Through String `s`**:
   ```cpp
   for(char c: s) {
       if(c == '1') cnt_one++;
       else         cnt_flip++;
       cnt_flip = min(cnt_one, cnt_flip);
   }
   ```
   - For each character in `s`:
     - If the character is `'1'`, increment `cnt_one`.
     - If the character is `'0'`, increment `cnt_flip` as we consider flipping it to `'1'` for monotonicity.
   - Update `cnt_flip` to the minimum between `cnt_one` and `cnt_flip` to ensure the smallest number of flips.

3. **Return Final Flip Count**:
   ```cpp
   return cnt_flip;
   ```
   - After the loop, `cnt_flip` contains the minimum flips needed to make `s` monotonically increasing.

### Complexity

1. **Time Complexity**:
   - The time complexity is **O(n)**, where `n` is the length of the string `s`, since we only iterate through `s` once.

2. **Space Complexity**:
   - The space complexity is **O(1)**, as we only use a few integer variables for counting and no additional data structures.

### Conclusion

This solution provides an optimal way to determine the minimum number of flips to make a binary string monotonically increasing. The dynamic counting approach effectively minimizes flips while only requiring a single pass through `s`. By maintaining two counters, `cnt_one` and `cnt_flip`, we can make quick decisions on whether to flip or keep each character to satisfy the condition. This method is efficient and scales well, even for large strings, making it a powerful solution for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

---
{{< youtube tMq9z5k3umQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
