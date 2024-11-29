
+++
authors = ["grid47"]
title = "Leetcode 1945: Sum of Digits of String After Convert"
date = "2024-04-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1945: Sum of Digits of String After Convert in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KN4WAH95RIo"
youtube_upload_date="2021-07-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KN4WAH95RIo/maxresdefault.webp"
comments = true
+++



---
You are given a string consisting of lowercase English letters and an integer k. Your task is to convert the string into an integer by replacing each letter with its corresponding position in the alphabet (where 'a' = 1, 'b' = 2, ..., 'z' = 26), and then repeatedly sum its digits k times. The final result is the integer obtained after performing the digit sum operation k times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string s of lowercase English letters and an integer k. The string s represents the word to be converted into an integer, and k represents the number of times the digit sum operation should be performed.
- **Example:** `s = "abcd", k = 2`
- **Constraints:**
	- 1 <= s.length <= 100
	- 1 <= k <= 10
	- s consists of lowercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer obtained after performing the digit sum operation on the string's converted integer representation k times.
- **Example:** `Output: 7`
- **Constraints:**
	- The result should be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to convert each character in the string to its respective position in the alphabet, then repeatedly sum the digits of the resulting integer k times to get the final result.

- Step 1: Convert each character in the string to its corresponding number in the alphabet.
- Step 2: Concatenate the numbers to form a large integer.
- Step 3: Perform the digit sum operation on the integer k times.
- Step 4: Return the resulting integer after k digit sum operations.
{{< dots >}}
### Problem Assumptions ✅
- The input string will contain only lowercase English letters.
- The value of k will be at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "abcd", k = 2`  \
  **Explanation:** The string 'abcd' is converted to '1234'. First, we sum the digits: 1+2+3+4 = 10. Then, we sum the digits of 10: 1+0 = 1. After 2 transformations, the result is 1.

- **Input:** `Input: s = "aaa", k = 1`  \
  **Explanation:** The string 'aaa' becomes '111'. Summing the digits gives: 1+1+1 = 3. After 1 transformation, the result is 3.

{{< dots >}}
## Approach 🚀
The approach is to first map the letters of the string to their respective numeric values based on their position in the alphabet, and then perform digit sum transformations k times.

### Initial Thoughts 💭
- We need to map each letter to its respective position in the alphabet.
- After forming the integer from these positions, we will repeatedly sum the digits.
- This is a simple string manipulation and digit sum problem that can be solved in a straightforward manner using basic operations.
{{< dots >}}
### Edge Cases 🌐
- Empty string input is not valid as per the constraints.
- If the string has a length close to the upper limit (100 characters), the solution should efficiently handle the large number formed.
- Single character strings should return a simple transformation result.
- Ensure that k is within the valid range of 1 to 10.
{{< dots >}}
## Code 💻
```cpp
int getLucky(string s, int k) {
    string tmp;
    for (char c : s) tmp += to_string(c - 'a' + 1);
    int n = 0;
    for (char c : tmp) n += c - '0';
    for (int i = 1; i < k; ++i) {
        int next = 0;
        while (n) {
            next += n % 10;
            n /= 10;
        }
        n = next;
    }
    return n;
}
```

This function computes a transformation of the input string, calculates the sum of the digits derived from the string, and iterates a specified number of times to reduce the sum until it stabilizes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int getLucky(string s, int k) {
	```
	The function definition begins with the input parameters: 's' (a string) and 'k' (an integer) representing the number of iterations for the digit reduction process.

2. **Variable Initialization**
	```cpp
	    string tmp;
	```
	A string 'tmp' is initialized to store the numeric string derived from the input string 's'.

3. **Loop over String**
	```cpp
	    for (char c : s) tmp += to_string(c - 'a' + 1);
	```
	Each character of the input string 's' is converted to a corresponding number ('a' -> 1, 'b' -> 2, ..., 'z' -> 26) and appended to 'tmp'.

4. **Variable Initialization**
	```cpp
	    int n = 0;
	```
	The variable 'n' is initialized to 0. It will hold the sum of the digits in the string 'tmp'.

5. **Summing Digits**
	```cpp
	    for (char c : tmp) n += c - '0';
	```
	The digits in the string 'tmp' are summed up and stored in the variable 'n'. Each character is converted to its numeric value using 'c - '0'.

6. **Loop for Reduction**
	```cpp
	    for (int i = 1; i < k; ++i) {
	```
	A loop is initiated that will run 'k' times, reducing the sum 'n' by repeatedly summing its digits.

7. **Variable Initialization**
	```cpp
	        int next = 0;
	```
	A temporary variable 'next' is initialized to accumulate the sum of the digits of 'n'.

8. **While Loop for Digit Summation**
	```cpp
	        while (n) {
	```
	A while loop is used to reduce 'n' by summing its digits. The loop continues until 'n' becomes 0.

9. **Digit Summation**
	```cpp
	            next += n % 10;
	```
	The last digit of 'n' is added to 'next'.

10. **Update n**
	```cpp
	            n /= 10;
	```
	The last digit of 'n' is removed by performing integer division by 10.

11. **Update n**
	```cpp
	        n = next;
	```
	'n' is updated to 'next', which is the sum of the digits of the previous 'n'.

12. **Return Statement**
	```cpp
	    return n;
	```
	The final reduced value of 'n' is returned after 'k' iterations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the string.
- **Average Case:** O(n * k) where n is the length of the string and k is the number of digit sum operations.
- **Worst Case:** O(n * k), the worst-case time complexity occurs when the input string is large and k is at its maximum value.

The time complexity depends on both the string length and the number of times the transformation is performed.

### Space Complexity 💾
- **Best Case:** O(1), if we use constant space for digit summing operations.
- **Worst Case:** O(n), as we need space for storing the converted string and the intermediate results.

The space complexity depends on the length of the input string and the storage required for intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/)

---
{{< youtube KN4WAH95RIo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
