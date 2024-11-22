
+++
authors = ["grid47"]
title = "Leetcode 1816: Truncate Sentence"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1816: Truncate Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "2_B2ZUBRYQQ"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/2_B2ZUBRYQQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =0;
        string ans="";
        for(auto x:s)
        {
            if(x==' ')
                count++;
            if(count==k)
                break;
            ans+=x;
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to truncate a given sentence after a specified number of words. The function should take a string `s`, which represents the sentence, and an integer `k`, which specifies the number of words to keep. The goal is to return a new string containing only the first `k` words of the original sentence. If the number of words in the sentence is less than or equal to `k`, the entire sentence should be returned as is.

### Approach

To solve this problem, we can follow a simple iterative approach:

1. **Initialize Counters**: We will maintain a count of the number of words encountered as we iterate through the string.
2. **Iterate Through the Sentence**: We will traverse each character in the string `s` and check for spaces, which indicate the separation between words.
3. **Build the Result**: As we encounter each character, we will append it to our result string `ans`. Once we reach the `k`-th word (after counting `k-1` spaces), we will stop the iteration.
4. **Return the Result**: Finally, we will return the constructed result string `ans`.

### Code Breakdown (Step by Step)

Here is a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
```
- A class `Solution` is defined to encapsulate the functionality required to solve the problem.

```cpp
    string truncateSentence(string s, int k) {
```
- The method `truncateSentence` takes two parameters: a string `s` representing the sentence and an integer `k` representing the number of words to keep. The function returns a string.

```cpp
        int count = 0;
        string ans = "";
```
- We initialize an integer `count` to keep track of the number of words we have encountered and a string `ans` to store the resulting truncated sentence.

```cpp
        for(auto x : s)
        {
```
- A for-loop is initiated to iterate over each character `x` in the string `s`.

```cpp
            if(x == ' ')
                count++;
```
- Inside the loop, we check if the current character `x` is a space. If it is, we increment our `count` variable by 1 to indicate that we have found another word.

```cpp
            if(count == k)
                break;
```
- We check if the `count` of words encountered is equal to `k`. If it is, we break out of the loop as we have reached the desired number of words to include in our result.

```cpp
            ans += x;
```
- Regardless of whether we have hit the word limit or not, we append the current character `x` to our result string `ans`.

```cpp
        return ans;
```
- Finally, we return the constructed string `ans` that contains the truncated sentence.

```cpp
    }
};
```
- The method and class are closed.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the length of the string `s`. This is because we potentially traverse the entire string in the worst case, counting words and building the result.

- **Space Complexity**: The space complexity is \(O(m)\), where \(m\) is the number of characters in the resulting string. In the worst case, this could be the length of `s` if the sentence has fewer than or equal to `k` words.

### Conclusion

The `truncateSentence` function effectively truncates a sentence to the specified number of words by iterating through the input string character by character. It uses a straightforward counting mechanism to determine when to stop adding words to the result, ensuring that we capture the first `k` words of the sentence accurately.

This implementation showcases a simple and efficient approach to string manipulation in C++. It highlights the importance of understanding word boundaries and counting techniques in solving common string-related problems. The code is designed to handle edge cases seamlessly, such as when the sentence has fewer words than `k`, making it robust for various inputs. Overall, this solution is an excellent example of practical string handling in competitive programming and software development contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/truncate-sentence/description/)

---
{{< youtube 2_B2ZUBRYQQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
