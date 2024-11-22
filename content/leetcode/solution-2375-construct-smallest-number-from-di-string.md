
+++
authors = ["grid47"]
title = "Leetcode 2375: Construct Smallest Number From DI String"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2375: Construct Smallest Number From DI String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-vIB0xikOw"
youtube_upload_date="2022-08-14"
youtube_thumbnail="https://i.ytimg.com/vi/b-vIB0xikOw/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestNumber(string ptn) {
        string res, stk;
        int n = ptn.size();
        for(int i = 0; i <= n; i++) {
            stk.push_back(i + '1');
            if(i == n || ptn[i] == 'I') {
                while(!stk.empty()) {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given a string `ptn` that consists of the characters `'I'` (representing "increase") and `'D'` (representing "decrease"). Our goal is to return the smallest number that can be formed by the digits from `1` to `n + 1` (where `n` is the length of `ptn`), such that the sequence of digits satisfies the given pattern of increasing and decreasing orders.

For example:
- If `ptn = "IDID"`, the output should be `"13254"`.
- If `ptn = "III"`, the output should be `"1234"`.

The approach is to treat the problem as a stack-based problem where we push digits into a stack when the pattern indicates a decrease (`'D'`) and pop digits from the stack when the pattern indicates an increase (`'I'`).

### Approach

The key observation is that we can use a stack to handle the "decreasing" segments of the pattern efficiently. Here’s how we can break down the approach:

1. **Initial Setup**:
   - The sequence of digits we need to form ranges from `1` to `n + 1`, where `n` is the length of the given pattern string `ptn`.
   - We will iterate through the pattern string and for each index, either push the current digit into the stack or pop it to form the correct number sequence.

2. **Stack Logic**:
   - When the pattern character is `'I'` (increase), we know that the current digit should be smaller than the next digit. Therefore, we need to pop the digits from the stack to get the correct order for this increasing segment.
   - When the pattern character is `'D'` (decrease), we push the current digit into the stack because the current digit is larger than the next digit, and we’ll deal with it later when the sequence needs to increase.

3. **Handling Edge Cases**:
   - After processing all characters in the pattern, there may still be numbers left in the stack. These should be popped and added to the result to complete the number sequence.

4. **Final Result**:
   - After going through the pattern and handling all increase and decrease operations, the result is a string representing the smallest number satisfying the given pattern.

### Code Breakdown (Step by Step)

1. **Class Definition**:
    ```cpp
    class Solution {
    public:
        string smallestNumber(string ptn) {
    ```
    The class `Solution` contains the method `smallestNumber` which takes the string `ptn` as input and returns the smallest number that satisfies the pattern.

2. **Variable Initialization**:
    ```cpp
        string res, stk;
        int n = ptn.size();
    ```
    - `res` will store the final result, which is the smallest number.
    - `stk` is a string that simulates a stack. It will be used to temporarily store digits during the processing of decreasing sequences in the pattern.
    - `n` is the length of the pattern string.

3. **Main Loop**:
    ```cpp
        for(int i = 0; i <= n; i++) {
            stk.push_back(i + '1');
    ```
    - The loop iterates from `i = 0` to `i = n`. We iterate one extra time to handle the last digit. For each iteration, we push the current number (`i + 1`) into the stack (`stk`).
    - The number `i + '1'` is added to the stack because the digits we are using range from `1` to `n + 1`. The expression `i + '1'` converts the integer `i + 1` to its corresponding character.

4. **Handling the `'I'` Pattern**:
    ```cpp
            if(i == n || ptn[i] == 'I') {
                while(!stk.empty()) {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
            }
    ```
    - If the current character in the pattern is `'I'` (increase), or if we are at the end of the pattern (`i == n`), we pop all the elements from the stack and append them to the result string `res`.
    - This ensures that when we encounter an increase, we have the digits in increasing order in the result.

5. **Return the Result**:
    ```cpp
        return res;
    }
    ```
    After processing all the digits and handling the pattern, the result string `res` is returned, containing the smallest number that satisfies the given pattern.

### Complexity

1. **Time Complexity**:
    - The algorithm processes each character of the pattern string exactly once, and for each character, we either push or pop from the stack. Both pushing and popping operations on the stack are constant time operations.
    - Therefore, the time complexity of this solution is **O(n)**, where `n` is the length of the pattern string. Since we only iterate through the pattern string once and the stack operations are done in constant time, the overall time complexity is linear.

2. **Space Complexity**:
    - We use a stack (implemented as a string `stk`) to temporarily store digits. The size of this stack is at most `n + 1`, as we push digits from `1` to `n + 1`.
    - Therefore, the space complexity of this solution is **O(n)**, where `n` is the length of the pattern string. The space is required to store the digits temporarily and to hold the result string.

### Conclusion

The solution efficiently solves the problem by utilizing a stack to handle the decrease (`'D'`) segments of the pattern and ensuring that digits are popped in the correct order when the pattern requires an increase (`'I'`). The algorithm processes the pattern string in linear time and uses constant space for each operation, making it both time and space efficient.

This approach works efficiently even for larger input sizes due to its **O(n)** time complexity. The logic behind using a stack to manage the ordering of digits based on the increase/decrease pattern is simple and elegant, ensuring that we always form the smallest possible number satisfying the given pattern. The implementation is concise, and the solution handles edge cases like consecutive increasing or decreasing patterns correctly.

This method provides a fast and scalable solution to this problem, making it an excellent choice for solving such pattern-based number formation problems.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-smallest-number-from-di-string/description/)

---
{{< youtube b-vIB0xikOw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
