
+++
authors = ["grid47"]
title = "Leetcode 2075: Decode the Slanted Ciphertext"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2075: Decode the Slanted Ciphertext in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vFxVjspTM-0"
youtube_upload_date="2021-11-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vFxVjspTM-0/maxresdefault.webp"
comments = true
+++



---
Given an encoded string and the number of rows used to encode the original text, recover the original string. The encoded text is produced by filling a matrix in a slanted transposition cipher and reading it row by row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an encoded string `encodedText` and an integer `rows` representing the number of rows used to encode the original text.
- **Example:** `encodedText = 'hello    wor  ld   ', rows = 3`
- **Constraints:**
	- 0 <= encodedText.length <= 10^6
	- encodedText consists of lowercase English letters and spaces
	- encodedText is a valid encoding of some originalText that does not have trailing spaces
	- 1 <= rows <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decoded original text as a string.
- **Example:** `Output: 'helloworld'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To decode the encoded text back to its original form using the given number of rows.

- Calculate the number of columns in the matrix from the length of the encoded text and the number of rows.
- Reconstruct the matrix by placing the characters of the encoded text according to the slanted transposition cipher pattern.
- Read the matrix diagonally and reconstruct the original text.
{{< dots >}}
### Problem Assumptions ✅
- The encoded text does not contain trailing spaces.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this example, the encoded string is 'hello    wor  ld   ' with 3 rows. By filling the matrix diagonally, we can recover the original string 'helloworld'.

- **Input:** `Example 2`  \
  **Explanation:** For the input 'abc   defghi' and 3 rows, the matrix looks like: 'abc', 'def', 'ghi'. Reading diagonally, we recover 'abcdefghi'.

{{< dots >}}
## Approach 🚀
The solution involves reconstructing the matrix from the encoded string and reading it diagonally to recover the original string.

### Initial Thoughts 💭
- We need to reverse the encoding process by filling a matrix with the encoded text and reading it diagonally.
- The problem can be solved by calculating the matrix dimensions and then reversing the transposition cipher to get the original string.
{{< dots >}}
### Edge Cases 🌐
- If the encoded text is empty, the original text is also empty.
- Ensure that the algorithm works efficiently for the maximum input size (encodedText.length up to 10^6).
- When there is only one row, the encoded text is the same as the original text.
- The algorithm must handle the given constraints and ensure that the reconstructed text is valid.
{{< dots >}}
## Code 💻
```cpp
string decodeCiphertext(string et, int rows) {
    cout << et.size() << " " << rows;
    string res = "";
    int col = et.size() / rows;
    int idx = 0;
    string space = "";
    // cout << col << " " << rows << " ";
    while(idx < col - rows + 2) {
        for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
            if(et[idx + i + i * col] == ' ')
                space += ' ';
            else {
                res += (space + et[idx + i + i * col]);                    
                space = "";
            }

        }
        idx++;
    }
    return res;
}
```

This function decodes a ciphered string by re-arranging characters according to the specified number of rows, essentially reversing the process of encoding characters into a matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string decodeCiphertext(string et, int rows) {
	```
	This is the function signature for `decodeCiphertext`, which accepts a string `et` (the encoded text) and an integer `rows` (the number of rows in the cipher matrix). It returns the decoded string.

2. **Variable Initialization**
	```cpp
	    string res = "";
	```
	This line initializes an empty string `res`, which will hold the decoded result.

3. **Column Calculation**
	```cpp
	    int col = et.size() / rows;
	```
	This line calculates the number of columns in the cipher matrix by dividing the size of the encoded string `et` by the number of rows.

4. **Index Initialization**
	```cpp
	    int idx = 0;
	```
	This line initializes an index `idx` to track the position of the current character being processed in the cipher.

5. **Space Initialization**
	```cpp
	    string space = "";
	```
	This initializes a `space` string to hold spaces that are encountered during decoding, ensuring that they are correctly placed in the result.

6. **While Loop**
	```cpp
	    while(idx < col - rows + 2) {
	```
	This `while` loop iterates over the columns and adjusts the `idx` value to ensure we process the matrix correctly for decoding.

7. **For Loop**
	```cpp
	        for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
	```
	This nested `for` loop iterates through the rows and checks if the current character index falls within the bounds of the encoded string.

8. **Space Check**
	```cpp
	            if(et[idx + i + i * col] == ' ')
	```
	This checks if the current character in the encoded string is a space.

9. **Space Accumulation**
	```cpp
	                space += ' ';
	```
	If the character is a space, it is added to the `space` string to maintain the spaces in the decoded message.

10. **Character Processing**
	```cpp
	            else {
	```
	If the character is not a space, it is added to the decoded result string `res`.

11. **Result Update**
	```cpp
	                res += (space + et[idx + i + i * col]);
	```
	This line appends the current character (along with any accumulated spaces) to the result string `res`.

12. **Space Reset**
	```cpp
	                space = "";
	```
	This resets the `space` string after processing a non-space character.

13. **Index Increment**
	```cpp
	        idx++;
	```
	This increments the `idx` value to move to the next character in the encoded string.

14. **Return Statement**
	```cpp
	    return res;
	```
	This line returns the decoded string stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the size of the input string, as we process each character exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear in terms of the size of the input string, as we store the matrix and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-the-slanted-ciphertext/description/)

---
{{< youtube vFxVjspTM-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
