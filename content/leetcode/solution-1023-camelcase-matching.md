
+++
authors = ["grid47"]
title = "Leetcode 1023: Camelcase Matching"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1023: Camelcase Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String","Trie","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "h9I_yFNeMgo"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h9I_yFNeMgo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res;
        
        for(string q: queries) {
            
            bool ret = match(q, pattern);
            
            res.push_back(ret);
        }

        return res;
    }
    
    bool match(string q, string p) {
        
        int j = 0;
        
        for(int i = 0; i < q.size(); i++) {
            
            if(j < p.size()&&q[i] == p[j]) {
                j++;
                continue;
            }else if(q[i] >= 'A' && 
               q[i] <= 'Z')
                return false;               
               
        }
        
        return j == p.size();
        
    }

};
{{< /highlight >}}
---


### Problem Statement
The objective of this problem is to determine whether each query in a list adheres to a specified camel case pattern. In camel case, a pattern starts with a lowercase letter and may contain uppercase letters that indicate the start of new words. A query matches the pattern if:
1. It contains all the characters of the pattern in the same order.
2. It may have additional lowercase letters, but any uppercase letters must correspond to lowercase letters in the pattern or not be present in the query at all.

For example, given the pattern "aB" and queries ["ab", "aB", "aBc", "AB", "bA"], the results would indicate that "aB" and "aBc" match the pattern, while "ab", "AB", and "bA" do not.

### Approach
To solve this problem, we can use a straightforward approach that involves iterating through each query and checking whether it matches the provided pattern. The approach consists of the following steps:
1. **Iterate through Queries**: For each query, determine if it matches the pattern using a helper function.
2. **Character Matching**: In the helper function, traverse both the query and pattern strings simultaneously. Track the current position in the pattern and validate whether the characters in the query match the pattern according to camel case rules.
3. **Result Collection**: Store the result (true or false) for each query based on whether it matches the pattern and return the results as a vector of booleans.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The main function `camelMatch` is defined as a public member of the `Solution` class, taking a vector of strings (`queries`) and a string (`pattern`) as parameters.

2. **Result Vector Initialization**:
   - A vector of booleans named `res` is initialized to store the match results for each query.

3. **Query Iteration**:
   - A `for` loop iterates over each string `q` in the `queries` vector.
   - For each query, the `match` function is called with the current query and the pattern, and the returned boolean result (`ret`) is pushed into the `res` vector.

4. **Matching Function**:
   - The helper function `match` is defined to check if the query matches the pattern.
   - A variable `j` is initialized to keep track of the current index in the pattern.

5. **Query Character Traversal**:
   - A `for` loop iterates through each character in the query (`q`), using an index `i`.
   - Inside the loop, there are two primary conditions:
     - **Pattern Matching**: If the current character in the query matches the current character in the pattern (`q[i] == p[j]`), the index `j` is incremented to check the next character in the pattern.
     - **Uppercase Character Check**: If the character in the query is uppercase (i.e., between 'A' and 'Z') and does not match the pattern, the function immediately returns `false`, indicating that the query does not match.

6. **Final Matching Condition**:
   - After traversing the query, the function checks if all characters of the pattern have been matched (`j == p.size()`). If this condition is met, it returns `true`; otherwise, it returns `false`.

7. **Return Statement**:
   - Finally, the `camelMatch` function returns the result vector `res`, containing the match results for each query.

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \( O(q \times p) \), where \( q \) is the average length of the queries and \( p \) is the length of the pattern. Each query is processed independently, and for each character in the query, we potentially check against the characters in the pattern.
- **Space Complexity**: The space complexity is \( O(n) \), where \( n \) is the number of queries since we are storing the results in a vector. The auxiliary space used by the function is minimal.

### Conclusion
The `camelMatch` function provides an efficient solution for determining whether each query matches a given camel case pattern. The use of a helper function to handle the character matching logic ensures that the implementation remains clear and modular.

This solution demonstrates a practical approach to string matching problems, showcasing how to effectively handle camel case patterns and manage character comparisons. Understanding this technique can be beneficial for solving similar problems related to pattern recognition and validation in strings.

In summary, the `camelMatch` function is a valuable example of how to implement pattern matching in C++, making use of logical conditions to enforce the rules of camel case. This approach not only provides a clear solution to the problem but also serves as a reference for similar challenges in competitive programming and software development.

Overall, the function illustrates the application of basic string manipulation and comparison techniques, emphasizing the importance of logical thinking when designing algorithms for pattern matching. By leveraging these strategies, developers can tackle a wide range of string processing tasks effectively.


[`Link to LeetCode Lab`](https://leetcode.com/problems/camelcase-matching/description/)

---
{{< youtube h9I_yFNeMgo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
