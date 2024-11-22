
+++
authors = ["grid47"]
title = "Leetcode 2452: Words Within Two Edits of Dictionary"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2452: Words Within Two Edits of Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "99KTTNdlKns"
youtube_upload_date="2022-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/99KTTNdlKns/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(auto &q: queries)
        for(auto &d: dictionary)
        if(inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3) {
            res.push_back(q);
            break;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement:
In this problem, we are tasked with identifying words in a given list of queries that can be transformed into any word in a dictionary with at most two character changes. Specifically, for each query word, we need to check if there is any word in the dictionary that can be modified by changing at most two characters (at any position) to become the query word.

### Approach:
The problem can be approached by iterating through each query word and comparing it with every word in the dictionary. The goal is to check if the query word can match any dictionary word with at most two changes. This means that for each pair of query and dictionary word, we need to count the number of positions at which the characters differ.

If the number of differing positions is less than or equal to two, then that dictionary word qualifies as a match for the query. The query word is then added to the result list.

### Code Breakdown (Step by Step):
Let’s walk through the solution code in detail, explaining each section step by step.

1. **Function Declaration**:
   ```cpp
   vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary)
   ```
   This function `twoEditWords` takes in two parameters: 
   - A vector `queries` containing the list of query words.
   - A vector `dictionary` containing the list of dictionary words.
   
   It returns a vector of strings, containing the query words that can be transformed into any dictionary word by changing at most two characters.

2. **Result Vector Initialization**:
   ```cpp
   vector<string> res;
   ```
   A `vector<string>` named `res` is initialized. This will hold the query words that meet the criteria — that is, words that can be transformed into a dictionary word with at most two character changes.

3. **Outer Loop (Iterating Over Queries)**:
   ```cpp
   for (auto &q : queries)
   ```
   This outer loop iterates over each query word in the `queries` vector. The variable `q` refers to the current query word being processed.

4. **Inner Loop (Iterating Over Dictionary)**:
   ```cpp
   for (auto &d : dictionary)
   ```
   Inside the outer loop, we have an inner loop that iterates over each word in the `dictionary`. The variable `d` refers to the current dictionary word being compared with the query word `q`.

5. **Comparison Using `inner_product`**:
   ```cpp
   if (inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3)
   ```
   Here’s where the main logic for comparing the query word and the dictionary word is applied. 
   
   The `inner_product` function is used to compare the query word `q` and the dictionary word `d`. It computes a sum of results from applying the `not_equal_to<char>()` operation to corresponding characters of `q` and `d`. This operation checks whether the characters are different at each position.

   - `begin(q)` and `begin(d)` represent the starting points of the two strings (`q` and `d`).
   - `end(q)` and `end(d)` represent the ending points of the strings.
   - The initial value of the sum is set to `0`, and `plus<int>()` is used to add the results.
   - `not_equal_to<char>()` returns `true` for differing characters, contributing `1` to the sum, and `false` contributes `0`.

   The result of `inner_product` is the total number of character positions where `q` and `d` differ. If the result is less than 3, this means that the two words differ in less than three positions, satisfying the condition of transforming one word into another by changing at most two characters.

6. **Adding the Query to the Result**:
   ```cpp
   res.push_back(q);
   break;
   ```
   If the condition is met (i.e., the number of differing positions is less than 3), the query word `q` is added to the result vector `res`. The inner loop is then broken using `break`, as we only need to find one matching dictionary word for each query word.

7. **Return the Result**:
   ```cpp
   return res;
   ```
   After processing all the query words, the function returns the `res` vector, which contains all the query words that can be transformed into a dictionary word with at most two character changes.

### Code Complexity:
The time complexity and space complexity of this solution can be analyzed as follows:

- **Time Complexity**:
  - The solution uses two nested loops: one iterating over the query words (`queries`) and another iterating over the dictionary words (`dictionary`).
  - For each pair of query and dictionary word, we use `inner_product` to compare the characters, which takes linear time relative to the length of the words.
  
  If there are `m` query words and `n` dictionary words, and each word has a length of `l`, the overall time complexity can be expressed as:
  \[
  O(m \times n \times l)
  \]
  This is because for each pair of words (query and dictionary), we are performing a comparison of `l` characters.

- **Space Complexity**:
  - The space complexity is primarily determined by the storage of the result vector `res`, which can hold up to `m` query words. Each word is stored as a string, so the space complexity is:
  \[
  O(m \times l)
  \]
  where `m` is the number of query words and `l` is the average length of the words.

### Conclusion:
The `twoEditWords` function is an efficient solution to the problem of finding query words that can be transformed into dictionary words with at most two character edits. The algorithm leverages the `inner_product` function to efficiently compare characters between query and dictionary words. It uses two nested loops to check each query word against every dictionary word, and if any match is found with fewer than three differing characters, the query is added to the result.

The time complexity is quadratic in terms of the number of queries and dictionary words, with an additional factor of the word length, making the algorithm suitable for moderate-sized inputs. By breaking down the problem into simple steps and using efficient comparison techniques, this solution offers a clear and straightforward approach to solving the problem.

This solution can be further optimized or parallelized for very large inputs, but for typical scenarios, it performs well in terms of both time and space complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/)

---
{{< youtube 99KTTNdlKns >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
