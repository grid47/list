
+++
authors = ["grid47"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2024-03-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "kv0O7p0pRvI"
youtube_upload_date="2022-05-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kv0O7p0pRvI/maxresdefault.webp"
comments = true
+++



---
You are given a string `num` consisting of digits, where each digit represents a specific number. The task is to verify if for every index `i` in the string, the digit at index `i` appears exactly `num[i]` times in the entire string. Return `true` if the condition holds for all indices, and `false` otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string `num` of length `n` consisting of digits, where 1 <= n <= 10.
- **Example:** `Input: num = "2020"`
- **Constraints:**
	- 1 <= num.length <= 10
	- num consists of digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether the condition holds for every index.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify for each index `i` in the string `num`, the digit `i` must appear exactly `num[i]` times in the string.

- Initialize an array to count the frequency of each digit.
- Iterate over each digit in the string and check if the frequency matches the expected value at that index.
- Return `true` if all conditions hold, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The string contains only digits.
- The length of the string will not exceed 10.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = "1210"`  \
  **Explanation:** For this input, the conditions hold true because: num[0] = 1, and the digit 0 appears once in the string; num[1] = 2, and the digit 1 appears twice; num[2] = 1, and the digit 2 appears once; num[3] = 0, and the digit 3 appears zero times.

- **Input:** `Input: num = "1122"`  \
  **Explanation:** For this input, the condition fails because: num[0] = 1, and the digit 0 occurs zero times, which violates the condition.

{{< dots >}}
## Approach 🚀
The approach is to count the occurrences of each digit in the string and check if each digit at index `i` matches its expected frequency based on the digit value at `num[i]`.

### Initial Thoughts 💭
- We need to track the occurrences of digits efficiently.
- By iterating through the string and using a simple counting mechanism, we can verify if the condition holds for all indices.
{{< dots >}}
### Edge Cases 🌐
- The input string is never empty, as the minimum length is 1.
- The maximum length of the input string is 10, so performance concerns are minimal.
- If the string consists of repeated zeros, the condition will fail if any index does not meet the expected count.
- The problem has a small input size, allowing us to use simple counting techniques.
{{< dots >}}
## Code 💻
```cpp
bool digitCount(string num) {
int cnt[10] = {};
for (auto n : num)
    ++cnt[n - '0'];
for (int i = 0; i < num.size(); ++i)
    if (cnt[i] != num[i] - '0')
        return false;
return true;
}
```

This function checks whether the frequency of each digit in a number (represented as a string) matches the digits at their respective positions in the number. It returns `true` if the frequencies match, otherwise it returns `false`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool digitCount(string num) {
	```
	The function `digitCount` takes a string `num` as input and returns a boolean value indicating whether the frequency of digits in `num` matches the digits at the respective positions.

2. **Initialize Count Array**
	```cpp
	int cnt[10] = {};
	```
	An array `cnt` of size 10 is initialized to 0. This array will be used to store the frequency of each digit (from 0 to 9) in the string `num`.

3. **Loop Through String**
	```cpp
	for (auto n : num)
	```
	This `for` loop iterates over each character in the string `num`, where each character represents a digit.

4. **Update Count Array**
	```cpp
	    ++cnt[n - '0'];
	```
	For each digit `n` in the string, we convert the character to its integer value (`n - '0'`) and increment the corresponding index in the `cnt` array.

5. **Loop Through Digits**
	```cpp
	for (int i = 0; i < num.size(); ++i)
	```
	This second `for` loop iterates over each index `i` of the string `num`, checking whether the frequency of the digit at position `i` matches the digit itself.

6. **Check Frequency Match**
	```cpp
	    if (cnt[i] != num[i] - '0')
	```
	This conditional checks if the frequency of digit `i` stored in `cnt[i]` matches the digit at position `i` in the string `num`. If they don't match, the function will return `false`.

7. **Return False**
	```cpp
	        return false;
	```
	If the frequencies do not match for any digit, the function returns `false` immediately, indicating the number doesn't satisfy the condition.

8. **Return True**
	```cpp
	return true;
	```
	If all digit frequencies match their respective digits, the function returns `true`, indicating that the number satisfies the condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where `n` is the length of the string, due to the single iteration over the string to count digits.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need an array of size 10 to track the frequency of digits.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/)

---
{{< youtube kv0O7p0pRvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
