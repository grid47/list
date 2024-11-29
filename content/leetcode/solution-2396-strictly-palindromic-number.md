
+++
authors = ["grid47"]
title = "Leetcode 2396: Strictly Palindromic Number"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2396: Strictly Palindromic Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Two Pointers","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "37EtWXDucwQ"
youtube_upload_date="2022-09-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/37EtWXDucwQ/maxresdefault.webp"
comments = true
+++



---
An integer `n` is considered strictly palindromic if, for every base `b` between 2 and `n - 2` (inclusive), the representation of `n` in base `b` is a palindrome. A number is palindromic in a base if the string representation of that number in that base reads the same forward and backward. Your task is to determine if the given integer `n` is strictly palindromic or not.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer `n` (4 <= n <= 10^5), where `n` is the number you need to check for strict palindromicity across various bases.
- **Example:** `n = 5`
- **Constraints:**
	- 4 <= n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if `n` is strictly palindromic, otherwise return `false`.
- **Example:** `Output: false`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if for all bases between 2 and `n - 2`, the base `b` representation of `n` is palindromic. If for any base it is not palindromic, return false.

- 1. Iterate through all bases from 2 to `n - 2`.
- 2. For each base, convert `n` to its string representation in that base.
- 3. Check if the string representation is a palindrome.
- 4. If a non-palindromic representation is found, return false.
- 5. If all representations are palindromic, return true.
{{< dots >}}
### Problem Assumptions ✅
- The number `n` is always greater than or equal to 4.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6`  \
  **Explanation:** In base 2: 6 = 110 (not palindromic), base 3: 6 = 20 (not palindromic), base 4: 6 = 12 (not palindromic), hence 6 is not strictly palindromic.

- **Input:** `n = 7`  \
  **Explanation:** In base 2: 7 = 111 (palindromic), base 3: 7 = 21 (not palindromic), hence 7 is not strictly palindromic.

{{< dots >}}
## Approach 🚀
The approach is to iterate over all bases between 2 and `n - 2`, converting the number `n` to its base `b` representation and checking if the representation is palindromic. If any base has a non-palindromic representation, the function will return false.

### Initial Thoughts 💭
- This problem involves converting numbers to various bases and checking for palindromic properties.
- The challenge lies in efficiently checking palindromes for all bases up to `n-2`.
{{< dots >}}
### Edge Cases 🌐
- Since `n` is always >= 4, there are no empty inputs.
- Handle cases where `n` is near the upper limit of 10^5.
- Consider how values near the lower bound (like `n = 4`) behave.
- Make sure that the solution is efficient enough to handle the largest inputs within the time limit.
{{< dots >}}
## Code 💻
```cpp
bool isStrictlyPalindromic(int n) {
    return false;
}
```

The function `isStrictlyPalindromic` is a placeholder function that takes an integer `n` as input and simply returns `false`. This function is likely meant to check if a number is strictly palindromic in some base, but it is incomplete.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isStrictlyPalindromic(int n) {
	```
	The function `isStrictlyPalindromic` is declared. It takes an integer `n` as input and is expected to return a boolean value indicating whether `n` is strictly palindromic in a given base.

2. **Return Statement**
	```cpp
	    return false;
	```
	The function currently returns `false`, meaning that no number is considered strictly palindromic in this implementation. The logic for palindromic checking in various bases needs to be implemented.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input number.
- **Average Case:** O(n), where n is the length of the input number.
- **Worst Case:** O(n^2), where n is the length of the input number due to base conversion and palindrome checking.

The worst-case time complexity is O(n^2) because for each base we convert the number and check if it's palindromic.

### Space Complexity 💾
- **Best Case:** O(1), if using a constant amount of extra space.
- **Worst Case:** O(n), where n is the length of the input number due to space used in storing the string representations.

The space complexity is O(n) in the worst case, where n is the number of digits in the base `b` representation of `n`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/strictly-palindromic-number/description/)

---
{{< youtube 37EtWXDucwQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
