
+++
authors = ["grid47"]
title = "Leetcode 1461: Check If a String Contains All Binary Codes of Size K"
date = "2024-06-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1461: Check If a String Contains All Binary Codes of Size K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qU32rTy_kOM"
youtube_upload_date="2022-05-31"
youtube_thumbnail="https://i.ytimg.com/vi/qU32rTy_kOM/maxresdefault.jpg"
comments = true
+++



---
You are given a binary string s and an integer k. Your task is to determine if every possible binary code of length k appears as a substring within s. Return true if all such binary codes are present, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string s and an integer k, where s represents a binary number and k specifies the length of binary codes to check.
- **Example:** `Input: s = "1101011", k = 2`
- **Constraints:**
	- 1 <= s.length <= 5 * 10^5
	- s[i] is either '0' or '1'.
	- 1 <= k <= 20

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if every possible binary code of length k exists as a substring of s. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output is a boolean value indicating whether every binary code of length k exists in the string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if all binary codes of length k are present as substrings of s.

- Initialize a set to store the binary codes of length k that appear as substrings.
- Iterate over the string s, checking each substring of length k.
- For each substring, add it to the set.
- If the set size equals 2^k, then all possible binary codes of length k have been found.
{{< dots >}}
### Problem Assumptions ✅
- The input string s is valid and contains only '0' and '1'.
- The integer k is at most 20, ensuring that checking all binary codes of length k is feasible.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = "00110110", k = 2`  \
  **Explanation:** Output: true. The binary codes of length 2 are "00", "01", "10", and "11", and all of them appear as substrings in s.

- **Input:** `Input: s = "0110", k = 1`  \
  **Explanation:** Output: true. The binary codes of length 1 are "0" and "1", and both appear as substrings in s.

- **Input:** `Input: s = "0110", k = 2`  \
  **Explanation:** Output: false. The binary code "00" is missing as a substring in s.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a sliding window approach to efficiently check every substring of length k in the string s.

### Initial Thoughts 💭
- The number of unique binary codes of length k is 2^k.
- We need to efficiently check for all possible binary codes of length k in s.
- A sliding window can help extract each substring of length k from s, and a set can be used to track unique substrings.
{{< dots >}}
### Edge Cases 🌐
- If the string s is empty, return false as no substrings can exist.
- For large inputs where s has the maximum length (500,000 characters), ensure the solution remains efficient.
- If k equals the length of the string, check if the string itself is a valid substring.
- Handle cases where the string is smaller than 2^k, which means not all possible binary codes can be present.
{{< dots >}}
## Code 💻
```cpp
bool hasAllCodes(string s, int k) {
    
    int n = s.size();
    set<int> cnt;
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(i < k) {
            tmp = tmp * 2 + (s[i] == '0'? 0: 1);
            continue;
        }
        cnt.insert(tmp);
        tmp *= 2;
        tmp &= ((1 << k) - 1);            
        tmp += (s[i] == '0'? 0: 1);
    }
    cnt.insert(tmp);
    // cout << cnt.size() << " " << (1 << k);
    return cnt.size() == (1 << k);
}
```

This code defines the function `hasAllCodes`, which checks if a binary string `s` contains all possible binary codes of length `k`. The function iterates through the string, generating each k-length binary substring and adding it to a set. If the set's size equals the total number of possible binary codes (2^k), it returns `true`; otherwise, `false`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool hasAllCodes(string s, int k) {
	```
	Define the function `hasAllCodes`, which takes a string `s` and an integer `k` as input and returns a boolean value indicating whether all binary strings of length `k` are present in `s`.

2. **String Size**
	```cpp
	    int n = s.size();
	```
	Store the length of the input string `s` in variable `n`.

3. **Set Declaration**
	```cpp
	    set<int> cnt;
	```
	Declare a set `cnt` to store unique binary integers corresponding to substrings of length `k`.

4. **Initialization**
	```cpp
	    int tmp = 0;
	```
	Initialize the variable `tmp` to 0, which will store the current k-length binary number being processed.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop that iterates through each character of the string `s`.

6. **Condition Check**
	```cpp
	        if(i < k) {
	```
	Check if the current index `i` is less than `k`. This ensures the first `k` characters are processed correctly.

7. **Binary Conversion**
	```cpp
	            tmp = tmp * 2 + (s[i] == '0'? 0: 1);
	```
	Update `tmp` by shifting its bits left and adding the current character (0 or 1) of the string `s` to it.

8. **Continue**
	```cpp
	            continue;
	```
	Skip the rest of the loop for the current iteration since the set is only populated after `k` characters.

9. **Insert into Set**
	```cpp
	        cnt.insert(tmp);
	```
	Insert the current value of `tmp` into the set `cnt` to track the unique k-length binary numbers.

10. **Shift and Mask**
	```cpp
	        tmp *= 2;
	```
	Shift the bits of `tmp` left by 1 to make room for the next bit.

11. **Masking**
	```cpp
	        tmp &= ((1 << k) - 1);            
	```
	Apply a mask to keep only the last `k` bits of `tmp`, ensuring that the value fits within `k` bits.

12. **Update Binary Value**
	```cpp
	        tmp += (s[i] == '0'? 0: 1);
	```
	Add the current character (either 0 or 1) from `s` to `tmp` to form the new k-length binary number.

13. **Final Insert**
	```cpp
	    cnt.insert(tmp);
	```
	After the loop, insert the final value of `tmp` into the set `cnt` to ensure it is considered.

14. **Return Statement**
	```cpp
	    return cnt.size() == (1 << k);
	```
	Return `true` if the size of the set `cnt` equals the total number of possible k-length binary strings (2^k), otherwise return `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the length of the string s, as we slide through the string once and check substrings of length k.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(2^k)

The space complexity is O(2^k) for storing the unique binary substrings of length k in the set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/)

---
{{< youtube qU32rTy_kOM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
