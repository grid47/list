
+++
authors = ["grid47"]
title = "Leetcode 168: Excel Sheet Column Title"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 168: Excel Sheet Column Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/168.webp"
youtube = "X_vJDpCCuoA"
youtube_upload_date="2023-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/X_vJDpCCuoA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/168.webp" 
    alt="A radiant column title unfolding slowly, forming the Excel-style alphanumeric title."
    caption="Solution to LeetCode 168: Excel Sheet Column Title Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer columnNumber, which represents the column number to be converted to Excel column title.
- **Example:** `columnNumber = 27`
- **Constraints:**
	- 1 <= columnNumber <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string representing the column title corresponding to the input columnNumber.
- **Example:** `Output: 'AA'`
- **Constraints:**
	- The output is a valid Excel column title.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the Excel column title corresponding to a given integer columnNumber.

- Reduce the columnNumber by 1 (to make the conversion zero-indexed).
- Calculate the remainder when divided by 26, and map it to the corresponding alphabet (A-Z).
- Update columnNumber by dividing it by 26, and continue the process until columnNumber becomes 0.
{{< dots >}}
### Problem Assumptions ✅
- The column number will always have a valid corresponding Excel column title.
{{< dots >}}
## Examples 🧩
- **Input:** `columnNumber = 27`  \
  **Explanation:** The column title corresponding to 27 is 'AA'. This is because after reducing 27 by 1, we get 26, which corresponds to 'Z'. Dividing by 26 gives us 1, which corresponds to 'A'.

{{< dots >}}
## Approach 🚀
We will convert the integer columnNumber into its corresponding Excel column title by repeatedly calculating remainders and mapping them to characters.

### Initial Thoughts 💭
- The problem involves repeatedly dividing the number by 26 and mapping the result to a letter in the alphabet.
- This problem can be solved by simulating the conversion process using basic modular arithmetic.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that columnNumber will be at least 1, so no need to handle empty inputs.
- For large columnNumbers, the solution must handle the division and string construction efficiently.
- If columnNumber is 1, the result should be 'A'.
- The approach should work efficiently for values up to 2^31 - 1.
{{< dots >}}
## Code 💻
```cpp
string convertToTitle(int columnNumber) {
    string res = "";
    int mod;
    while(columnNumber > 0) {
        mod = --columnNumber % 26;
        char x = ('A' + mod);
        res = x + res;
        columnNumber /= 26;
    }
    return res;
}
```

This function converts a given column number (as an integer) to its corresponding Excel column title, like how 1 maps to 'A', 2 maps to 'B', etc.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string convertToTitle(int columnNumber) {
	```
	Define the function 'convertToTitle' that converts an integer column number to its corresponding Excel column title (e.g., 1 -> 'A').

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	Initialize an empty string 'res' to build the resulting column title as we compute it.

3. **Variable Declaration**
	```cpp
	    int mod;
	```
	Declare an integer 'mod' to store the result of the modulo operation, which will be used to calculate the characters of the column title.

4. **While Loop**
	```cpp
	    while(columnNumber > 0) {
	```
	Start a while loop that continues until 'columnNumber' becomes zero, which means we have processed all digits of the title.

5. **Modulo Operation**
	```cpp
	        mod = --columnNumber % 26;
	```
	Decrement 'columnNumber' by 1 to handle the 'A' as 0 case, then compute the remainder when dividing by 26 to get the corresponding character's index.

6. **Character Conversion**
	```cpp
	        char x = ('A' + mod);
	```
	Convert the calculated remainder ('mod') to the corresponding character in the alphabet by adding it to the ASCII value of 'A'.

7. **String Update**
	```cpp
	        res = x + res;
	```
	Prepend the character 'x' to the result string 'res', so that the title is built in the correct order from right to left.

8. **Column Division**
	```cpp
	        columnNumber /= 26;
	```
	Divide 'columnNumber' by 26 to move to the next significant digit of the Excel column title.

9. **Return Statement**
	```cpp
	    return res;
	```
	Return the computed column title stored in the 'res' string.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(columnNumber))
- **Average Case:** O(log(columnNumber))
- **Worst Case:** O(log(columnNumber))

The time complexity is O(log(columnNumber)) because we divide columnNumber by 26 in each iteration.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(log(columnNumber))

The space complexity is O(log(columnNumber)) due to the string being built in the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/excel-sheet-column-title/description/)

---
{{< youtube X_vJDpCCuoA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
