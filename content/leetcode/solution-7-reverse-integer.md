
+++
authors = ["grid47"]
title = "Leetcode 7: Reverse Integer"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 7: Reverse Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/7.webp"
youtube = "HAgLH58IgJQ"
youtube_upload_date="2021-08-18"
youtube_thumbnail="https://i.ytimg.com/vi/HAgLH58IgJQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/7.webp" 
    alt="A swirling, translucent number turning in reverse motion, unfolding in a calming spiral."
    caption="Solution to LeetCode 7: Reverse Integer Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Reverse the digits of a signed 32-bit integer. If the reversed integer is outside the range of a signed 32-bit integer, return 0. You are restricted from using 64-bit integers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a signed 32-bit integer.
- **Example:** `Input: x = 456`
- **Constraints:**
	- -2^31 <= x <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the reversed integer or 0 if the reversed integer exceeds the 32-bit signed integer range.
- **Example:** `Output: 654`
- **Constraints:**
	- If reversing causes overflow, return 0.

{{< dots >}}
### Core Logic 🔍
**Goal:** Reverse the digits of the input integer while ensuring the result does not exceed the 32-bit integer range.

- Extract digits one by one using modulus and division.
- Check for potential overflow before appending the digit to the result.
- Stop and return 0 if the next step would exceed the integer limits.
- Return the reversed number.
{{< dots >}}
### Problem Assumptions ✅
- Input integer will always be within the 32-bit signed range.
- Negative numbers retain their sign after reversal.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: x = 456`  \
  **Explanation:** Reverse the digits of 456 to get 654.

- **Input:** `Input: x = -890`  \
  **Explanation:** Reverse the digits of -890 to get -98.

- **Input:** `Input: x = 0`  \
  **Explanation:** The reversed digits of 0 is still 0.

{{< dots >}}
## Approach 🚀
Simulate the digit reversal process and manage overflow using checks before appending each digit.

### Initial Thoughts 💭
- Reversing the digits is straightforward using modulus and division.
- Overflow must be checked at each step before modifying the result.
- Use conditions to handle cases where the next digit causes overflow or underflow.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as input is always provided.
- Test with inputs close to the integer boundaries like -2147483648 and 2147483647.
- Test with 0 and single-digit numbers.
- Ensure that overflow cases return 0 as expected.
{{< dots >}}
## Code 💻
```cpp
int reverse(int x)
{
    int rev=0, pop;
    while(x != 0)
    {
        pop  = x % 10;
        x   /= 10;

        if( (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) || 
            (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) )
            return 0;

        rev  = rev * 10 + pop;
    }
    return  rev;
}
```

This code implements a function to reverse the digits of an integer `x`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int reverse(int x)
	```
	Declare the `reverse` function, which takes an integer `x` as input and returns the reversed integer.

2. **Variable Initialization**
	```cpp
	    int rev=0, pop;
	```
	Initialize variables `rev` and `pop` to store the reversed integer and the popped digit, respectively.

3. **Loop Iteration**
	```cpp
	    while(x != 0)
	```
	Start a loop that continues as long as `x` is not zero.

4. **Modulo Operation**
	```cpp
	        pop  = x % 10;
	```
	Extract the last digit of `x` using the modulo operator and store it in `pop`.

5. **Integer Division**
	```cpp
	        x   /= 10;
	```
	Remove the last digit from `x` by integer division.

6. **Conditional Check**
	```cpp
	        if( (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) || 
	```
	Check if the reversed integer `rev` is about to exceed the maximum integer value.

7. **Conditional Check**
	```cpp
	            (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) )
	```
	Check if the reversed integer `rev` is about to go below the minimum integer value.

8. **Return Value**
	```cpp
	            return 0;
	```
	If overflow or underflow occurs, return 0.

9. **Mathematical Operations**
	```cpp
	        rev  = rev * 10 + pop;
	```
	Multiply `rev` by 10 and add the popped digit `pop` to it.

10. **Return Value**
	```cpp
	    return  rev;
	```
	Return the reversed integer `rev`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d)
- **Average Case:** O(d)
- **Worst Case:** O(d)

Where 'd' is the number of digits in the integer, as each digit is processed once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space for variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-integer/description/)

---
{{< youtube HAgLH58IgJQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
