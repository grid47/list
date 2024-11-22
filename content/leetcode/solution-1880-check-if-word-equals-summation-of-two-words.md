
+++
authors = ["grid47"]
title = "Leetcode 1880: Check if Word Equals Summation of Two Words"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1880: Check if Word Equals Summation of Two Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "XdgS7eqwF2M"
youtube_upload_date="2021-05-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XdgS7eqwF2M/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first=0,second=0,target=0;
        for(int i=0;i<firstWord.size();i++)
            first=first*10 + (firstWord[i]-'a');
        
        for(int i=0;i<secondWord.size();i++)
            second=second*10 +(secondWord[i]-'a');
        
        for(int i=0;i<targetWord.size();i++)
            target=target*10 +(targetWord[i]-'a');
        
        
        return first+second == target;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires determining if the sum of two words represented by lowercase letters can equal a target word. Each letter from 'a' to 'z' corresponds to a digit from 0 to 25, respectively. Therefore, the goal is to convert the words into their numerical representations based on this mapping, then check if the sum of the first two words equals the third word (the target).

### Approach

To solve this problem, we will follow these steps:

1. **Mapping Characters to Numbers**: Each character in the given words will be converted to a corresponding numerical value based on its position in the alphabet. Specifically, 'a' will be mapped to 0, 'b' to 1, up to 'z', which will be mapped to 25.

2. **Constructing the Numerical Values**: We will iterate through each word, constructing its numerical value as we process each character. This is done by multiplying the current total by 10 (to shift the digits) and adding the numerical value of the current character.

3. **Checking the Equality**: After converting all three words into their numerical forms, we simply check if the sum of the first two equals the value of the third.

### Code Breakdown (Step by Step)

1. **Class Declaration**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Definition**: The main function `isSumEqual` is defined, taking three strings as parameters.

   ```cpp
       bool isSumEqual(string firstWord, string secondWord, string targetWord) {
   ```

3. **Initialization of Variables**: We initialize three integer variables `first`, `second`, and `target` to hold the numerical values of the first word, second word, and target word, respectively.

   ```cpp
           int first = 0, second = 0, target = 0;
   ```

4. **Converting the First Word**: We loop through each character in `firstWord`, converting it to a number and building its total value.

   ```cpp
           for(int i = 0; i < firstWord.size(); i++)
               first = first * 10 + (firstWord[i] - 'a');
   ```

5. **Converting the Second Word**: We repeat the process for `secondWord`, building its numerical representation.

   ```cpp
           for(int i = 0; i < secondWord.size(); i++)
               second = second * 10 + (secondWord[i] - 'a');
   ```

6. **Converting the Target Word**: The same conversion process is applied to `targetWord`.

   ```cpp
           for(int i = 0; i < targetWord.size(); i++)
               target = target * 10 + (targetWord[i] - 'a');
   ```

7. **Return the Result**: Finally, we return whether the sum of the first two words equals the third word.

   ```cpp
           return first + second == target;
       }
   };
   ```

### Complexity

The time complexity of this algorithm is \( O(n) \), where \( n \) is the length of the longest word among `firstWord`, `secondWord`, and `targetWord`. This is because we are processing each character of the strings once to build their numerical values.

The space complexity is \( O(1) \) as we are using a fixed amount of space (three integers) regardless of the input size.

### Conclusion

In conclusion, the `isSumEqual` function provides an efficient solution to the problem of checking if two words sum up to a target word using a specific character-to-number mapping. The approach is straightforward, relying on basic arithmetic operations and character manipulations.

By converting each word into its numerical equivalent based on its characters, we can directly perform the required addition and equality check. This solution illustrates how to handle string manipulation and numerical conversion in a concise manner.

This method not only highlights the ability to represent complex problems using simple mathematical representations but also demonstrates how to efficiently process strings in competitive programming scenarios. By mastering such techniques, developers can tackle various problems that involve similar transformations, thereby enhancing their problem-solving capabilities in algorithm design.

Overall, the `isSumEqual` function exemplifies a clear and efficient approach to a character mapping problem, reinforcing the importance of understanding both string handling and basic arithmetic in algorithm development.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/)

---
{{< youtube XdgS7eqwF2M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
