
+++
authors = ["grid47"]
title = "Leetcode 831: Masking Personal Information"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 831: Masking Personal Information in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gBPqkLohQvg"
youtube_upload_date="2024-08-16"
youtube_thumbnail="https://i.ytimg.com/vi/gBPqkLohQvg/maxresdefault.jpg"
comments = true
+++



---
You are given a string representing either an email address or a phone number. The task is to mask the personal information by following specific rules. For email addresses, the name and domain should be in lowercase, and the middle letters of the name should be replaced with asterisks. For phone numbers, any non-digit characters should be removed, and the number should be masked with asterisks based on the country code and local number.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a string containing either a valid email address or a valid phone number.
- **Example:** `Input: s = 'JaneDoe@domain.com'`
- **Constraints:**
	- If the input is an email, the length will be between 8 and 40 characters.
	- If the input is a phone number, the length will be between 10 and 20 characters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the masked version of the input string, either an email address or a phone number, according to the specified rules.
- **Example:** `Output: 'j*****e@domain.com'`
- **Constraints:**
	- The output must follow the masking rules provided for emails and phone numbers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to mask the personal information string based on whether it is an email or a phone number, following the specified rules for each case.

- Step 1: Check if the string contains '@', which indicates it is an email address.
- Step 2: For emails, convert all characters to lowercase and replace the middle part of the name with asterisks.
- Step 3: If it is a phone number, remove all non-digit characters and mask the number based on the number of digits in the country code.
{{< dots >}}
### Problem Assumptions ✅
- The input string is always a valid email address or a phone number.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: s = 'JohnSmith@Example.com'`  \
  **Explanation:** This is an email address. We convert the entire string to lowercase and replace the middle part of the name with asterisks: 'j*****h@example.com'.

- **Input:** `Input: s = '1(234)567-890'`  \
  **Explanation:** This is a phone number. After removing the non-digit characters, the number becomes '1234567890'. As it has no country code, it is masked as '***-***-7890'.

{{< dots >}}
## Approach 🚀
The approach involves identifying whether the input is an email address or a phone number, and applying the corresponding masking rules. For emails, it is essential to handle the name and domain separately, while for phone numbers, we focus on removing separators and masking the digits appropriately.

### Initial Thoughts 💭
- We need to differentiate between email and phone number formats first.
- For emails, it is important to only mask the middle characters of the name, while preserving the first and last letters.
- The main challenge is to identify whether the input is an email or a phone number, and then apply the corresponding masking rules.
{{< dots >}}
### Edge Cases 🌐
- Empty strings should not be provided, as the input must be either a valid email or phone number.
- The solution must efficiently handle inputs at the maximum length (up to 20 characters for phone numbers).
- Ensure the solution handles cases where the country code is missing or there is only one or two digits in the country code.
- The solution must not assume the input format is always perfectly standardized and should account for different separator symbols in phone numbers.
{{< dots >}}
## Code 💻
```cpp
vector<string> country = {"", "+*-", "+**-", "+***-"};
string maskPII(string s) {
    string res;
    int at = s.find('@');
    if(at != string::npos) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s.substr(0, 1) + "*****" + s.substr(at - 1);
    }
    s = regex_replace(s, regex("[^0-9]"), "");
    return country[s.size() - 10]  + "***-***-" + s.substr(s.size() - 4);
}
```

This code masks Personally Identifiable Information (PII) in an email or phone number. It formats the email or phone number to a masked version, showing only the first character or area code, with the remaining characters replaced by asterisks.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<string> country = {"", "+*-", "+**-", "+***-"};
	```
	Initialize a vector of strings called `country` containing country-specific phone number formatting options based on length.

2. **Function Declaration**
	```cpp
	string maskPII(string s) {
	```
	Define the function `maskPII` that takes a string `s` and returns a masked version of the string, either as an email or phone number.

3. **Variable Declaration**
	```cpp
	    string res;
	```
	Declare a string variable `res` that will hold the result of the masking process.

4. **Find '@'**
	```cpp
	    int at = s.find('@');
	```
	Find the position of '@' in the string `s` (email address).

5. **Condition Check for Email**
	```cpp
	    if(at != string::npos) {
	```
	Check if the '@' character is found in the string, which would indicate that the input is an email address.

6. **Transform to Lowercase**
	```cpp
	        transform(s.begin(), s.end(), s.begin(), ::tolower);
	```
	Convert all characters in the string `s` to lowercase to ensure consistent formatting for email.

7. **Mask Email**
	```cpp
	        return s.substr(0, 1) + "*****" + s.substr(at - 1);
	```
	For an email, return the first character, followed by five asterisks, and the part of the email after '@'.

8. **Phone Number Cleaning**
	```cpp
	    s = regex_replace(s, regex("[^0-9]"), "");
	```
	Remove any non-digit characters from the string, leaving only numbers, in case the input is a phone number.

9. **Mask Phone Number**
	```cpp
	    return country[s.size() - 10]  + "***-***-" + s.substr(s.size() - 4);
	```
	For a phone number, format it based on its length using a corresponding pattern from `country` and return the masked phone number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input string. The best case occurs when no replacements are needed.
- **Average Case:** O(n), as we process the string character by character.
- **Worst Case:** O(n), since the solution involves parsing and manipulating each character in the string.

The time complexity is linear in terms of the length of the input string.

### Space Complexity 💾
- **Best Case:** O(1), if no additional space is required apart from the input string itself.
- **Worst Case:** O(n), where n is the length of the input string, due to the storage needed for the masked version of the input.

The space complexity is linear with respect to the length of the input string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/masking-personal-information/description/)

---
{{< youtube gBPqkLohQvg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
