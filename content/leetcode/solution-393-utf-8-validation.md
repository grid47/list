
+++
authors = ["grid47"]
title = "Leetcode 393: UTF-8 Validation"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 393: UTF-8 Validation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/393.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/393.webp" 
    alt="A string being validated for UTF-8 encoding, with each valid byte sequence softly glowing."
    caption="Solution to LeetCode 393: UTF-8 Validation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers `data`, where each integer represents one byte of data. Your task is to check whether this sequence of bytes forms a valid UTF-8 encoded string based on the UTF-8 encoding rules for 1 to 4 bytes characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `data` where each integer represents one byte of data.
- **Example:** `Input: [197, 130, 1]`
- **Constraints:**
	- 1 <= data.length <= 2 * 10^4
	- 0 <= data[i] <= 255

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean indicating whether the input array `data` represents a valid UTF-8 encoding.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be true if the byte sequence represents a valid UTF-8 encoding, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to validate if the given byte sequence adheres to the rules of UTF-8 encoding.

- Iterate through the array of bytes in `data`.
- Check the first bits of each byte to determine whether it's the start of a 1, 2, 3, or 4-byte character.
- For continuation bytes (those starting with `10`), ensure that the correct number of continuation bytes follows.
- Return true if the entire sequence is valid; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- Each integer in `data` represents one byte of data, and the byte values range from 0 to 255.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [197, 130, 1]`  \
  **Explanation:** The byte sequence '11000101 10000010 00000001' represents a valid UTF-8 encoding: a 2-byte character followed by a 1-byte character.

- **Input:** `Input: [235, 140, 4]`  \
  **Explanation:** The byte sequence '11101011 10001100 00000100' represents an invalid UTF-8 encoding because the second byte does not start with '10' as required for a continuation byte.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the byte array and validating each byte according to the rules for UTF-8 encoding.

### Initial Thoughts 💭
- We need to check the starting bits of each byte to determine the number of bytes that form a character.
- For each continuation byte, we need to ensure it starts with '10'.
- The solution involves a simple traversal of the byte array and checking the bits, ensuring that the sequence follows the UTF-8 encoding rules.
{{< dots >}}
### Edge Cases 🌐
- The input is guaranteed to be non-empty, so no need to handle empty arrays.
- The solution must be optimized to handle large inputs with up to 2 * 10^4 elements.
- A sequence with an invalid continuation byte (not starting with '10') should return false.
- The solution should efficiently check the validity of the UTF-8 encoding even for the largest inputs.
{{< dots >}}
## Code 💻
```cpp
bool validUtf8(vector<int>& data) {
    int count = 0;
    for(auto c : data) {
        if(count == 0) {
            if((c >> 5) == 0b110) count = 1;
            else if ((c >> 4) == 0b1110) count = 2;
            else if ((c >> 3) == 0b11110) count = 3;
            else if (c >> 7) return false;
        } else {
            if ((c >> 6) != 0b10) return false;
            count--;
        }
    }
    return count == 0;
}
```

This function checks whether a given sequence of integers represents a valid UTF-8 encoding. It processes each byte and verifies if the sequences follow the correct number of continuation bytes according to UTF-8 encoding rules.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool validUtf8(vector<int>& data) {
	```
	Define the function 'validUtf8' that takes a vector of integers, 'data', representing a sequence of bytes. It will return a boolean value indicating whether the sequence is a valid UTF-8 encoding.

2. **Variable Initialization**
	```cpp
	    int count = 0;
	```
	Initialize a variable 'count' to track the number of continuation bytes remaining for a valid UTF-8 sequence.

3. **For Loop**
	```cpp
	    for(auto c : data) {
	```
	Start a loop to iterate through each byte 'c' in the 'data' vector.

4. **Main If Condition**
	```cpp
	        if(count == 0) {
	```
	Check if no continuation bytes are expected, meaning we are starting a new character in the UTF-8 sequence.

5. **UTF-8 First Byte Check**
	```cpp
	            if((c >> 5) == 0b110) count = 1;
	```
	Check if the byte 'c' represents a valid starting byte for a 2-byte UTF-8 character. The condition checks the first 3 bits to determine if it matches the '110' prefix.

6. **UTF-8 First Byte Check**
	```cpp
	            else if ((c >> 4) == 0b1110) count = 2;
	```
	Check if the byte 'c' represents a valid starting byte for a 3-byte UTF-8 character. The condition checks the first 4 bits to determine if it matches the '1110' prefix.

7. **UTF-8 First Byte Check**
	```cpp
	            else if ((c >> 3) == 0b11110) count = 3;
	```
	Check if the byte 'c' represents a valid starting byte for a 4-byte UTF-8 character. The condition checks the first 5 bits to determine if it matches the '11110' prefix.

8. **Invalid First Byte Check**
	```cpp
	            else if (c >> 7) return false;
	```
	If the byte does not match any valid starting byte prefix (i.e., the first bit is 1 but does not match any of the expected patterns), return false, indicating an invalid UTF-8 sequence.

9. **Else Block for Continuation Bytes**
	```cpp
	        } else {
	```
	If we are expecting continuation bytes (i.e., 'count' is not 0), we check if the current byte follows the continuation pattern.

10. **UTF-8 Continuation Byte Check**
	```cpp
	            if ((c >> 6) != 0b10) return false;
	```
	Check if the byte 'c' is a valid continuation byte. A continuation byte in UTF-8 should start with '10' in its most significant bits.

11. **Decrement Continuation Byte Count**
	```cpp
	            count--;
	```
	Decrement the 'count' variable to indicate that one continuation byte has been successfully processed.

12. **Return Statement**
	```cpp
	    return count == 0;
	```
	If 'count' is 0 at the end of the loop, it means all continuation bytes were matched correctly, and the UTF-8 sequence is valid. Otherwise, return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate through each byte in the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/utf-8-validation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
