
+++
authors = ["grid47"]
title = "Leetcode 2384: Largest Palindromic Number"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2384: Largest Palindromic Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IMktz_WlNYo"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/IMktz_WlNYo/maxresdefault.jpg"
comments = true
+++



---
You are given a string `num` consisting only of digits. Your task is to form the largest possible palindromic number by rearranging the digits of `num`. The resulting number should not have leading zeros and must use at least one digit from the string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `num` of length `n` containing only digits.
- **Example:** `Input: num = '123321'`
- **Constraints:**
	- 1 <= num.length <= 10^5
	- num consists of digits only.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest palindromic number that can be formed from the digits of `num`. The result should be a string.
- **Example:** `Output: '321123'`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To form the largest possible palindromic number from the digits, rearrange them to maximize the digits in the left half and mirror them on the right side.

- 1. Count the occurrences of each digit in the string.
- 2. Build the first half of the palindrome by placing as many pairs of digits as possible in descending order.
- 3. If there is any digit with an odd count, place it in the center of the palindrome.
- 4. Mirror the first half to create the full palindrome.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain at least one non-zero digit.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = '123321'`  \
  **Explanation:** In this example, we can rearrange the digits to form '321123', which is the largest palindromic number. The digits are arranged so that the first half is mirrored to the second half.

- **Input:** `Input: num = '00009'`  \
  **Explanation:** In this case, the only non-zero digit is '9', so the largest palindromic number we can form is simply '9'.

{{< dots >}}
## Approach 🚀
The problem can be approached by counting the frequency of each digit in the string and then arranging them to maximize the palindrome. The key steps are forming pairs for the left and right halves of the palindrome and placing any remaining odd digit in the center.

### Initial Thoughts 💭
- A palindrome must have the same digits in reverse order, so we need to carefully distribute the digits to form a symmetric structure.
- By focusing on maximizing the left half of the palindrome, we can easily generate the largest possible palindrome.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one digit.
- The solution should efficiently handle input strings of length up to 100,000.
- If the input consists only of zeros, the result should be '0'.
- If there are multiple occurrences of the same digit, they should be grouped together to form the largest palindrome.
- The solution should not generate palindromes with leading zeros unless the palindrome is '0'.
{{< dots >}}
## Code 💻
```cpp
string largestPalindromic(string num) {
    int cnt[10] = {}, mid = -1;
    string s;

    for(char c: num) cnt[c - '0']++;

    for(int i = 9; i > 0; i--) {
        if(cnt[i] == 0) continue;
        s.append(cnt[i]/2, i + '0');
        if(mid == -1 && (cnt[i]&1))
                mid = i;
    }

    if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
    mid = mid == -1 && (cnt[0] & 1)? 0: mid;
    if(mid != -1) s.push_back(mid + '0');
    s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());

    return s != ""? s : "0";
}
```

This function takes a string of digits and finds the largest possible palindromic number by rearranging the digits, ensuring that it returns a valid palindrome. If no palindrome can be formed, it returns "0".

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string largestPalindromic(string num) {
	```
	This line defines the function 'largestPalindromic' which takes a string 'num' representing the number whose largest palindromic arrangement is to be found.

2. **Variable Initialization**
	```cpp
	    int cnt[10] = {}, mid = -1;
	```
	This initializes an array 'cnt' to keep track of the count of each digit (0-9), and 'mid' is used to store the middle digit for the palindrome.

3. **Variable Declaration**
	```cpp
	    string s;
	```
	A string 's' is declared which will hold the left half of the palindromic number as it's built.

4. **For Loop**
	```cpp
	    for(char c: num) cnt[c - '0']++;
	```
	This loop iterates over each character in the input string 'num', converting it to an integer, and increments the corresponding count in the 'cnt' array.

5. **For Loop**
	```cpp
	    for(int i = 9; i > 0; i--) {
	```
	This loop processes the digits in descending order, starting from 9, to form the largest possible palindrome.

6. **Condition Check**
	```cpp
	        if(cnt[i] == 0) continue;
	```
	If there are no occurrences of the current digit 'i', the loop skips to the next iteration.

7. **String Append**
	```cpp
	        s.append(cnt[i]/2, i + '0');
	```
	This appends half the occurrences of digit 'i' to the string 's' to form the left half of the palindrome.

8. **Mid Digit Assignment**
	```cpp
	        if(mid == -1 && (cnt[i]&1))
	```
	Checks if 'mid' is unassigned and if the current digit 'i' occurs an odd number of times, setting 'mid' to 'i'.

9. **Mid Digit Assignment**
	```cpp
	                mid = i;
	```
	Sets 'mid' to 'i' as it will be placed in the center of the palindrome if it's the only odd occurrence.

10. **Condition Check**
	```cpp
	    if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
	```
	If 's' has any digits and the digit '0' occurs, it appends half of the occurrences of '0' to 's'.

11. **Mid Digit Adjustment**
	```cpp
	    mid = mid == -1 && (cnt[0] & 1)? 0: mid;
	```
	If 'mid' was not assigned, it checks if '0' has an odd count, assigning '0' as 'mid' if necessary.

12. **Mid Digit Check**
	```cpp
	    if(mid != -1) s.push_back(mid + '0');
	```
	If 'mid' is assigned, it appends the 'mid' digit to the center of the string.

13. **String Reverse**
	```cpp
	    s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());
	```
	This inserts the reverse of the left half of the string 's' to form the right half of the palindrome.

14. **Return Statement**
	```cpp
	    return s != ""? s : "0";
	```
	Returns the constructed palindromic string, or '0' if the string is empty (meaning no palindrome could be formed).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in relation to the length of the input string, as we process each digit only once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only need a small fixed amount of extra space to store the digit counts and the palindrome.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-palindromic-number/description/)

---
{{< youtube IMktz_WlNYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
