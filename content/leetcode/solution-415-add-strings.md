
+++
authors = ["grid47"]
title = "Leetcode 415: Add Strings"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 415: Add Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/415.webp"
youtube = "XbPJhrkROfI"
youtube_upload_date="2020-03-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XbPJhrkROfI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/415.webp" 
    alt="Two strings being added together, with each character gently illuminating to show the sum."
    caption="Solution to LeetCode 415: Add Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two non-negative integers represented as strings, return the sum of these numbers as a string. The solution should avoid converting the strings to integers directly or using any built-in libraries for large integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two strings num1 and num2, each representing a non-negative integer.
- **Example:** `For num1 = '5' and num2 = '789', the output is '794'.`
- **Constraints:**
	- 1 <= num1.length, num2.length <= 10^4
	- num1 and num2 consist of only digits.
	- num1 and num2 don't have leading zeros except for '0'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the two numbers as a string.
- **Example:** `For num1 = '1234' and num2 = '876', the output is '2110'.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To add two large numbers represented as strings and return their sum as a string.

- 1. Initialize a carry variable to 0 and an empty string to store the result.
- 2. Start from the rightmost digits of both strings and sum corresponding digits, including the carry from the previous sum.
- 3. If there are remaining digits in either string, continue summing them.
- 4. If there is any carry left after processing both strings, add it to the result.
- 5. Return the final result, ensuring that the digits are in the correct order.
{{< dots >}}
### Problem Assumptions ✅
- The inputs are valid strings representing non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For num1 = '0' and num2 = '0', the output is '0'.`  \
  **Explanation:** The sum of two zeros is zero, which is handled correctly by the algorithm.

{{< dots >}}
## Approach 🚀
Iterate through the strings from right to left, adding corresponding digits and managing carry to compute the sum of the two numbers.

### Initial Thoughts 💭
- We need to process the digits of both numbers one by one starting from the least significant digit.
- The strings may have different lengths, so we need to handle cases where one number has more digits than the other.
- Use two pointers to traverse both strings, and maintain a carry to handle overflow during addition.
{{< dots >}}
### Edge Cases 🌐
- If num1 or num2 is a very large number (e.g., 10^4 digits), the solution should still run efficiently.
- If either num1 or num2 is '0', the result should be the other number.
- Handle cases where the input strings have different lengths.
{{< dots >}}
## Code 💻
```cpp
   string addStrings(string num1, string num2) {
    int carry=0,i=num1.length()-1,j=num2.length()-1;
    string ans="";
    while(i>=0||j>=0||carry>0){
        if(i>=0){
            carry=carry+num1[i]-'0';
            i--;
        }
        if(j>=0){
            carry=carry+num2[j]-'0';
            j--;
        }
        
         ans += char(carry % 10 + '0');
        carry =carry/ 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
```

This function adds two non-negative integers represented as strings and returns their sum as a string. The function performs the addition digit by digit, handling the carry and ensuring the result is returned in the correct order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	   string addStrings(string num1, string num2) {
	```
	Define the function `addStrings` which takes two strings, `num1` and `num2`, representing two non-negative integers, and returns their sum as a string.

2. **Variable Initialization**
	```cpp
	    int carry=0,i=num1.length()-1,j=num2.length()-1;
	```
	Initialize the `carry` variable to 0, and set `i` and `j` to the last indices of `num1` and `num2`, respectively, to start adding from the rightmost digits.

3. **String Initialization**
	```cpp
	    string ans="";
	```
	Initialize an empty string `ans` to store the result of the addition as the digits are processed.

4. **Loop Iteration**
	```cpp
	    while(i>=0||j>=0||carry>0){
	```
	Start a `while` loop that continues as long as there are more digits to process or there is a carry left to add.

5. **Conditional Check**
	```cpp
	        if(i>=0){
	```
	If there are still digits in `num1` (i.e., `i` is non-negative), process the current digit.

6. **Digit Processing**
	```cpp
	            carry=carry+num1[i]-'0';
	```
	Add the current digit of `num1` (converted to an integer) to the `carry`.

7. **Index Decrement**
	```cpp
	            i--;
	```
	Decrement the index `i` to move to the next left digit in `num1`.

8. **Conditional Check**
	```cpp
	        }
	```
	End the `if` block for processing digits in `num1`.

9. **Conditional Check**
	```cpp
	        if(j>=0){
	```
	If there are still digits in `num2` (i.e., `j` is non-negative), process the current digit.

10. **Digit Processing**
	```cpp
	            carry=carry+num2[j]-'0';
	```
	Add the current digit of `num2` (converted to an integer) to the `carry`.

11. **Index Decrement**
	```cpp
	            j--;
	```
	Decrement the index `j` to move to the next left digit in `num2`.

12. **Answer Construction**
	```cpp
	         ans += char(carry % 10 + '0');
	```
	Append the current digit (obtained by taking the remainder of `carry` divided by 10) to the result string `ans`.

13. **Carry Update**
	```cpp
	        carry =carry/ 10;
	```
	Update the `carry` by dividing it by 10 to ensure it contains only the carry-over for the next iteration.

14. **Reverse Operation**
	```cpp
	    reverse(ans.begin(),ans.end());
	```
	Reverse the string `ans` to ensure the digits are in the correct order (since they were processed from right to left).

15. **Return Statement**
	```cpp
	    return ans;
	```
	Return the final result string `ans` containing the sum of `num1` and `num2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the maximum length of the two input strings, since we iterate through both strings once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of digits in the resulting sum, since we store the result in a string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-strings/description/)

---
{{< youtube XbPJhrkROfI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
