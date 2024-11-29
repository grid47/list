
+++
authors = ["grid47"]
title = "Leetcode 12: Integer to Roman"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 12: Integer to Roman in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/12.webp"
youtube = "Rsq1ObYg6ak"
youtube_upload_date="2022-09-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Rsq1ObYg6ak/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/12.webp" 
    alt="Roman numerals glowing softly, forming a delicate arc of timeless symbols."
    caption="Solution to LeetCode 12: Integer to Roman Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a positive integer and need to convert it into a Roman numeral. Roman numerals are constructed by combining symbols from the set: I, V, X, L, C, D, M, where each symbol has a specific value. The conversion rules are based on subtractive notation for values like 4 (IV), 9 (IX), and so on, to avoid using symbols multiple times where not allowed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a single integer `num` (1 <= num <= 3999), which represents the number to be converted to a Roman numeral.
- **Example:** `Input: num = 1987`
- **Constraints:**
	- 1 <= num <= 3999

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the Roman numeral representation of the given number.
- **Example:** `Output: 'MCMLXXXVII'`
- **Constraints:**
	- The result should be a string representing the Roman numeral equivalent of the input number.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to break down the number into its decimal place values and convert them into Roman numerals according to the Roman numeral conversion rules.

- Create a list of values for Roman numerals starting from the largest to the smallest.
- For each value, check if it can be subtracted from the current number and add the corresponding Roman numeral symbol to the result.
- If a subtractive form like 4 (IV) or 9 (IX) is needed, use those instead of repeating smaller symbols.
{{< dots >}}
### Problem Assumptions ✅
- The input number will always be a valid positive integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = 1987`  \
  **Explanation:** 1987 is split into 1000 (M), 900 (CM), 80 (LXXX), and 7 (VII). Therefore, the Roman numeral is 'MCMLXXXVII'.

- **Input:** `Input: num = 58`  \
  **Explanation:** 58 is split into 50 (L) and 8 (VIII). Therefore, the Roman numeral is 'LVIII'.

{{< dots >}}
## Approach 🚀
To convert the number to a Roman numeral, we use a greedy approach that subtracts the largest possible Roman numeral values from the number at each step, appending the corresponding symbols to the result string.

### Initial Thoughts 💭
- We should process the Roman numeral symbols from largest to smallest to maximize the efficiency of the conversion.
- Start with the largest value (1000, M) and work downwards. This avoids adding unnecessary symbols.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since the number will always be between 1 and 3999.
- The solution should work efficiently for the largest input (3999).
- Ensure that the subtractive notation is correctly applied, e.g., 4 (IV), 9 (IX), 40 (XL), etc.
- The solution should process the number in O(1) time since the number of possible Roman numeral symbols is constant.
{{< dots >}}
## Code 💻
```cpp
string intToRoman(int num) {
    vector<int> nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    vector<string> chrs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    int idx = 0;
    string res = "";
    while(num > 0)
    {
        while(num >= nums[idx])
        {
            num -= nums[idx];
            res += chrs[idx];
        }
        idx++;
    }
    return res;
}
```

This code implements the `intToRoman` function, which converts an integer to a Roman numeral.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string intToRoman(int num) {
	```
	Declare the `intToRoman` function, which takes an integer `num` as input and returns a string representing the Roman numeral equivalent.

2. **Array Initialization**
	```cpp
	    vector<int> nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	```
	Initialize a vector `nums` to store the decimal values of Roman numerals in descending order.

3. **Array Initialization**
	```cpp
	    vector<string> chrs = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	```
	Initialize a vector `chrs` to store the corresponding Roman numerals for each decimal value.

4. **Variable Initialization**
	```cpp
	    int idx = 0;
	```
	Initialize an index `idx` to keep track of the current position in the `nums` and `chrs` vectors.

5. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string `res` to store the resulting Roman numeral.

6. **Loop Iteration**
	```cpp
	    while(num > 0)
	```
	Start a loop that continues while `num` is greater than 0.

7. **Loop Iteration**
	```cpp
	        while(num >= nums[idx])
	```
	Start an inner loop that continues while `num` is greater than or equal to the current decimal value.

8. **Mathematical Operations**
	```cpp
	            num -= nums[idx];
	```
	Subtract the current decimal value from `num`.

9. **String Manipulation**
	```cpp
	            res += chrs[idx];
	```
	Append the corresponding Roman numeral to the `res` string.

10. **Index Update**
	```cpp
	        idx++;
	```
	Increment the index `idx` to move to the next decimal value and its corresponding Roman numeral.

11. **Loop Iteration**
	```cpp
	    }
	```
	End of the outer loop.

12. **Return Value**
	```cpp
	    return res;
	```
	Return the final Roman numeral string `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Since the number of Roman numeral symbols is fixed and there are only a few steps involved in the conversion, the time complexity is O(1).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are only using a fixed number of variables to store the result and intermediate values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/integer-to-roman/description/)

---
{{< youtube Rsq1ObYg6ak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
