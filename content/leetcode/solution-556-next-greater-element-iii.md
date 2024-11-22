
+++
authors = ["grid47"]
title = "Leetcode 556: Next Greater Element III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 556: Next Greater Element III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp"
youtube = "-Ehc8QF1eac"
youtube_upload_date="2021-03-04"
youtube_thumbnail="https://i.ytimg.com/vi/-Ehc8QF1eac/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/556.webp" 
    alt="A sequence of numbers where each next greater element softly illuminates as it’s found for the next number."
    caption="Solution to LeetCode 556: Next Greater Element III Problem"
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
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n)? -1: res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the next greater element with the same digits as the given number `n`. This involves rearranging the digits of `n` to find the next larger number that can be formed. If no such larger number exists (i.e., `n` is the largest possible number with those digits), the function should return `-1`. The output must be returned as an integer.

**Example 1:**

Input: `12`  
Output: `21`  
Explanation: The next greater number with the same digits as `12` is `21`.

**Example 2:**

Input: `21`  
Output: `-1`  
Explanation: Since `21` is already the largest number that can be formed with its digits, the function returns `-1`.

### Approach

The goal is to find the next greater permutation of the digits of the given number `n`. To achieve this, we can leverage a well-known algorithm for finding the "next permutation" in an ordered set of numbers.

Here are the steps to solve the problem:

1. **Convert the Number to a String**: Since we are dealing with digits, it’s easier to manipulate the digits if they are treated as characters in a string.
2. **Next Permutation Algorithm**: This algorithm helps us find the next lexicographically larger permutation of the digits:
   - Traverse the string of digits from right to left and find the first digit that is smaller than the digit next to it.
   - Swap this digit with the smallest digit that is larger than it, found to its right.
   - Reverse the digits to the right of the swapped digit to get the smallest lexicographical order.
3. **Check the Validity of the Result**: The result should be a valid integer that is greater than the original number. If the result exceeds the maximum value of an integer (`INT_MAX`), or if the result is smaller than or equal to the original number, return `-1`.
4. **Return the Result**: Convert the digits back to an integer and return the result if it is valid, otherwise return `-1`.

### Code Breakdown (Step by Step)

#### 1. **Converting the Number to a String**
```cpp
auto digits = to_string(n);
```
- First, we convert the given number `n` to a string so that we can manipulate the digits more easily. This allows us to use string manipulation functions like `next_permutation` on the digits.

#### 2. **Applying the Next Permutation**
```cpp
next_permutation(begin(digits), end(digits));
```
- The function `next_permutation` is a built-in function in C++ that rearranges the digits to the next lexicographical permutation.
- It modifies the sequence of digits to the next greater permutation (if possible), otherwise, it rearranges the digits into the smallest possible order (if the input is already the largest permutation).
- We call this function on the `digits` string, which rearranges the digits into the next permutation.

#### 3. **Converting Back to an Integer**
```cpp
auto res = stoll(digits);
```
- After the digits are rearranged, we convert the modified string back to an integer using `stoll` (which stands for "string to long long"), since the number could potentially be large and beyond the range of `int`.
- `stoll` converts the string back into an integer type that can handle large numbers.

#### 4. **Validating the Result**
```cpp
return (res > INT_MAX || res <= n)? -1: res;
```
- The final check ensures that the resulting number is valid:
  - If the result exceeds `INT_MAX` (the maximum value an `int` can hold), the function returns `-1`, since the number would be out of the valid range for a 32-bit integer.
  - If the result is less than or equal to the original number `n`, the function also returns `-1`, since we are looking for the next greater number, not the same or smaller number.
- If both conditions are passed, the result `res` is returned as the next greater number.

### Complexity

#### Time Complexity:
- **O(d)**, where `d` is the number of digits in the given number `n`. The `next_permutation` function operates in linear time with respect to the number of digits, as it needs to examine and rearrange the digits once.
- Converting the number to a string and back to an integer also takes linear time with respect to the number of digits. Therefore, the time complexity is **O(d)**.

#### Space Complexity:
- **O(d)**, where `d` is the number of digits in `n`. This space is required to store the string representation of the digits of `n` and the result. The space complexity comes from the need to store the digits as a string and the final rearranged string, making the space complexity linear with respect to the number of digits.

### Conclusion

This solution efficiently finds the next greater number that can be formed from the digits of a given number `n`. It uses the "next permutation" algorithm, which is a well-established algorithm for finding the next lexicographically greater permutation in an ordered set of numbers. 

**Key points:**
- The algorithm finds the next permutation of digits in linear time.
- It uses string manipulation to facilitate the rearrangement of digits.
- It checks if the resulting number is within the valid range for integers and returns `-1` if not.

**Advantages:**
- The solution is fast with a time complexity of **O(d)**, where `d` is the number of digits, making it suitable for large numbers.
- The space complexity is also **O(d)**, as it uses only the necessary space to store the digits and the result.

This approach is a simple yet effective way to solve the problem using the next permutation algorithm, ensuring correctness and efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-element-iii/description/)

---
{{< youtube -Ehc8QF1eac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
