
+++
authors = ["grid47"]
title = "Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1111: Maximum Nesting Depth of Two Valid Parentheses Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lHzdbjyqBG4"
youtube_upload_date="2024-05-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lHzdbjyqBG4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> groups;
        int d = 0;
        for(char c: seq) {
            bool open = c == '(';
            if(open) d++;
            groups.push_back(d%2);
            if(!open) d--;
        }
        return groups;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to split a sequence of parentheses into two groups such that the maximum depth of nesting in each group is minimized. The input is a string consisting of only '(' and ')', representing open and close parentheses, respectively. The goal is to return a vector where each position indicates the group to which the corresponding parenthesis belongs. The splitting should be done in a way that allows for balanced nesting of parentheses.

**Input:**
- A string `seq` representing the parentheses sequence.

**Output:**
- A vector of integers (0 or 1) indicating the group assignment for each parenthesis in the sequence.

### Approach
To solve this problem, we can utilize a simple iteration technique:
1. Initialize a depth counter that tracks the current level of nesting in the parentheses.
2. Traverse through each character in the string:
   - Increment the depth counter for an opening parenthesis '('.
   - Record the group for each parenthesis based on whether the current depth is odd or even:
     - If the depth is even, assign it to group 0.
     - If the depth is odd, assign it to group 1.
   - Decrement the depth counter for a closing parenthesis ')'.
3. Return the vector of group assignments.

This method ensures that the parentheses are divided into two groups while maintaining the nesting structure, effectively minimizing the maximum depth after the split.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class encapsulates the function for processing the parentheses.

   ```cpp
   class Solution {
   public:
       vector<int> maxDepthAfterSplit(string seq) {
   ```

2. **Variable Initialization**: We define a vector `groups` to hold the group assignments and an integer `d` to keep track of the current depth.

   ```cpp
           vector<int> groups;  // Vector to store the group assignment for each parenthesis
           int d = 0;  // Current depth of nesting
   ```

3. **Iteration through the Sequence**: We iterate through each character in the input string.

   ```cpp
           for(char c: seq) {
               bool open = c == '(';  // Check if the current character is an opening parenthesis
   ```

4. **Updating Depth**: For each opening parenthesis, we increment the depth counter. For a closing parenthesis, we decrement it after processing.

   ```cpp
               if(open) d++;  // Increment depth for '('
               groups.push_back(d % 2);  // Assign group based on current depth (0 for even, 1 for odd)
               if(!open) d--;  // Decrement depth for ')'
           }
   ```

5. **Return the Result**: Finally, we return the vector containing the group assignments for each parenthesis.

   ```cpp
           return groups;  // Return the vector of group assignments
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of the algorithm is \(O(n)\), where \(n\) is the length of the input string. This is because we traverse each character exactly once.
- **Space Complexity**: The space complexity is \(O(n)\) as well, since we are storing the group assignments for each character in a vector.

### Conclusion
The provided C++ code efficiently solves the problem of splitting a sequence of parentheses into two groups while minimizing the maximum depth of nesting in each group. By utilizing a straightforward iteration and a depth counter, the algorithm maintains clarity and efficiency, making it an excellent solution for this type of problem.

This solution is an excellent example of how to handle nested structures using depth tracking, which can be applied to various problems involving balanced parentheses or nested data structures. 

Overall, this implementation serves as a valuable reference for those looking to understand algorithms related to parentheses grouping and nesting, showcasing a practical approach to solving a common algorithmic challenge.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/)

---
{{< youtube lHzdbjyqBG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
