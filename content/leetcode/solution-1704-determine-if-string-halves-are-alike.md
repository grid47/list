
+++
authors = ["grid47"]
title = "Leetcode 1704: Determine if String Halves Are Alike"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1704: Determine if String Halves Are Alike in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6svsUO6X8g"
youtube_upload_date="2020-12-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/n6svsUO6X8g/maxresdefault.webp"
comments = true
+++



---
You are given a string 's' of even length. Split the string into two equal halves, where the first half is 'a' and the second half is 'b'.

Two strings are considered alike if they contain the same number of vowels (a, e, i, o, u, A, E, I, O, U). Return 'true' if 'a' and 'b' are alike, otherwise return 'false'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string 's' of even length.
- **Example:** `"hellohello"`
- **Constraints:**
	- 2 <= s.length <= 1000
	- s.length is even.
	- s consists of uppercase and lowercase letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return 'true' if the first half and the second half of the string contain the same number of vowels, otherwise return 'false'.
- **Example:** `"true"`
- **Constraints:**
	- The output should be a boolean value: 'true' or 'false'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the first and second halves of the string contain an equal number of vowels.

- 1. Split the string 's' into two halves: 'a' and 'b'.
- 2. Count the vowels in both halves.
- 3. Compare the vowel count of 'a' and 'b'.
- 4. If both halves contain the same number of vowels, return 'true'. Otherwise, return 'false'.
{{< dots >}}
### Problem Assumptions ✅
- The input string has even length.
- The input contains only English alphabet letters, both uppercase and lowercase.
{{< dots >}}
## Examples 🧩
- **Input:** `"hellohello"`  \
  **Explanation:** In this example, split the string into 'hello' and 'hello'. Both halves contain 2 vowels ('e' and 'o' in each half), so the result is 'true'.

- **Input:** `"textbooktextbook"`  \
  **Explanation:** Here, split the string into 'textbook' and 'textbook'. The first half contains 2 vowels ('e' and 'o'), and the second half contains 3 vowels ('e', 'o', 'o'). Therefore, the result is 'false'.

{{< dots >}}
## Approach 🚀
The approach is to split the string into two halves, count the vowels in each half, and compare the counts. If they are the same, return 'true'; otherwise, return 'false'.

### Initial Thoughts 💭
- The problem involves comparing vowel counts in two halves of a string.
- A direct comparison of the vowel counts in both halves should solve the problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input string length is guaranteed to be at least 2, so empty strings are not a concern.
- Ensure that the solution can handle input strings of length up to 1000 efficiently.
- If the string contains no vowels in either half, the result should be 'true' as long as both halves are identical in vowel count.
- The string length must be even, and it will only contain uppercase and lowercase alphabetic characters.
{{< dots >}}
## Code 💻
```cpp
bool halvesAreAlike(string s) {
    int t=0;
    for(int i=0;i<s.size();i++)
    {   
        s[i]=tolower(s[i]);
        if(i<s.size()/2)
        {
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                  t++;                  // counting for the first half of the string
        }
        else
        {
            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                 t--;            // reducing the count if occures in second half of the string 
        }     
    } 
   return (t==0);
}
```

This function checks whether the two halves of a given string have the same number of vowels. It counts vowels in the first half and subtracts the count for vowels in the second half. The string is considered 'alike' if the counts match.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool halvesAreAlike(string s) {
	```
	Defines the function `halvesAreAlike`, which determines if the two halves of a string have an equal number of vowels.

2. **Variable Initialization**
	```cpp
	    int t=0;
	```
	Initializes an integer variable `t` to keep track of the difference between the number of vowels in the first and second halves of the string.

3. **Iterate Through String**
	```cpp
	    for(int i=0;i<s.size();i++)
	```
	Starts a loop that iterates through each character of the string `s`.

4. **Convert to Lowercase**
	```cpp
	        s[i]=tolower(s[i]);
	```
	Converts the current character to lowercase to ensure the comparison is case-insensitive.

5. **Check First Half**
	```cpp
	        if(i<s.size()/2)
	```
	Checks if the current index is in the first half of the string.

6. **Count Vowels in First Half**
	```cpp
	            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
	```
	Checks if the current character is a vowel (one of 'a', 'e', 'i', 'o', 'u') in the first half of the string.

7. **Increment Vowel Count for First Half**
	```cpp
	                  t++;                  // counting for the first half of the string
	```
	Increments the `t` counter when a vowel is found in the first half of the string.

8. **Check Second Half**
	```cpp
	        else
	```
	Checks if the current index is in the second half of the string.

9. **Count Vowels in Second Half**
	```cpp
	            if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
	```
	Checks if the current character is a vowel (one of 'a', 'e', 'i', 'o', 'u') in the second half of the string.

10. **Decrement Vowel Count for Second Half**
	```cpp
	                 t--;            // reducing the count if occures in second half of the string 
	```
	Decrements the `t` counter when a vowel is found in the second half of the string.

11. **Check Vowel Count Equality**
	```cpp
	   return (t==0);
	```
	Checks if the counter `t` is equal to zero, which would indicate that the number of vowels in both halves is the same.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string. The best case occurs when the string has only one vowel in each half.
- **Average Case:** O(n), where n is the length of the string. We need to traverse each half to count the vowels.
- **Worst Case:** O(n), where n is the length of the string. The solution involves traversing the string to count vowels.

The time complexity is linear with respect to the input size, making the solution efficient even for large inputs.

### Space Complexity 💾
- **Best Case:** O(1), since no extra space is required apart from counters for vowels.
- **Worst Case:** O(1), as the space used for counting vowels is constant.

The space complexity is constant, as we only need a few variables to count vowels and compare the two halves.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/determine-if-string-halves-are-alike/description/)

---
{{< youtube n6svsUO6X8g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
