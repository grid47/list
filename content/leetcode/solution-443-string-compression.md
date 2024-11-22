
+++
authors = ["grid47"]
title = "Leetcode 443: String Compression"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 443: String Compression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/443.webp"
youtube = "JHTqvUTZzqM"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi/JHTqvUTZzqM/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/443.webp" 
    alt="A string shrinking as characters are compressed, with each compression step softly glowing."
    caption="Solution to LeetCode 443: String Compression Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2) return chars.size();
        int i = 0, j = 0;
        while(i < chars.size()) {
            chars[j] = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == chars[j]) {
                cnt++;
                i++;
            }

            if(cnt == 1) {
                j++;
            } else {
                string cntt = to_string(cnt);
                for(auto ch: cntt) {
                    chars[++j] = ch;
                }
                j++;
            }
        }
        return j;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to implement a string compression algorithm. Given a list of characters, we need to compress the string by replacing consecutive repeated characters with a single character followed by the count of its repetitions. For example, the input `["a","a","b","b","c","c","c"]` should be compressed to `["a","2","b","2","c","3"]`. The goal is to compress the list in-place, using the minimum amount of extra space, and return the new length of the compressed list.

### Approach

The key idea behind this solution is to use a two-pointer approach to iterate through the `chars` array and compress consecutive characters as we encounter them. The approach works by:

1. **Iterating through the input array**: Using a pointer `i` to traverse through each character and another pointer `j` to place the result of compression.
2. **Counting consecutive characters**: For each character, we count how many times it repeats consecutively.
3. **Compressing the string**: If the character repeats more than once, we add both the character and the count of its occurrences to the `chars` array. If it only appears once, we just add the character.
4. **Updating the pointer**: After processing a sequence of repeated characters, we update the pointer `j` accordingly and continue to the next unique character.
5. **Handling edge cases**: Special cases like when the input string has fewer than two characters or no characters at all are handled early in the function.

### Code Breakdown (Step by Step)

#### Step 1: Handle Short Inputs

```cpp
if(chars.size() < 2) return chars.size();
```

- We first handle the base case where the input has fewer than two characters. In this case, there’s no compression to do, so the function simply returns the size of the input.

#### Step 2: Initialize Pointers

```cpp
int i = 0, j = 0;
```

- Two pointers are initialized: `i` is used to traverse the array to find consecutive characters, and `j` is used to place the result of the compression.

#### Step 3: Main Loop to Traverse and Compress

```cpp
while(i < chars.size()) {
    chars[j] = chars[i];
    int cnt = 0;
```

- The loop begins with `i` pointing to the first character. The character at `chars[i]` is placed at `chars[j]` to preserve it for later compression. We also initialize a counter `cnt` to zero to count the consecutive occurrences of the current character.

#### Step 4: Count Consecutive Occurrences

```cpp
while(i < chars.size() && chars[i] == chars[j]) {
    cnt++;
    i++;
}
```

- We use an inner `while` loop to count how many times the current character repeats consecutively in the array. Each time we find a match (`chars[i] == chars[j]`), we increment the counter `cnt` and move the pointer `i` to the next character.

#### Step 5: Handle the Count of Repeated Characters

```cpp
if(cnt == 1) {
    j++;
} else {
    string cntt = to_string(cnt);
    for(auto ch: cntt) {
        chars[++j] = ch;
    }
    j++;
}
```

- If the character appears only once (i.e., `cnt == 1`), we simply increment the pointer `j` to place the next character.
- If the character appears more than once, we convert the count `cnt` to a string and place each digit of the count in the `chars` array, updating `j` each time we place a character or digit.

#### Step 6: Return the New Length

```cpp
return j;
```

- Finally, the function returns `j`, which represents the new length of the compressed string after the in-place compression is done.

### Complexity

#### Time Complexity:
- The time complexity of the solution is `O(n)`, where `n` is the size of the `chars` array. This is because we only traverse the input array once, and the inner loop only operates on a limited number of characters (i.e., the digits of the count). The overall number of iterations is proportional to the length of the input array, so the time complexity is linear.

#### Space Complexity:
- The space complexity is `O(1)`, which means that the algorithm uses constant space, excluding the input and output. The compression is done in-place, meaning we do not use any additional data structures to store intermediate results (other than a small number of variables like `i`, `j`, and `cnt`).

### Conclusion

This solution provides an efficient in-place approach to compressing a list of characters by replacing consecutive repeated characters with the character followed by the number of occurrences. It uses a two-pointer technique to traverse the list, counting consecutive characters and placing the result directly into the input array. The time complexity is linear (`O(n)`), making this approach very efficient for large inputs. The space complexity is constant (`O(1)`), making it an optimal solution in terms of memory usage as well.

By following this method, the function efficiently solves the problem while maintaining the required constraints and ensuring that the output is in the correct compressed format.

[`Link to LeetCode Lab`](https://leetcode.com/problems/string-compression/description/)

---
{{< youtube JHTqvUTZzqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
