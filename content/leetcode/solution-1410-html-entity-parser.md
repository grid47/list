
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The task is to convert a string containing HTML entities into its corresponding characters. HTML entities are special character sequences that start with an ampersand (`&`) and end with a semicolon (`;`). For example, `&quot;` represents a double quote (`"`), `&apos;` represents an apostrophe (`'`), `&amp;` represents an ampersand (`&`), and so on. The challenge is to parse a given string, replace all HTML entities with their actual characters, and return the resulting string.

### Approach

To solve this problem, we can follow a systematic approach:

1. **Mapping HTML Entities**: Create a map (or dictionary) that associates each HTML entity with its corresponding character.

2. **Iterating Through the String**: Traverse the input string character by character:
   - When an ampersand (`&`) is encountered, start building a potential HTML entity string.
   - Continue appending characters until a semicolon (`;`) is found or another ampersand is detected.
   - If a semicolon is reached, check if the collected string matches any key in the map.
   - Replace the entity with the mapped character if it exists; otherwise, include it as is.

3. **Building the Result**: Construct the result string by appending either the mapped character or the original sequence to it.

### Code Breakdown (Step by Step)

Below is a detailed breakdown of the provided C++ code that implements the above approach:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```

   - A class named `Solution` is defined, containing the method `entityParser`.

2. **Function Declaration**:
   ```cpp
       string entityParser(string text) {
   ```

   - The `entityParser` function takes a single parameter `text`, which is a string that may contain HTML entities.

3. **Mapping HTML Entities**:
   ```cpp
           map<string, string> mp;
           mp["&quot;"] = "\"";
           mp["&apos;"] = "\'";
           mp["&amp;"] = "&";
           mp["&gt;"] = ">";
           mp["&lt;"] = "<";
           mp["&frasl;"] = "/";
   ```

   - A map named `mp` is created to store the mapping of HTML entities to their respective characters.
   - Each entity is associated with its corresponding character.

4. **Result Initialization**:
   ```cpp
           string res = "";        
           int i = 0;
   ```

   - An empty string `res` is initialized to build the final result.
   - A variable `i` is initialized to iterate through the characters of the input string.

5. **Iterating Through the String**:
   ```cpp
           while(i < text.size()) {
               if(text[i] == '&') {
   ```

   - A while loop is set up to traverse the string until all characters are processed.
   - Inside the loop, a check is performed to see if the current character is an ampersand (`&`).

6. **Building the Entity String**:
   ```cpp
                   string tmp = "";
                   while(i < text.size() && text[i] != ';'){
                       tmp += text[i++];
                       if(i < text.size() && text[i] == '&') {
                           res += tmp;
                           tmp = "";
                       }
                   }
   ```

   - If an ampersand is found, a temporary string `tmp` is initialized to collect characters for the entity.
   - A nested while loop collects characters until a semicolon (`;`) is reached or another ampersand is encountered.
   - If another ampersand is detected before the semicolon, the collected characters are added to the result, and the temporary string is reset.

7. **Handling the Semicolon**:
   ```cpp
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
   ```

   - If a semicolon is reached, it is appended to `tmp`, and the program checks if `tmp` is a valid HTML entity in the map.
   - If it is, the corresponding character is appended to `res`. If not, the original `tmp` (which contains the entity without translation) is added to the result.
   - If the current character is not an ampersand, it is simply appended to the result.

8. **Returning the Result**:
   ```cpp
           return res;
       }
   };
   ```

   - After processing the entire input string, the function returns the constructed result string `res`.

### Complexity

- **Time Complexity**:
  - The time complexity of this solution is \( O(n) \), where \( n \) is the length of the input string. This is because we traverse the string character by character, processing each character in constant time.

- **Space Complexity**:
  - The space complexity is \( O(m) \), where \( m \) is the number of unique HTML entities stored in the map. Additionally, the space required for the output string `res` is also accounted for in this complexity.

### Conclusion

The implementation of the `entityParser` function effectively converts HTML entities into their respective characters using a straightforward mapping approach and string traversal. This solution is efficient and clean, demonstrating a solid understanding of string manipulation and the use of maps for quick lookups.

#### Key Takeaways:

- **String Processing**: This code exemplifies the importance of careful string manipulation, especially when dealing with special characters or encodings.

- **Mapping for Efficiency**: Using a map to store the relationships between entities and characters allows for rapid lookups, making the parsing efficient.

- **Robustness in Handling Input**: The algorithm is robust enough to handle cases where entities might be malformed or where there are adjacent ampersands, ensuring that the output remains consistent with the input requirements.

Overall, this solution serves as an excellent example of parsing problems in programming, offering insights into effective techniques for handling strings and special characters in a computational context.

[`Link to LeetCode Lab`](https://leetcode.com/problems/html-entity-parser/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
