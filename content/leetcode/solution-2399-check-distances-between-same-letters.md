
+++
authors = ["grid47"]
title = "Leetcode 2399: Check Distances Between Same Letters"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2399: Check Distances Between Same Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uNv8XvliP0o"
youtube_upload_date="2022-09-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uNv8XvliP0o/maxresdefault.webp"
comments = true
+++



---
You are given a string `s` consisting of lowercase English letters where each letter appears exactly twice. You are also given an array `distance` of length 26, where each element represents the number of characters between the two occurrences of the corresponding letter (0-indexed, 'a' corresponds to index 0, 'b' to index 1, etc.). Your task is to determine if the string `s` is a 'well-spaced' string. A string is well-spaced if, for each letter in `s`, the number of characters between its two occurrences matches the corresponding value in the `distance` array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` of length `n` and an array `distance` of size 26, representing the spacing rules for each letter in the alphabet.
- **Example:** `s = 'abcdbf', distance = [1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`
- **Constraints:**
	- 2 <= s.length <= 52
	- Each letter appears exactly twice in `s`.
	- The `distance` array has length 26.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if `s` is a well-spaced string, otherwise return `false`.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if the string is well-spaced according to the spacing rules defined by the `distance` array.

- 1. Iterate through each character in the string `s`.
- 2. For each character, check if the number of characters between its two occurrences matches the value in the `distance` array.
- 3. If for any character, the spacing condition is violated, return `false`.
- 4. If all characters satisfy their spacing conditions, return `true`.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` contains only lowercase English letters.
- The array `distance` provides valid values for each letter, where values represent the number of letters between the two occurrences.
{{< dots >}}
## Examples 🧩
- **Input:** `s = 'abaccb', distance = [1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`  \
  **Explanation:** In this example, the spacing between occurrences of 'a' is 1 (distance[0] = 1), between 'b' is 3 (distance[1] = 3), and 'c' has no spacing (distance[2] = 0). The string meets the well-spaced condition, so the output is true.

- **Input:** `s = 'aa', distance = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`  \
  **Explanation:** In this case, 'a' appears at indices 0 and 1, but the distance condition for 'a' (distance[0] = 1) is not satisfied, as there are no letters between them. Therefore, the output is false.

{{< dots >}}
## Approach 🚀
The approach involves checking the distance between occurrences of each character in the string `s` and ensuring that it satisfies the conditions specified in the `distance` array.

### Initial Thoughts 💭
- Each character in `s` appears exactly twice, so we only need to check the distance between the two occurrences of each character.
- We can efficiently track the positions of each character in the string and verify if the distance condition holds for each letter.
{{< dots >}}
### Edge Cases 🌐
- Although `s` will always have a length of at least 2, it is important to consider cases where `s` contains only one unique character repeated twice.
- The problem ensures that `s.length` will not exceed 52, so the solution must efficiently handle this input size.
- When `distance` contains zeros, it signifies that there are no characters between the occurrences of a letter.
- We can safely assume that the constraints guarantee a valid input string `s` and a well-formed `distance` array.
{{< dots >}}
## Code 💻
```cpp
  bool checkDistances(string s, vector<int>& distance) {
int pos[26] = {};
for (int i = 0; i < s.size(); ++i) {
    int n = s[i] - 'a';
    if (pos[n] > 0 && distance[n] != i - pos[n])
        return false;
    pos[n] = i + 1;
}
return true;
  }
```

This function checks whether the distances between identical characters in a string match the corresponding values provided in the distance vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **FunctionDefinition**
	```cpp
	  bool checkDistances(string s, vector<int>& distance) {
	```
	This line defines the function checkDistances, which takes a string 's' and a vector 'distance' as parameters. The function returns a boolean value.

2. **VariableInitialization**
	```cpp
	int pos[26] = {};
	```
	An array 'pos' of size 26 is initialized to zero to keep track of the last seen position of each letter in the string. The array indexes correspond to the letters of the alphabet.

3. **LoopStart**
	```cpp
	for (int i = 0; i < s.size(); ++i) {
	```
	A for loop is started that iterates through each character of the string 's'.

4. **CharacterToIndex**
	```cpp
	    int n = s[i] - 'a';
	```
	Each character of the string 's' is converted into an index (0 for 'a', 1 for 'b', etc.) by subtracting 'a' from the character.

5. **ConditionalCheck**
	```cpp
	    if (pos[n] > 0 && distance[n] != i - pos[n])
	```
	This condition checks whether the character has appeared before and if the distance between this occurrence and the previous one matches the corresponding value in the 'distance' vector.

6. **ReturnFalse**
	```cpp
	        return false;
	```
	If the condition in the previous step is true, the function immediately returns false, indicating that the distances do not match.

7. **UpdatePosition**
	```cpp
	    pos[n] = i + 1;
	```
	The position of the current character is updated in the 'pos' array. The index is incremented by 1 to indicate that this character has been seen at the current index.

8. **ReturnTrue**
	```cpp
	return true;
	```
	If no mismatched distances were found during the loop, the function returns true, indicating that the distances between identical characters match the given values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the string `s`. This is the case when all characters are well-spaced.
- **Average Case:** O(n), where n is the length of the string `s`. We need to check each character's spacing.
- **Worst Case:** O(n), where n is the length of the string `s`. We check every character's distance condition.

The time complexity is linear in terms of the length of `s`, as we perform a single pass through the string.

### Space Complexity 💾
- **Best Case:** O(1), as space usage is independent of input size.
- **Worst Case:** O(1), as we are using a constant amount of space to track positions of characters.

The space complexity is constant, as we only need a fixed-size array to store the first occurrence of each character.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-distances-between-same-letters/description/)

---
{{< youtube uNv8XvliP0o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
