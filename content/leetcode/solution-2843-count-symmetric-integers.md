
+++
authors = ["grid47"]
title = "Leetcode 2843:   Count Symmetric Integers"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2843:   Count Symmetric Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KHRfRTVqpVc"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/KHRfRTVqpVc/maxresdefault.jpg"
comments = true
+++



---
You are given two integers low and high. Return the number of symmetric integers in the range [low, high]. A symmetric integer has an even number of digits, and the sum of the first half of its digits equals the sum of the second half. Numbers with an odd number of digits are never symmetric.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, low and high, representing the range of numbers to check for symmetry.
- **Example:** `low = 1, high = 50`
- **Constraints:**
	- 1 <= low <= high <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of symmetric integers within the range [low, high].
- **Example:** `4`
- **Constraints:**
	- The output should be a single integer indicating the number of symmetric numbers in the range.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the count of symmetric integers in the given range [low, high].

- Loop through all integers in the range [low, high].
- Convert each integer to a string to check its symmetry.
- Check if the number has an even number of digits.
- For numbers with an even number of digits, check if the sum of the first half of digits equals the sum of the second half.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain valid positive integers.
- The number of digits for each number is not too large, ensuring the solution can run efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `low = 1, high = 50`  \
  **Explanation:** The symmetric numbers between 1 and 50 are: 11, 22, 33, and 44. These numbers have an even number of digits, and the sum of the digits in the first half is equal to the sum of the digits in the second half.

- **Input:** `low = 800, high = 850`  \
  **Explanation:** The symmetric numbers between 800 and 850 are: 808, 818. These numbers are symmetric because they have an even number of digits, and the sum of the first half equals the sum of the second half.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through each number in the range [low, high], converting it to a string, and checking if it is symmetric. If a number has an even number of digits and the sum of the first half of its digits equals the sum of the second half, we count it as symmetric.

### Initial Thoughts 💭
- The range can be as large as 10^4, so a direct solution iterating through all numbers will work within the time limits.
- The key observation is that symmetric numbers must have an even number of digits.
- We can use string manipulation to extract the digits and check if the sums of the halves are equal.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as low and high are always valid positive integers.
- The input range can be as large as 10^4, but this is manageable with the approach.
- Consider cases where low equals high, or the range contains only a few numbers.
- Ensure that we check the number of digits in each number and avoid counting odd-digit numbers.
{{< dots >}}
## Code 💻
```cpp
int countSymmetricIntegers(int low, int high) {
    int ans = 0;
    for(int i = low; i <= high; ++i) {
        string s = to_string(i);
        int t = 0, n = s.size();
        for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
        if(n%2 == 0 && t == 0) ans++;
    }
    return ans;
}
```

This code counts the number of symmetric integers between the given low and high range, where a symmetric integer is one whose digits form a palindrome.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Prototype**
	```cpp
	int countSymmetricIntegers(int low, int high) {
	```
	Define the function `countSymmetricIntegers` that takes a range of integers (`low` to `high`) and returns the count of symmetric integers within that range.

2. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize a variable `ans` to store the count of symmetric integers.

3. **Loop Setup**
	```cpp
	    for(int i = low; i <= high; ++i) {
	```
	Loop through each integer from `low` to `high`.

4. **String Conversion**
	```cpp
	        string s = to_string(i);
	```
	Convert the current integer `i` to a string `s` for easy manipulation of digits.

5. **Variable Initialization**
	```cpp
	        int t = 0, n = s.size();
	```
	Initialize two variables: `t` for storing the sum of differences between mirrored digits, and `n` for storing the length of the string `s`.

6. **Digit Comparison**
	```cpp
	        for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
	```
	Loop through the first half of the digits and calculate the difference between mirrored digits.

7. **Palindrome Check**
	```cpp
	        if(n%2 == 0 && t == 0) ans++;
	```
	Check if the number of digits `n` is even and if the sum of differences `t` is zero (indicating a palindrome). If so, increment the `ans` counter.

8. **Return Result**
	```cpp
	    return ans;
	```
	Return the final count of symmetric integers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the size of the range [low, high]. We iterate over each number and check its symmetry.

### Space Complexity 💾
- **Best Case:** O(d)
- **Worst Case:** O(d)

The space complexity is O(d), where d is the number of digits in the largest number (at most 4).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-symmetric-integers/description/)

---
{{< youtube KHRfRTVqpVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
