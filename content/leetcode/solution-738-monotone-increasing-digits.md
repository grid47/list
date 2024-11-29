
+++
authors = ["grid47"]
title = "Leetcode 738: Monotone Increasing Digits"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 738: Monotone Increasing Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/738.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/738.webp" 
    alt="A set of digits where the monotone increasing condition is checked, with valid sequences glowing softly."
    caption="Solution to LeetCode 738: Monotone Increasing Digits Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer n, return the largest number less than or equal to n with digits in monotone increasing order, meaning each digit is less than or equal to the next one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an integer n where 0 <= n <= 10^9.
- **Example:** `n = 1234`
- **Constraints:**
	- 0 <= n <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest number less than or equal to n with monotone increasing digits.
- **Example:** `For the input n = 1234, the output should be 1234.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest number less than or equal to n that has digits in increasing order.

- Convert the number to a string to process the digits.
- Iterate through the digits from right to left to find the point where the digits stop increasing.
- Decrease the previous digit and set all subsequent digits to 9 to ensure the largest possible number.
- Convert the result back to an integer.
{{< dots >}}
### Problem Assumptions ✅
- The number n is a valid non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Starting with n = 211, the number 211 is not monotone increasing. By reducing the last digit and making the others 9, we get 199.`  \
  **Explanation:** 211 is not a valid number with increasing digits, so the largest number that is less than or equal to 211 with increasing digits is 199.

{{< dots >}}
## Approach 🚀
Use a greedy approach to find the largest number with monotone increasing digits less than or equal to n.

### Initial Thoughts 💭
- We need to adjust the number by reducing digits where necessary and ensuring the largest possible value for each adjustment.
- A greedy approach can solve this problem by looking for the first violation of monotonicity and adjusting the digits accordingly.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty, as n is a valid integer between 0 and 10^9.
- The algorithm should handle the largest possible input, which is 10^9.
- The input n = 0 should return 0, as 0 is trivially a number with monotone increasing digits.
- The solution should handle up to the largest input size efficiently.
{{< dots >}}
## Code 💻
```cpp
int monotoneIncreasingDigits(int n) {
    string n_str = to_string(n);

    int marker = n_str.size();

    for(int i = n_str.size() - 1; i > 0; i--) {
        if(n_str[i] < n_str[i - 1]) {
            marker = i;
            n_str[i-1] = n_str[i - 1] - 1;
        }
    }

    for(int i = marker; i < n_str.size(); i++)
        n_str[i]= '9';

    return stoi(n_str);
}
```

This function modifies the input integer `n` to its largest monotonic increasing number. It iterates through the digits, adjusting as necessary to ensure all digits after a decrease are set to 9.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int monotoneIncreasingDigits(int n) {
	```
	Define the function that takes an integer `n` as input.

2. **Variable Initialization**
	```cpp
	    string n_str = to_string(n);
	```
	Convert the integer `n` into a string `n_str` for easier manipulation of individual digits.

3. **Variable Initialization**
	```cpp
	    int marker = n_str.size();
	```
	Initialize the `marker` variable to the size of `n_str`, which will track the point where digits need modification.

4. **Loop Setup**
	```cpp
	    for(int i = n_str.size() - 1; i > 0; i--) {
	```
	Start a loop that traverses the digits of `n_str` from the last digit to the first, excluding the most significant digit.

5. **Condition Check**
	```cpp
	        if(n_str[i] < n_str[i - 1]) {
	```
	Check if the current digit is smaller than the previous one, indicating the need for modification.

6. **Modification**
	```cpp
	            marker = i;
	```
	Set `marker` to the current position `i`, marking where adjustments to digits need to occur.

7. **Modification**
	```cpp
	            n_str[i-1] = n_str[i - 1] - 1;
	```
	Decrement the previous digit by 1, as we are attempting to create the largest possible monotonic increasing number.

8. **Digit Update**
	```cpp
	    for(int i = marker; i < n_str.size(); i++)
	```
	Start a second loop to set all digits after the `marker` position to '9'.

9. **Digit Update**
	```cpp
	        n_str[i]= '9';
	```
	Set each digit starting from the `marker` position to '9', ensuring the number is as large as possible while still being monotonic increasing.

10. **Return Statement**
	```cpp
	    return stoi(n_str);
	```
	Convert the modified string `n_str` back into an integer and return it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of digits in the number. This happens when no adjustment is needed.
- **Average Case:** O(n), as we need to iterate through the digits at most twice.
- **Worst Case:** O(n), where n is the number of digits in the number, as we traverse the number from right to left.

The time complexity is O(n) because we iterate through the digits of the number once.

### Space Complexity 💾
- **Best Case:** O(1), as no extra space is needed if the solution does not require copying the digits.
- **Worst Case:** O(n), where n is the number of digits in the number, as we need to store the digits in a string.

The space complexity is O(n) due to the storage of the digits in a string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/monotone-increasing-digits/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
