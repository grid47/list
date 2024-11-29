
+++
authors = ["grid47"]
title = "Leetcode 67: Add Binary"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 67: Add Binary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Bit Manipulation","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/67.webp"
youtube = "M9foA9gcL98"
youtube_upload_date="2024-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/M9foA9gcL98/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/67.webp" 
    alt="Two radiant binary sequences gently merging into a new, illuminated result."
    caption="Solution to LeetCode 67: Add Binary Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two binary strings, a and b. Each string represents a binary number. Your task is to compute their sum and return it as a binary string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Two binary strings a and b, representing non-negative binary numbers.
- **Example:** `Input: a = "101", b = "11"`
- **Constraints:**
	- 1 <= a.length, b.length <= 10^4
	- a and b consist only of '0' or '1' characters.
	- Neither string contains leading zeros, except for the string '0' itself.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a binary string representing the sum of the two input binary strings.
- **Example:** `Output: "1000"`
- **Constraints:**
	- The output binary string must represent the correct sum of the two input binary numbers.

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the sum of two binary strings and return the result as a binary string.

- Initialize a carry variable to handle carryovers during addition.
- Iterate over both strings from right to left, adding corresponding digits along with the carry.
- If one string is shorter, treat the missing digits as 0.
- For each sum, update the carry and append the resulting bit to the output.
- If carry remains after processing all digits, prepend it to the result.
- Return the resulting binary string.
{{< dots >}}
### Problem Assumptions ✅
- The input strings represent valid binary numbers.
- The result will fit within memory limits.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: a = "101", b = "11"`  \
  **Explanation:** The binary sum of 101 and 11 is 1000, so the output is "1000".

- **Input:** `Input: a = "0", b = "0"`  \
  **Explanation:** Adding two zeros results in zero, so the output is "0".

{{< dots >}}
## Approach 🚀
The solution involves simulating binary addition manually, similar to adding numbers digit by digit, while keeping track of carryovers.

### Initial Thoughts 💭
- Binary addition involves summing digits and managing carry, similar to decimal addition.
- Strings of different lengths can be aligned by treating missing digits as 0.
- Iterate over the strings from the end, adding digits one by one with a carry.
{{< dots >}}
### Edge Cases 🌐
- Not applicable since the constraints guarantee valid inputs.
- Two strings of length 10^4, such as "1" repeated 10^4 times.
- Strings containing all zeros, e.g., "0" + "0".
- One string significantly shorter than the other, e.g., "1" and "100000".
- Ensure carry is correctly managed for large inputs.
{{< dots >}}
## Code 💻
```cpp
string addBinary(string a, string b) {
    string result = "";
    int carry = 0;

    // Iterate from the end of both strings until both are empty and carry is 0
    while (a.size() > 0 || b.size() > 0 || carry > 0) {
        int sum = carry;
        if (a.size() > 0) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size() > 0) {
            sum += b.back() - '0';
            b.pop_back();
        }

        // Append the current bit to the result
        result = to_string(sum % 2) + result;

        // Update the carry for the next iteration
        carry = sum / 2;
    }

    return result;
}
```

This code adds two binary numbers represented as strings and returns the result as a binary string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string addBinary(string a, string b) {
	```
	This line declares a function named `addBinary` that takes two binary strings `a` and `b` as input and returns their sum as a binary string.

2. **Initialize Result and Carry**
	```cpp
	    string result = "";
	    int carry = 0;
	```
	This line initializes an empty string `result` to store the binary sum and an integer `carry` to keep track of any carry-over from previous additions.

3. **Iterate and Add Digits**
	```cpp
	    while (a.size() > 0 || b.size() > 0 || carry > 0) {
	```
	This loop iterates until both input strings are empty and there's no carry-over.

4. **Calculate Sum**
	```cpp
	        int sum = carry;
	```
	This line initializes the `sum` variable to the current `carry` value.

5. **Add Digits from a**
	```cpp
	        if (a.size() > 0) {
	            sum += a.back() - '0';
	            a.pop_back();
	        }
	```
	If `a` is not empty, add the last digit of `a` to the `sum` and remove it from `a`.

6. **Add Digits from b**
	```cpp
	        if (b.size() > 0) {
	            sum += b.back() - '0';
	            b.pop_back();
	        }
	```
	If `b` is not empty, add the last digit of `b` to the `sum` and remove it from `b`.

7. **Append Result Digit**
	```cpp
	        result = to_string(sum % 2) + result;
	```
	Append the current bit (the remainder of `sum` divided by 2) to the beginning of the `result` string.

8. **Update Carry**
	```cpp
	        carry = sum / 2;
	```
	Update the `carry` for the next iteration by dividing `sum` by 2.

9. **Return Result**
	```cpp
	    return result;
	```
	Return the final `result` string, which represents the binary sum of `a` and `b`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm processes each digit of the input strings exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space is required for the result string and the carry.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-binary/description/)

---
{{< youtube M9foA9gcL98 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
