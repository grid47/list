
+++
authors = ["grid47"]
title = "Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1415: The k-th Lexicographical String of All Happy Strings of Length n in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
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
    string ans = "";
    int cnt = 0;
    int k, n;
    
    string getHappyString(int n, int k) {
        this->k = k;
        this->n = n;
        string tmp = "";
        bt(-1, tmp);
        return ans;
    }
    
    void bt(int prv, string &tmp) {
        if(tmp.size() == n) {
            cnt++;
            if(cnt == k){
              ans = tmp;  
            } 
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(prv == i) continue;
            if(i == 0) {
                tmp += 'a';
            } else if(i == 1) {
                tmp += 'b';
            } else if(i == 2) {
                tmp += 'c';
            }
            bt(i, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to generate the k-th lexicographically smallest "happy string" of length \( n \). A "happy string" is defined as a string composed of the letters 'a', 'b', and 'c', where no three consecutive characters are the same. For example, "abc", "aab", and "abbc" are happy strings, while "aaa" and "abca" are not. Given \( n \) and \( k \), the function should return the k-th happy string in the lexicographical order.

### Approach

To solve this problem, we can use a backtracking approach. The algorithm generates all possible happy strings of length \( n \) and keeps track of their lexicographical order until it reaches the k-th happy string. Here’s how the approach works:

1. **Backtracking**: We will recursively build the happy strings by appending characters 'a', 'b', or 'c' while ensuring that we do not create three consecutive characters that are the same.

2. **Lexicographical Order**: The backtracking will inherently generate strings in lexicographical order due to the way characters are added ('a', 'b', 'c').

3. **Counting**: As we generate each happy string, we will count how many valid happy strings have been generated so far. When we reach the k-th happy string, we will store that result and stop further generation.

### Code Breakdown (Step by Step)

Let's break down the provided C++ code for the solution:

1. **Class and Member Variables**:
   ```cpp
   class Solution {
   public:
       string ans = "";
       int cnt = 0;
       int k, n;
   ```

   - A class named `Solution` is defined. It contains member variables to store the resulting happy string (`ans`), a count of generated happy strings (`cnt`), and the input values `k` and `n`.

2. **Main Function**:
   ```cpp
       string getHappyString(int n, int k) {
           this->k = k;
           this->n = n;
           string tmp = "";
           bt(-1, tmp);
           return ans;
       }
   ```

   - The method `getHappyString` takes two integers, \( n \) and \( k \), as input.
   - It initializes the member variables `k` and `n` and creates a temporary string `tmp` to build the happy strings.
   - It then calls the recursive function `bt` to start generating happy strings.
   - Finally, it returns the k-th happy string stored in `ans`.

3. **Backtracking Function**:
   ```cpp
       void bt(int prv, string &tmp) {
           if(tmp.size() == n) {
               cnt++;
               if(cnt == k) {
                   ans = tmp;  
               } 
               return;
           }
   ```

   - The method `bt` is defined for backtracking. It takes the index of the last character added (`prv`) and the temporary string (`tmp`) as parameters.
   - If the length of `tmp` equals \( n \), it means a complete happy string has been generated. The count is incremented, and if it matches \( k \), the string is stored in `ans`.
   - The function returns to stop further exploration for that branch.

4. **Character Addition Loop**:
   ```cpp
           for(int i = 0; i < 3; i++) {
               if(prv == i) continue;
               if(i == 0) {
                   tmp += 'a';
               } else if(i == 1) {
                   tmp += 'b';
               } else if(i == 2) {
                   tmp += 'c';
               }
               bt(i, tmp);
               tmp.pop_back();
           }
   ```

   - A loop iterates over the three possible characters (0 for 'a', 1 for 'b', 2 for 'c').
   - The condition `if(prv == i) continue;` ensures that we do not add the same character consecutively more than twice.
   - Depending on the value of `i`, the corresponding character is added to `tmp`.
   - The backtracking function `bt` is called recursively with the new last character index (`i`) and the updated string `tmp`.
   - After returning from recursion, the last character is removed from `tmp` using `tmp.pop_back()` to backtrack and explore other combinations.

5. **End of Class**:
   ```cpp
   };
   ```

   - The class definition ends here.

### Complexity

- **Time Complexity**:
  - The worst-case time complexity can be approximated as \( O(3^n) \) in generating all potential happy strings of length \( n \). However, since we are counting until the k-th string, in practice, the function will terminate early once it finds the k-th string, which optimizes the process significantly.

- **Space Complexity**:
  - The space complexity is \( O(n) \) due to the recursion stack and the temporary string `tmp` used in the backtracking process.

### Conclusion

The `getHappyString` function effectively generates and counts happy strings of a specified length \( n \) and retrieves the k-th such string using a backtracking approach. This solution not only leverages the properties of happy strings to enforce the constraints on character repetition but also ensures that strings are generated in lexicographical order. 

#### Key Takeaways:

- **Backtracking Techniques**: This problem showcases the power of backtracking in generating combinatorial solutions, where constraints need to be adhered to dynamically.
- **String Manipulation**: The method emphasizes how string construction and manipulation can be efficiently handled within recursive functions.
- **Performance Optimization**: The early termination upon reaching the k-th string provides an efficient solution to potentially large input sizes, making the function robust and performant.

Overall, this solution provides a clean and elegant approach to solving the problem while adhering to the constraints of happy strings.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
