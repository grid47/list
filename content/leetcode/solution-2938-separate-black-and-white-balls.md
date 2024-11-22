
+++
authors = ["grid47"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2938: Separate Black and White Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-VVN0FI0KFo"
youtube_upload_date="2024-10-15"
youtube_thumbnail="https://i.ytimg.com/vi/-VVN0FI0KFo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt;
            else
                res += cnt;
        }
        return res;        
    }
};
{{< /highlight >}}
---

### Problem Statement:
Given a binary string `s` consisting of characters `'0'` and `'1'`, the task is to find the number of steps required to change all `'0'` characters to `'1'`. The problem specifies that the steps must be counted in a way that each step involves flipping a `'0'` to `'1'` by considering all previous `'1'`s to the left of it. Each flip adds a number of steps equal to the number of `'1'`s seen before the current `'0'`.

In simpler terms, we need to count how many `'1'`s are to the left of each `'0'`, and the total number of flips is the sum of these counts for all `'0'`s in the string.

### Approach:
The key to solving this problem efficiently lies in iterating over the string and keeping track of how many `'1'`s we've encountered as we go through the string. For each `'0'` encountered, the number of `'1'`s that have been encountered up to that point is added to the result. This is because every `'1'` before a `'0'` represents a valid flip step that will change that `'0'` into a `'1'`.

To summarize, the approach can be outlined as follows:
1. Traverse the string from left to right.
2. Keep a running count of how many `'1'`s have been seen up to each position.
3. For each `'0'` encountered, add the count of `'1'`s to the result, as these represent the number of flips needed to convert that `'0'`.
4. The total result will be the sum of all flips needed to convert every `'0'` to `'1'` based on the previous `'1'`s.

### Code Breakdown (Step by Step):

#### 1. **Variable Initialization**:
   We start by initializing two variables:
   - `res`: This will store the total number of steps required to flip all `'0'`s to `'1'`s.
   - `cnt`: This will keep track of the number of `'1'`s encountered so far in the string.

   ```cpp
   long long res = 0;
   for (int i = 0, cnt = 0; i < s.size(); ++i) {
   ```

#### 2. **Iterating Over the String**:
   We iterate over each character in the string `s`. The loop variable `i` is used to track the index of the current character.

   ```cpp
   for (int i = 0, cnt = 0; i < s.size(); ++i) {
   ```

#### 3. **Handling `'1'` Characters**:
   Whenever we encounter a `'1'`, we simply increment the `cnt` variable because each `'1'` encountered represents an additional valid flip that can be used for any subsequent `'0'`s.

   ```cpp
   if (s[i] == '1')
       ++cnt;
   ```

#### 4. **Handling `'0'` Characters**:
   If the current character is `'0'`, we add the number of `'1'`s encountered so far (`cnt`) to the result `res`. This is because each `'1'` before this `'0'` represents a valid flip operation that will change this `'0'` into `'1'`.

   ```cpp
   else
       res += cnt;
   ```

#### 5. **Return the Result**:
   Once the entire string is processed, the variable `res` contains the total number of flip steps required to convert all `'0'`s to `'1'`s. The function then returns `res`.

   ```cpp
   return res;
   ```

### Complexity:

#### Time Complexity:
- We are iterating over the string `s` once, and for each character, we perform constant time operations (incrementing variables or adding to the result). Therefore, the time complexity is \(O(n)\), where `n` is the length of the string `s`.

#### Space Complexity:
- We are using only a constant amount of extra space to store the variables `res` and `cnt`. Therefore, the space complexity is \(O(1)\).

### Conclusion:
This solution efficiently computes the minimum number of steps required to change all `'0'`s to `'1'`s in a binary string. By keeping track of the number of `'1'`s encountered as we traverse the string, we can quickly calculate the number of steps for each `'0'` encountered. The overall time complexity is linear in the size of the input string, and the space complexity is constant. This makes the solution optimal and well-suited for large strings. 

In summary:
- **Time Complexity**: \(O(n)\), where `n` is the length of the input string `s`.
- **Space Complexity**: \(O(1)\).

This solution ensures that we count the number of steps required in an efficient manner, making it a great fit for competitive programming and scenarios where performance is critical.

[`Link to LeetCode Lab`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---
{{< youtube -VVN0FI0KFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
