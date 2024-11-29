
+++
authors = ["grid47"]
title = "Leetcode 443: String Compression"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 443: String Compression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/443.webp"
youtube = "JHTqvUTZzqM"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi/JHTqvUTZzqM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/443.webp" 
    alt="A string shrinking as characters are compressed, with each compression step softly glowing."
    caption="Solution to LeetCode 443: String Compression Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of characters, compress it by replacing consecutive repeating characters with the character followed by the count of repetitions. If the character repeats only once, just include the character. The result should modify the input array and return the new length of the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an array of characters where each character is a lowercase or uppercase letter, digit, or symbol.
- **Example:** `["a","a","b","b","c","c","c"]`
- **Constraints:**
	- 1 <= chars.length <= 2000
	- chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the new length of the modified array, with the array itself being compressed in place.
- **Example:** `6`
- **Constraints:**
	- The modified array should be stored in the input array itself.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently compress the character array by grouping consecutive repeating characters and replacing them with the character followed by the count.

- 1. Iterate over the characters in the input array.
- 2. For each group of consecutive repeating characters, append the character to the result.
- 3. If the group contains more than one character, append the length of the group as well.
- 4. Modify the input array in place to store the compressed version.
- 5. Return the new length of the array.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain at least one character.
{{< dots >}}
## Examples 🧩
- **Input:** `["a","a","b","b","c","c","c"]`  \
  **Explanation:** In this case, the consecutive characters 'a' and 'b' appear twice, while 'c' appears three times. The output compresses to ['a','2','b','2','c','3'].

- **Input:** `["x"]`  \
  **Explanation:** The array has only one character, so no compression is necessary and the length remains 1.

{{< dots >}}
## Approach 🚀
The solution uses a greedy approach to iterate through the input array, compressing consecutive character groups in place without using extra space.

### Initial Thoughts 💭
- This problem requires modifying the array in place, so careful management of indices is necessary.
- We can use two pointers: one to track the current character and another to track the position where we will store the compressed result.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- For large input arrays with many consecutive repeating characters, the solution must run efficiently in O(n) time.
- Consider cases where all characters are unique or all characters are the same.
- Ensure that no additional space is used beyond constant space for character count storage.
{{< dots >}}
## Code 💻
```cpp
int compress(vector<char>& chars) {
    if(chars.size() < 2) return chars.size();
    int i = 0, j = 0;
    while(i < chars.size()) {
        chars[j] = chars[i];
        int cnt = 0;
        while(i < chars.size() && chars[i] == chars[j]) {
            cnt++;
            i++;
        }

        if(cnt == 1) {
            j++;
        } else {
            string cntt = to_string(cnt);
            for(auto ch: cntt) {
                chars[++j] = ch;
            }
            j++;
        }
    }
    return j;
}
```

This function compresses a string by replacing consecutive duplicate characters with the character followed by its count. The function modifies the input vector and returns the new length after compression.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int compress(vector<char>& chars) {
	```
	Defines the function to compress a vector of characters by replacing consecutive duplicates with the character and its count.

2. **Edge Case Check**
	```cpp
	    if(chars.size() < 2) return chars.size();
	```
	Checks if the input vector has fewer than two characters. If so, no compression is needed, and the function returns the original size.

3. **Variable Initialization**
	```cpp
	    int i = 0, j = 0;
	```
	Initializes two pointers, 'i' to traverse the input and 'j' to build the compressed version of the string.

4. **Main Loop**
	```cpp
	    while(i < chars.size()) {
	```
	Begins a loop to traverse the input vector of characters.

5. **Character Assignment**
	```cpp
	        chars[j] = chars[i];
	```
	Assigns the current character at 'i' to the position 'j' in the compressed vector.

6. **Counter Initialization**
	```cpp
	        int cnt = 0;
	```
	Initializes a counter 'cnt' to track the number of consecutive occurrences of the current character.

7. **Count Consecutive Characters**
	```cpp
	        while(i < chars.size() && chars[i] == chars[j]) {
	```
	Starts an inner loop to count consecutive characters that are the same as the current character at 'j'.

8. **Increment Count**
	```cpp
	            cnt++;
	```
	Increments the counter 'cnt' for each consecutive occurrence of the current character.

9. **Move Pointer**
	```cpp
	            i++;
	```
	Moves the pointer 'i' to the next character in the input vector.

10. **Handle Count**
	```cpp
	        if(cnt == 1) {
	```
	Checks if there is only one occurrence of the character.

11. **Single Occurrence Handling**
	```cpp
	            j++;
	```
	If the character occurs only once, simply moves the pointer 'j' to the next position.

12. **Handle Multiple Occurrences**
	```cpp
	        } else {
	```
	If the character occurs more than once, the function will append the count to the vector.

13. **Count to String Conversion**
	```cpp
	            string cntt = to_string(cnt);
	```
	Converts the count 'cnt' to a string so that its digits can be added to the vector.

14. **Appending Count Digits**
	```cpp
	            for(auto ch: cntt) {
	```
	Iterates through the digits of the count and appends each digit to the compressed vector.

15. **Store Count Digit**
	```cpp
	                chars[++j] = ch;
	```
	Stores each digit of the count in the appropriate position in the vector.

16. **Increment Pointer**
	```cpp
	            j++;
	```
	Increments pointer 'j' after appending the count digits.

17. **Return Statement**
	```cpp
	    return j;
	```
	Returns the new length of the compressed vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array. This happens when there are no repetitions.
- **Average Case:** O(n), because we still need to traverse the entire array.
- **Worst Case:** O(n), where n is the length of the input array, even in the case of large repetitions.

The solution traverses the array once, updating elements in place.

### Space Complexity 💾
- **Best Case:** O(1), since we do not use extra space except for the input array.
- **Worst Case:** O(1), as we only use a few integer variables for indexing and counting.

The space complexity is constant because we do not use any additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/string-compression/description/)

---
{{< youtube JHTqvUTZzqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
