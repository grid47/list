
+++
authors = ["grid47"]
title = "Leetcode 1451: Rearrange Words in a Sentence"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1451: Rearrange Words in a Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZMdBEJX3gog"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZMdBEJX3gog/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string arrangeWords(string txt) {
        
        int n = txt.size();
        vector<vector<int>> arr;
        map<int, string> mp;
        int prv = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(txt[i] == ' ' || i == n - 1) {
                string str;
                int len;
                if(i == n - 1) {
                    len = i + 1 - prv;
                } else {
                    len = i - prv;
                }
                str = txt.substr(prv, len);
                if(prv == 0) str[0] = str[0] - 'A' + 'a';
                cnt++;
                mp[cnt] = str;
                arr.push_back({len, cnt});
                prv = i + 1;
            }
        }
        sort(arr.begin(), arr.end());
        string res = "";
        for(int i = 0; i < arr.size(); i++) {
            res += mp[arr[i][1]];
            if(i != arr.size() - 1) res += ' ';
        }
        res[0] = res[0] - 'a' + 'A';
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to rearrange the words in a given string such that they are sorted by their lengths in ascending order. The first word in the resulting string should start with an uppercase letter, while all other words should be in lowercase. If there are multiple words of the same length, they should maintain their relative order from the input string.

### Approach

To solve this problem, we can follow these steps:

1. **Word Extraction**: Split the input string into individual words.
2. **Word Storage**: Store these words along with their lengths in a way that allows sorting.
3. **Sorting**: Sort the words based on their lengths.
4. **Result Construction**: Construct the resulting string from the sorted list of words, ensuring the correct capitalization for the first word.
5. **Return Result**: Finally, return the newly formed string.

### Code Breakdown (Step by Step)

Let's break down the provided code for better understanding:

1. **Class Declaration**:
   ```cpp
   class Solution {
   ```

   - The solution is encapsulated within a class named `Solution`, which is standard in coding challenges.

2. **Function Declaration**:
   ```cpp
   public:
       string arrangeWords(string txt) {
   ```

   - The function `arrangeWords` takes a string `txt` as input and returns a new string with rearranged words.

3. **Variable Initialization**:
   ```cpp
       int n = txt.size();
       vector<vector<int>> arr;
       map<int, string> mp;
       int prv = 0, cnt = 0;
   ```

   - We determine the length of the input string `n`.
   - `arr` will hold the lengths and order of words.
   - `mp` is a map that will store each word with its corresponding index (order).
   - `prv` is used to track the starting index of the current word, and `cnt` is a counter for the number of words processed.

4. **Word Extraction Loop**:
   ```cpp
       for(int i = 0; i < n; i++) {
           if(txt[i] == ' ' || i == n - 1) {
   ```

   - We loop through each character in the string to extract words. A word is considered to end when we encounter a space or reach the end of the string.

5. **Handling Last Word**:
   ```cpp
               string str;
               int len;
               if(i == n - 1) {
                   len = i + 1 - prv;
               } else {
                   len = i - prv;
               }
   ```

   - We determine the length of the current word. If it's the last character in the string, we adjust accordingly to include the last word.

6. **Substring Extraction**:
   ```cpp
               str = txt.substr(prv, len);
               if(prv == 0) str[0] = str[0] - 'A' + 'a';
   ```

   - We extract the substring corresponding to the current word.
   - If it's the first word (starting at index 0), we convert its first letter to lowercase.

7. **Storing Words**:
   ```cpp
               cnt++;
               mp[cnt] = str;
               arr.push_back({len, cnt});
               prv = i + 1;
           }
       }
   ```

   - We increment the word count, store the word in the map with its index, and push its length along with its order into the `arr` vector.
   - We update `prv` to point to the start of the next word.

8. **Sorting**:
   ```cpp
       sort(arr.begin(), arr.end());
   ```

   - The `arr` vector is sorted based on word lengths, which is the first element of each sub-array in `arr`.

9. **Result Construction**:
   ```cpp
       string res = "";
       for(int i = 0; i < arr.size(); i++) {
           res += mp[arr[i][1]];
           if(i != arr.size() - 1) res += ' ';
       }
   ```

   - We build the result string `res` by concatenating the words in the order of their lengths.
   - A space is added between words except for the last word.

10. **Capitalization of First Word**:
    ```cpp
       res[0] = res[0] - 'a' + 'A';
       return res;
   ```

   - Finally, the first character of the result is capitalized, and the completed string is returned.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(N \log N)\), where \(N\) is the total number of characters in the input string. This includes the time taken to sort the words based on their lengths after extracting them.

- **Space Complexity**: The space complexity is \(O(N)\) for storing the words and their lengths, which requires additional space proportional to the input size.

### Conclusion

The provided code effectively rearranges the words in a string based on their lengths, capitalizing the first word as required. 

#### Key Takeaways:

1. **String Manipulation**: The code demonstrates efficient string manipulation techniques, including substring extraction and character case conversion.

2. **Data Structures**: The use of a vector for sorting and a map for word storage highlights the importance of choosing appropriate data structures based on the problem requirements.

3. **Sorting Algorithms**: Sorting is a crucial step in arranging the words, and the approach taken ensures that the words are sorted efficiently.

4. **Edge Cases**: The implementation considers edge cases, such as empty strings or strings with only spaces.

In summary, the provided solution is a clear and effective implementation for rearranging words in a string based on their lengths, showcasing the power of C++'s STL (Standard Template Library) for handling collections of data efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/rearrange-words-in-a-sentence/description/)

---
{{< youtube ZMdBEJX3gog >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
