
+++
authors = ["grid47"]
title = "Leetcode 893: Groups of Special-Equivalent Strings"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 893: Groups of Special-Equivalent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tbtXPKkA2Zw"
youtube_upload_date="2020-01-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tbtXPKkA2Zw/maxresdefault.webp"
comments = true
+++



---
You are given an array of strings where each string is of the same length. In one move, you can swap any two characters at even indexed positions or any two characters at odd indexed positions in a string. Two strings are considered special-equivalent if they can be made identical after performing any number of such moves. Your task is to determine how many distinct groups of special-equivalent strings exist in the given array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of strings, all of which have the same length. Each string contains only lowercase English letters.
- **Example:** `Input: words = ["hello","oellh","elhol","aabb","bbaa","abab"]`
- **Constraints:**
	- 1 <= words.length <= 1000
	- 1 <= words[i].length <= 20
	- All strings have the same length.
	- Each string contains lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of distinct groups of special-equivalent strings in the given array.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be the number of distinct groups of special-equivalent strings.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to classify the strings into distinct groups where all strings within a group are special-equivalent.

- For each string in the array, split the characters into two groups: one for even indices and one for odd indices.
- Sort both groups (even indexed characters and odd indexed characters) to standardize their structure.
- Use a set to store each string's standardized representation (sorted even and odd indexed groups).
- The number of distinct groups will be equal to the size of the set.
{{< dots >}}
### Problem Assumptions ✅
- The problem guarantees that the input strings have the same length.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: words = ["hello","oellh","elhol","aabb","bbaa","abab"]`  \
  **Explanation:** In this case, the strings 'hello', 'oellh', and 'elhol' are all special-equivalent to each other because their even and odd indexed characters can be rearranged to match. The strings 'aabb', 'bbaa', and 'abab' form another group since they can be rearranged similarly. Thus, there are 3 groups in total.

- **Input:** `Input: words = ["abcd", "dcab", "acbd", "xyzz", "zzxy"]`  \
  **Explanation:** In this example, the first three strings form one group as they are special-equivalent. The last two strings form another group as they can be made identical by rearranging even and odd indexed characters.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to identify groups of strings that are special-equivalent. This can be achieved by separating each string into even and odd indexed characters, sorting them, and using a set to track distinct combinations.

### Initial Thoughts 💭
- We can separate the characters in the string based on their indices (even or odd).
- Sorting the characters within each group (even and odd) helps in identifying equivalence.
- We can use a set data structure to track unique combinations of sorted even and odd indexed characters.
{{< dots >}}
### Edge Cases 🌐
- If the input is empty, the result is 0.
- Ensure the solution can handle up to 1000 strings efficiently.
- Strings with only one character will always form their own group.
- Ensure efficient handling of strings up to length 20 and 1000 words.
{{< dots >}}
## Code 💻
```cpp
int numSpecialEquivGroups(vector<string>& words) {
    set<pair<string, string>> s;
    for(const auto& w: words) {
        pair<string, string> p;
        for(int i = 0; i < w.size(); i++) {
            if (i % 2) p.first  += w[i];
            else       p.second += w[i];
        }
        sort(p.first.begin(), p.first.end());
        sort(p.second.begin(), p.second.end());
        s.insert(p);
    }
    return s.size();
}
```

This code defines the function `numSpecialEquivGroups`, which finds the number of special equivalent groups in a list of strings. The function splits the characters of each string into two groups (odd and even indexed), sorts them, and then stores each pair of sorted groups in a set to count unique combinations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSpecialEquivGroups(vector<string>& words) {
	```
	Define the function `numSpecialEquivGroups`, which takes a vector of strings as input and returns the number of unique special equivalent groups.

2. **Variable Declaration**
	```cpp
	    set<pair<string, string>> s;
	```
	Declare a set `s` to store pairs of sorted odd and even indexed characters from each string.

3. **Loop Through Words**
	```cpp
	    for(const auto& w: words) {
	```
	Iterate through each string `w` in the input vector `words`.

4. **Pair Initialization**
	```cpp
	        pair<string, string> p;
	```
	Initialize a pair `p` to store the sorted characters from the odd and even indices of the string.

5. **Character Grouping**
	```cpp
	        for(int i = 0; i < w.size(); i++) {
	```
	Iterate through each character in the string `w`.

6. **Odd Index Character Grouping**
	```cpp
	            if (i % 2) p.first  += w[i];
	```
	For characters at odd indices, append them to `p.first`.

7. **Even Index Character Grouping**
	```cpp
	            else       p.second += w[i];
	```
	For characters at even indices, append them to `p.second`.

8. **End Inner Loop**
	```cpp
	        }
	```
	End the loop that processes characters in the string `w`.

9. **Sorting Odd Group**
	```cpp
	        sort(p.first.begin(), p.first.end());
	```
	Sort the characters stored in `p.first` (odd indexed characters).

10. **Sorting Even Group**
	```cpp
	        sort(p.second.begin(), p.second.end());
	```
	Sort the characters stored in `p.second` (even indexed characters).

11. **Insert Pair into Set**
	```cpp
	        s.insert(p);
	```
	Insert the sorted pair `p` into the set `s` to ensure uniqueness of the combinations.

12. **End Outer Loop**
	```cpp
	    }
	```
	End the loop that processes each word in the `words` vector.

13. **Return Unique Group Count**
	```cpp
	    return s.size();
	```
	Return the size of the set `s`, which contains the number of unique special equivalent groups.

14. **End Function**
	```cpp
	}
	```
	End the function definition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m log m)
- **Average Case:** O(n * m log m)
- **Worst Case:** O(n * m log m)

The time complexity is O(n * m log m), where n is the number of strings, and m is the length of each string. Sorting the even and odd indexed characters in each string takes O(m log m).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) because we store each string's even and odd indexed characters separately, along with the set of unique combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/groups-of-special-equivalent-strings/description/)

---
{{< youtube tbtXPKkA2Zw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
