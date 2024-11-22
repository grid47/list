
+++
authors = ["grid47"]
title = "Leetcode 1961: Check If String Is a Prefix of Array"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1961: Check If String Is a Prefix of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "msS6F5DL8gQ"
youtube_upload_date="2021-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/msS6F5DL8gQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPrefixString(string s, vector<string>& w) {
        int k = 0, l = 0, i = 0;
        for(i = 0; i < s.size() && k < w.size(); i++) {
            
            if(s[i] != w[k][l]) return false;
            
            l++;
            
            if(l == w[k].size()) {
                k++;
                l = 0;
            }
        }
        if(i != s.size()) return false;
        return (l == 0);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine if a given string `s` is a prefix of the concatenation of a list of words `w`. A prefix is defined as a string that appears at the beginning of another string. In this case, we need to check if `s` can be formed by sequentially concatenating the strings in `w` from the start, in the given order.

### Approach

To solve this problem, we can use a straightforward iterative approach to simulate the concatenation of the words in `w` and check if it matches the string `s`. The algorithm will work by maintaining two pointers: one for the string `s` and another for the current word in `w`. The key steps of the approach are:

1. **Initialize Pointers**: Set up counters for tracking positions in the string `s` and the current word in `w`.

2. **Iterate Through the String**: Loop through each character of the string `s`, and compare it with the characters of the current word from `w`.

3. **Character Comparison**: If the characters match, move forward in the current word. If the end of the current word is reached, switch to the next word in `w`.

4. **Final Checks**: After traversing through `s`, ensure that the entire string has been matched and that the current word pointer is in a state that indicates a complete match.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
The `Solution` class is defined, which will encapsulate our function.

```cpp
    bool isPrefixString(string s, vector<string>& w) {
```
The function `isPrefixString` takes two parameters:
- `s`: the string we want to check.
- `w`: a vector of strings representing the list of words.

```cpp
        int k = 0, l = 0, i = 0;
```
We initialize three variables:
- `k`: to track the current word index in `w`.
- `l`: to track the character index within the current word.
- `i`: to track the character index within the string `s`.

```cpp
        for(i = 0; i < s.size() && k < w.size(); i++) {
```
We enter a loop that continues until we've processed all characters in `s` or have exhausted all words in `w`.

```cpp
            if(s[i] != w[k][l]) return false;
```
We compare the current character in `s` with the current character in the current word of `w`. If they do not match, we return `false`, indicating that `s` cannot be a prefix.

```cpp
            l++;
```
If the characters match, we move to the next character in the current word.

```cpp
            if(l == w[k].size()) {
                k++;
                l = 0;
            }
```
We check if we have reached the end of the current word. If we have, we move to the next word in `w` and reset the character index `l` to zero.

```cpp
        }
```
End of the loop.

```cpp
        if(i != s.size()) return false;
```
After the loop, we check if we have processed the entire string `s`. If not, we return `false`.

```cpp
        return (l == 0);
    }
};
```
Finally, we return `true` if the character pointer `l` is zero, indicating that the last word has been completely matched. If not, we return `false`.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the length of the string `s`. In the worst case, we may need to traverse all characters of `s` and compare them with the characters in `w`.

- **Space Complexity**: The space complexity is \(O(1)\) since we are using a constant amount of extra space (for the pointers) and not utilizing any additional data structures that scale with input size.

### Conclusion

The `isPrefixString` function effectively checks if the string `s` can be formed by the sequential concatenation of words in the vector `w`. By employing a simple iteration and character comparison approach, the solution remains efficient and easy to understand. This function can be particularly useful in scenarios involving string manipulation, parsing, or prefix matching in various applications such as text processing, search engines, or compilers.

### Key Features

1. **Direct Comparison**: The algorithm directly compares characters from `s` and the words in `w`, ensuring accurate prefix validation.
  
2. **Iterative Approach**: Using an iterative approach simplifies the logic, making it easy to follow and implement.

3. **Efficiency**: The function runs in linear time relative to the length of `s`, making it suitable for large inputs.

### Use Cases

This function can be applied in various scenarios, such as:
- **Search Autocompletion**: In search engines where prefix matching is crucial for suggesting search terms.
- **Text Parsing**: In natural language processing tasks where prefix identification can aid in syntax analysis or tokenization.
- **Game Development**: For scenarios where player input needs to match predefined commands or keywords.

### Example Usage

Here’s an example of how to use the `isPrefixString` function:

```cpp
Solution sol;
string s = "iloveleetcode";
vector<string> w = {"i", "love", "leet", "code"};
bool result = sol.isPrefixString(s, w);
cout << "Is prefix string: " << (result ? "true" : "false") << endl; // Output: true
```

In this example, we create an instance of the `Solution` class, define a string `s`, and a vector of words `w`. We then call the `isPrefixString` method and print the result, which indicates whether `s` is a prefix of the concatenated words in `w`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/description/)

---
{{< youtube msS6F5DL8gQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
