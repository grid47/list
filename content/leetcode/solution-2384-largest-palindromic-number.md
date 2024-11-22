
+++
authors = ["grid47"]
title = "Leetcode 2384: Largest Palindromic Number"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2384: Largest Palindromic Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IMktz_WlNYo"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/IMktz_WlNYo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {}, mid = -1;
        string s;

        for(char c: num) cnt[c - '0']++;

        for(int i = 9; i > 0; i--) {
            if(cnt[i] == 0) continue;
            s.append(cnt[i]/2, i + '0');
            if(mid == -1 && (cnt[i]&1))
                    mid = i;
        }

        if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
        mid = mid == -1 && (cnt[0] & 1)? 0: mid;
        if(mid != -1) s.push_back(mid + '0');
        s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());

        return s != ""? s : "0";
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks for the largest palindromic number that can be formed from the digits of a given string `num`. A palindromic number reads the same forward and backward, and we must form the largest possible one by rearranging the digits of the input string.

**Key Constraints**:
- The string `num` can contain digits from '0' to '9'.
- The solution must be the largest palindrome that can be constructed from the digits of `num`.
- If it's not possible to create any palindrome, return `"0"`.

### Approach

To form the largest palindromic number, we need to use the following strategy:

1. **Character Counting**: 
   - We first count the occurrences of each digit in the input string. This will help us understand how many times we can use each digit in the final palindrome.

2. **Constructing the Palindrome**:
   - A palindrome is symmetric, meaning that half of the digits must be the same as the other half.
   - For digits that appear an even number of times, we can use half of them on the left side and the other half on the right side of the palindrome.
   - For digits that appear an odd number of times, we can use all but one of them symmetrically. One of the odd digits (if any) can be used in the middle of the palindrome.

3. **Handling Special Cases**:
   - If no digits can be used to form a palindrome, return `"0"`.
   - The palindrome should be as large as possible, so we should prioritize placing larger digits first.

### Code Breakdown (Step by Step)

1. **Initialize the Count Array**:
   ```cpp
   int cnt[10] = {}, mid = -1;
   string s;
   ```
   - We initialize an array `cnt` to store the frequency of each digit from '0' to '9'. The array will have 10 elements, where `cnt[i]` will store how many times the digit `i` appears in the input string.
   - We also initialize a variable `mid` to store the middle digit of the palindrome (if any). Initially, it is set to -1, meaning there is no middle digit.

2. **Count the Frequency of Each Digit**:
   ```cpp
   for(char c: num) cnt[c - '0']++;
   ```
   - For each character `c` in the input string `num`, we increment the corresponding count in the `cnt` array. `c - '0'` converts the character to its corresponding integer value (e.g., '1' becomes 1).

3. **Form the Left Half of the Palindrome**:
   ```cpp
   for(int i = 9; i > 0; i--) {
       if(cnt[i] == 0) continue;
       s.append(cnt[i]/2, i + '0');
       if(mid == -1 && (cnt[i] & 1))
               mid = i;
   }
   ```
   - We start by iterating through the digits from 9 to 1. This ensures that we form the largest palindrome possible by using the largest digits first.
   - For each digit `i`, we append `cnt[i] / 2` instances of the digit `i` to the string `s`. This creates the left half of the palindrome.
   - If `cnt[i]` is odd (i.e., `cnt[i] & 1`), we record the digit `i` as a candidate for the middle of the palindrome. This will only be used if no middle digit has been assigned yet (i.e., `mid == -1`).

4. **Handle the Middle Digit**:
   ```cpp
   if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
   mid = mid == -1 && (cnt[0] & 1)? 0: mid;
   ```
   - After forming the left half of the palindrome, we check if the string `s` is non-empty and if there are any '0's in the input (`cnt[0] > 0`). If so, we append half of the zeros to the left half of the palindrome.
   - We update the `mid` variable to `0` if no middle digit has been assigned yet, and there is an odd count of '0's.

5. **Create the Full Palindrome**:
   ```cpp
   if(mid != -1) s.push_back(mid + '0');
   s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());
   ```
   - If a middle digit (`mid`) is found, we append it to the string `s`.
   - To complete the palindrome, we append the reverse of the left half of the string `s` (excluding the middle digit if present). This ensures that the string reads the same forward and backward.

6. **Return the Result**:
   ```cpp
   return s != ""? s : "0";
   ```
   - Finally, we check if the string `s` is non-empty. If it is, we return the palindrome. If the string is empty (i.e., no palindrome could be formed), we return `"0"`.

### Example Walkthrough

Let’s walk through an example to better understand how the algorithm works:

#### Input: `"444947137"`
1. Count the digits: `cnt = [0, 0, 0, 0, 3, 0, 0, 1, 1, 1]`.
2. Iterate over the digits from 9 to 1:
   - For `i = 9`, `cnt[9] = 1` (odd count). We choose 9 as the middle digit: `mid = 9`.
   - For `i = 8`, `cnt[8] = 1` (odd count). We choose 8 as part of the palindrome and append half (i.e., 1): `s = "8"`.
   - For `i = 7`, `cnt[7] = 1` (odd count). We choose 7: `s = "87"`.
   - For `i = 4`, `cnt[4] = 3`. We append half (i.e., 1) of 4 to `s`: `s = "874"`, then append 4 again (since `cnt[4]` is odd): `s = "8744"`.
3. Append the reverse of `s` (excluding the middle digit if present): `s = "87449"`.
4. Return `"87449"` as the largest palindrome.

#### Input: `"1111"`
1. Count the digits: `cnt = [0, 4]`.
2. For `i = 1`, `cnt[1] = 4`. We append 2 ones to `s`: `s = "11"`.
3. Append the reverse of `s` (excluding the middle digit): `s = "1111"`.
4. Return `"1111"`.

### Complexity

1. **Time Complexity**:
   - The algorithm performs two main operations: counting the digits and constructing the palindrome.
   - Counting the digits takes **O(n)** time, where `n` is the length of the input string `num`.
   - Constructing the palindrome involves iterating over the digit counts (a constant amount of operations for each digit), so the time complexity is **O(1)** for the loop over digits.
   - The total time complexity is therefore **O(n)**.

2. **Space Complexity**:
   - The space complexity is **O(1)**, as we only use a fixed amount of extra space for the digit count array and a few integer variables. The space used does not depend on the size of the input string.

### Conclusion

This solution efficiently constructs the largest palindromic number that can be formed from the digits of a given string. It leverages character counting, prioritizes larger digits to form the largest palindrome, and handles special cases like middle digits and zeros. The solution runs in linear time, making it optimal for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-palindromic-number/description/)

---
{{< youtube IMktz_WlNYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
