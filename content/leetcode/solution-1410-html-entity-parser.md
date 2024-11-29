
+++
authors = ["grid47"]
title = "Leetcode 1410: HTML Entity Parser"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1410: HTML Entity Parser in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are tasked with decoding a string that contains HTML entities. The HTML entities represent special characters like quotation marks, ampersands, greater-than signs, etc. You need to replace the HTML entities with their respective characters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string with HTML entities.
- **Example:** `text = "The &quot;HTML&quot; language is popular."`
- **Constraints:**
	- 1 <= text.length <= 105
	- The string can contain any ASCII character.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the decoded string where all the HTML entities are replaced by their corresponding characters.
- **Example:** `The output will be "The HTML language is popular."`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Replace HTML entities in the string with their corresponding characters.

- Initialize a map with HTML entity to character mappings.
- Iterate through the string, find any entity starting with '&' and ending with ';'.
- Check if the found entity exists in the map and replace it.
- Return the final decoded string.
{{< dots >}}
### Problem Assumptions ✅
- The input string contains valid HTML entities.
- Entities are well-formed and properly enclosed in '&' and ';'.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: text = "The &quot;HTML&quot; language is popular."`  \
  **Explanation:** The parser will replace the entity &quot; with " to produce the decoded string: "The HTML language is popular."

{{< dots >}}
## Approach 🚀
To solve this problem, we'll map the HTML entities to their corresponding characters and then iterate over the string to replace any encountered entities.

### Initial Thoughts 💭
- HTML entities are enclosed by '&' and ';'.
- Each entity corresponds to a special character.
- We can use a map to store the mappings and process the string character by character.
{{< dots >}}
### Edge Cases 🌐
- Handle an empty string input.
- Ensure that the solution handles strings near the upper constraint of length 105.
- Consider cases where there are no entities in the input.
- Ensure all HTML entities are valid and properly closed with ';'.
{{< dots >}}
## Code 💻
```cpp
string entityParser(string text) {
    
    map<string, string> mp;
    mp["&quot;"] = "\"";
    mp["&apos;"] = "\'";
    mp["&amp;"] = "&";
    mp["&gt;"] = ">";
    mp["&lt;"] = "<";
    mp["&frasl;"] = "/";
    
    string res = "";        
    int i = 0;
    while(i < text.size()) {
        if(text[i] == '&') {
            string tmp = "";
            while(i < text.size() && text[i] != ';'){
                tmp += text[i++];
                if(i < text.size() && text[i] == '&') {
                    res += tmp;
                    tmp = "";
                }
            } 
            if(text[i] == ';') {
                i++;
                tmp += ';';
                if(mp.count(tmp)) {
                    res += mp[tmp];
                } else {
                    res += tmp;
                }
            } else {
                res += tmp;
            }
        } else {
            res += text[i++];
        }
    }
    return res;
}
```

The function `entityParser` processes an input string `text` and replaces certain HTML entities like `&quot;`, `&amp;`, and others with their respective character representations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **String Manipulations**
	```cpp
	string entityParser(string text) {
	```
	This line defines the function `entityParser`, which takes a string `text` as input and returns a modified version of it.

2. **Variable Initialization**
	```cpp
	    map<string, string> mp;
	```
	A map `mp` is initialized to store key-value pairs for replacing HTML entities with their corresponding characters.

3. **Map Operations**
	```cpp
	    mp["&quot;"] = "\"";
	```
	Here, the `&quot;` HTML entity is mapped to the double quote `"` character.

4. **Map Operations**
	```cpp
	    mp["&apos;"] = "\'";
	```
	The `&apos;` entity is mapped to the single quote \'\' character.

5. **Map Operations**
	```cpp
	    mp["&amp;"] = "&";
	```
	The `&amp;` entity is mapped to the `&` character.

6. **Map Operations**
	```cpp
	    mp["&gt;"] = ">";
	```
	The `&gt;` entity is mapped to the greater-than `>` character.

7. **Map Operations**
	```cpp
	    mp["&lt;"] = "<";
	```
	The `&lt;` entity is mapped to the less-than `<` character.

8. **Map Operations**
	```cpp
	    mp["&frasl;"] = "/";
	```
	The `&frasl;` entity is mapped to the forward slash `/` character.

9. **Variable Initialization**
	```cpp
	    string res = "";        
	```
	The variable `res` is initialized as an empty string to accumulate the result.

10. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	The variable `i` is initialized to 0 and will be used as the index to iterate through the input string `text`.

11. **Loop Constructs**
	```cpp
	    while(i < text.size()) {
	```
	A while loop is started to process each character in the input string `text`.

12. **Conditional Logic**
	```cpp
	        if(text[i] == '&') {
	```
	Checks if the current character is the `&` symbol, which indicates the start of an HTML entity.

13. **Variable Initialization**
	```cpp
	            string tmp = "";
	```
	A temporary string `tmp` is initialized to store potential HTML entities.

14. **Loop Constructs**
	```cpp
	            while(i < text.size() && text[i] != ';'){
	```
	A nested while loop is used to collect characters until a semicolon `;` (end of the entity) is found.

15. **String Manipulations**
	```cpp
	                tmp += text[i++];
	```
	Appends the current character to `tmp` and increments `i`.

16. **Conditional Logic**
	```cpp
	                if(i < text.size() && text[i] == '&') {
	```
	Checks if another `&` is encountered within the entity, in which case the current entity is complete.

17. **String Manipulations**
	```cpp
	                    res += tmp;
	```
	Appends the current entity in `tmp` to the result string `res`.

18. **Variable Initialization**
	```cpp
	                    tmp = "";
	```
	Resets the temporary string `tmp` to collect a new entity.

19. **Conditional Logic**
	```cpp
	            if(text[i] == ';') {
	```
	Checks if the current character is a semicolon, signaling the end of an HTML entity.

20. **Variable Initialization**
	```cpp
	                i++;
	```
	Increments `i` to move past the semicolon.

21. **String Manipulations**
	```cpp
	                tmp += ';';
	```
	Appends the semicolon to `tmp` to finalize the entity.

22. **Map Operations**
	```cpp
	                if(mp.count(tmp)) {
	```
	Checks if the entity `tmp` exists in the `mp` map.

23. **String Manipulations**
	```cpp
	                    res += mp[tmp];
	```
	If the entity is found in the map, its corresponding character is appended to the result string.

24. **String Manipulations**
	```cpp
	                } else {
	```
	Handles the case where the entity is not in the map.

25. **String Manipulations**
	```cpp
	                    res += tmp;
	```
	If the entity is not in the map, the raw entity is appended to the result string.

26. **Control Flow**
	```cpp
	            } else {
	```
	If the character is not `&`, append it to the result string.

27. **String Manipulations**
	```cpp
	                res += tmp;
	```
	Appends the accumulated characters in `tmp` to `res`.

28. **Loop Constructs**
	```cpp
	        } else {
	```
	If the character is not `&`, it is directly appended to the result.

29. **String Manipulations**
	```cpp
	            res += text[i++];
	```
	Appends the character to `res` and increments the index `i`.

30. **Return Statement**
	```cpp
	    return res;
	```
	Returns the processed string `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string.
- **Average Case:** O(n), as we need to process each character in the string.
- **Worst Case:** O(n), as we might encounter entities that require checking each character.

The time complexity is linear in relation to the length of the string.

### Space Complexity 💾
- **Best Case:** O(n), as we need to store the result string.
- **Worst Case:** O(n), where n is the length of the string.

The space complexity is linear due to the additional space used to store the decoded string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/html-entity-parser/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
