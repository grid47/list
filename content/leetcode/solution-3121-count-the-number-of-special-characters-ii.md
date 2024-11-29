
+++
authors = ["grid47"]
title = "Leetcode 3121: Count the Number of Special Characters II"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3121: Count the Number of Special Characters II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aIR3Iem0jQM"
youtube_upload_date="2024-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/aIR3Iem0jQM/maxresdefault.webp"
comments = true
+++



---
You are given a string `word`. A letter `c` is called special if it appears both in lowercase and uppercase in `word`, and every lowercase occurrence of `c` appears before the first uppercase occurrence of `c`. Return the number of special letters in `word`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `word` of length n.
- **Example:** `word = "abcABca"`
- **Constraints:**
	- 1 <= word.length <= 2 * 10^5
	- word consists of only lowercase and uppercase English letters

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of special letters in the string `word`.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify letters that appear in both lowercase and uppercase in the string and check if every lowercase occurrence precedes the first uppercase occurrence.

- 1. Initialize a vector of size 26 to keep track of the occurrences of each letter in `word`.
- 2. Loop through the string and update the vector to mark the status of each character.
- 3. After processing the string, check which letters have both lowercase and uppercase occurrences where all lowercase letters precede the uppercase ones.
- 4. Count and return the total number of such special letters.
{{< dots >}}
### Problem Assumptions ✅
- The input string will only contain lowercase and uppercase English letters.
- The string will have a length between 1 and 2 * 10^5 characters.
{{< dots >}}
## Examples 🧩
- **Input:** `word = "abcABca"`  \
  **Explanation:** The special characters are 'a' and 'b', because they appear in both lowercase and uppercase, and all lowercase occurrences precede the uppercase ones.

- **Input:** `word = "hello"`  \
  **Explanation:** No special characters exist in this string, as no letter appears in both uppercase and lowercase.

- **Input:** `word = "AaaBcAB"`  \
  **Explanation:** The letter 'a' appears both in lowercase and uppercase, but the lowercase 'a' occurs after the uppercase 'A', so it's not special.

{{< dots >}}
## Approach 🚀
We can solve this problem by iterating through the string, marking occurrences of each character in a vector, and then checking the conditions for special letters.

### Initial Thoughts 💭
- We need to check the order of lowercase and uppercase occurrences of each letter.
- By using a vector to track the occurrences and then validating the conditions for each letter, we can efficiently solve the problem.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one character, as per the problem constraints.
- The solution should efficiently handle strings of up to 2 * 10^5 characters.
- If the string contains only lowercase or only uppercase letters, the output should be 0.
- The string consists only of lowercase and uppercase English letters.
{{< dots >}}
## Code 💻
```cpp
int numberOfSpecialChars(string word) {
    vector<int> ch(26, 0);
    for(char x: word) {
        if(isupper(x)) {
            if(ch[x - 'A'] == -1) continue;
            if(ch[x - 'A'] != 1 && ch[x - 'A'] != 2)  {
              ch[x - 'A'] = -1;
                continue;  
            }
            ch[x - 'A'] = 2;
        } else {
            if(ch[x - 'a'] == -1) continue;                
            if(ch[x - 'a'] == 2) {
              ch[x - 'a'] = -1;
                continue;  
            } 
            ch[x - 'a'] = 1;
        }
        // cout << x << " ";
        // for(int i = 0; i < 26; i++) {
        //     cout << ch[i] << " ";
        // }
        // cout << "\n";
    }
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        // cout << ch[i] << " ";
        if(ch[i] == 2)
            cnt++;
    }
    return cnt;        
}
```

This function calculates the number of special characters in the string `word`, considering both uppercase and lowercase letter pairs. A letter pair is considered special if both the uppercase and lowercase forms of the letter appear in the string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfSpecialChars(string word) {
	```
	Defines the function `numberOfSpecialChars` that takes a string `word` as input and returns the count of special characters, where a special character is a pair of the same letter in both lowercase and uppercase.

2. **Array Initialization**
	```cpp
	    vector<int> ch(26, 0);
	```
	Initializes a vector `ch` of size 26 to keep track of the status of each letter. The vector elements will hold values representing the status of each character (0 = not encountered, 1 = lowercase encountered, 2 = uppercase encountered, -1 = both encountered and invalid).

3. **Loop Through String**
	```cpp
	    for(char x: word) {
	```
	Iterates through each character `x` in the string `word`.

4. **Check Uppercase Character**
	```cpp
	        if(isupper(x)) {
	```
	Checks if the current character `x` is uppercase.

5. **Handle Invalid Uppercase**
	```cpp
	            if(ch[x - 'A'] == -1) continue;
	```
	If the uppercase version of the character has already been invalidated, skips to the next character.

6. **Check Uppercase Validity**
	```cpp
	            if(ch[x - 'A'] != 1 && ch[x - 'A'] != 2) {
	```
	Checks if the uppercase character has been encountered in an invalid state or hasn't been encountered yet.

7. **Invalidate Uppercase**
	```cpp
	              ch[x - 'A'] = -1;
	```
	Marks the uppercase version of the character as invalid.

8. **Continue to Next Character**
	```cpp
	                continue;  
	```
	Skips to the next character in the loop if the current character has been invalidated.

9. **Mark Uppercase Valid**
	```cpp
	            ch[x - 'A'] = 2;
	```
	Marks the uppercase version of the character as encountered and valid.

10. **Handle Lowercase Character**
	```cpp
	        } else {
	```
	If the character is lowercase, execute the following logic for lowercase characters.

11. **Handle Invalid Lowercase**
	```cpp
	            if(ch[x - 'a'] == -1) continue;
	```
	If the lowercase version of the character has already been invalidated, skips to the next character.

12. **Check Lowercase Validity**
	```cpp
	            if(ch[x - 'a'] == 2) {
	```
	Checks if the lowercase character has been encountered in a valid state (both cases present).

13. **Invalidate Lowercase**
	```cpp
	              ch[x - 'a'] = -1;
	```
	Marks the lowercase version of the character as invalid.

14. **Continue to Next Character**
	```cpp
	                continue;  
	```
	Skips to the next character in the loop if the current character has been invalidated.

15. **Set Lowercase to 1**
	```cpp
	            ch[x - 'a'] = 1;
	```
	Marks the lowercase character as encountered.

16. **Count Special Characters**
	```cpp
	    int cnt = 0;
	```
	Initializes the counter `cnt` to count the number of special characters (pairs of both uppercase and lowercase versions of the same letter).

17. **Loop Through Alphabet**
	```cpp
	    for(int i = 0; i < 26; i++) {
	```
	Iterates through the `ch` array to count the special characters.

18. **Check Special Character**
	```cpp
	        if(ch[i] == 2)
	```
	Checks if both uppercase and lowercase versions of the letter are present, which indicates a special character.

19. **Increment Counter**
	```cpp
	            cnt++;
	```
	Increments the counter `cnt` when a special character is found.

20. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the total count of special characters.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the string. We process each character in the string once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only store information for each letter in a fixed-size vector.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

---
{{< youtube aIR3Iem0jQM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
