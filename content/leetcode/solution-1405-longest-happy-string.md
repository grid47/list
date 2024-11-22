
+++
authors = ["grid47"]
title = "Leetcode 1405: Longest Happy String"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1405: Longest Happy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "8u-H6O_XQKE"
youtube_upload_date="2022-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/8u-H6O_XQKE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        if(a > 0)
        pq.push({a, 'a'});
        if(b > 0)
        pq.push({b, 'b'});
        if(c > 0)
        pq.push({c, 'c'});
        
        string res = "";
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            res += string(min(2, it.first), it.second);
            it.first -= min(2, it.first);
            
            if(pq.empty()) break;
            auto it2 = pq.top();
            pq.pop();
            res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
            it2.first -= min(it.first > it2.first? 1: 2, it2.first);
            
            if(it.first > 0) pq.push(it);
            if(it2.first > 0) pq.push(it2);
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to generate the longest possible string using three types of characters ('a', 'b', and 'c') while adhering to the following constraints:
- No character can appear more than two consecutive times.
- You are given the counts of each character as inputs, specifically `a` for 'a', `b` for 'b', and `c` for 'c'.

For instance, if `a = 1`, `b = 1`, and `c = 7`, a possible valid output could be "ccbccacc" or any other combination that respects the constraints.

### Approach

To tackle this problem, we employ a greedy strategy using a max heap (priority queue). The steps involved in constructing the longest diverse string are as follows:

1. **Initialization of the Max Heap**: We first push the counts of the characters into a priority queue. This allows us to always retrieve the character with the highest remaining count.

2. **Building the Result String**: 
   - In each iteration, we take the character with the highest count and add it to our result string, ensuring that we do not add it more than twice consecutively.
   - If the heap is not empty after processing the first character, we take the next character and add it as well, while again adhering to the two-consecutive character rule.

3. **Updating Counts**: After using a character, we decrement its count and push it back into the heap if it still has a remaining count.

4. **Termination**: The process continues until we have exhausted all characters or cannot add any more without violating the constraints.

### Code Breakdown (Step by Step)

Here’s a line-by-line breakdown of the provided C++ code implementing the above logic:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - A class named `Solution` is defined to contain the method `longestDiverseString`.

2. **Method Signature**:
   ```cpp
       string longestDiverseString(int a, int b, int c) {
   ```
   - The method `longestDiverseString` takes three integers (`a`, `b`, and `c`) as parameters, which represent the counts of characters 'a', 'b', and 'c', respectively.

3. **Priority Queue Initialization**:
   ```cpp
           priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
   ```
   - We initialize a max heap `pq` to store pairs of character counts and characters. The heap will always allow us to retrieve the character with the highest remaining count.

4. **Filling the Heap**:
   ```cpp
           if(a > 0) pq.push({a, 'a'});
           if(b > 0) pq.push({b, 'b'});
           if(c > 0) pq.push({c, 'c'});
   ```
   - We push each character with a count greater than zero into the priority queue.

5. **Result String Initialization**:
   ```cpp
           string res = "";
   ```
   - A string `res` is initialized to build the final result.

6. **Main Loop**:
   ```cpp
           while(!pq.empty()) {
   ```
   - The loop continues as long as there are characters available in the heap.

7. **Processing the Most Frequent Character**:
   ```cpp
               auto it = pq.top();
               pq.pop();
               res += string(min(2, it.first), it.second);
               it.first -= min(2, it.first);
   ```
   - We retrieve the character with the highest count, remove it from the heap, and append it to `res` up to two times. The count is then decremented by the number of characters added.

8. **Handling the Second Character**:
   ```cpp
               if(pq.empty()) break;
               auto it2 = pq.top();
               pq.pop();
               res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
               it2.first -= min(it.first > it2.first? 1: 2, it2.first);
   ```
   - If the heap is not empty, we then retrieve the next most frequent character and add it to the result. The number of times it is added is determined based on the remaining count of the first character. If the first character's count is greater than the second, we add only one occurrence of the second character.

9. **Re-adding Characters to the Heap**:
   ```cpp
               if(it.first > 0) pq.push(it);
               if(it2.first > 0) pq.push(it2);
   ```
   - After processing, we check if the remaining counts of the characters are greater than zero and push them back into the heap for further processing.

10. **Return Statement**:
    ```cpp
           return res;
       }
   };
   ```
    - Finally, the constructed string `res` is returned as the output.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \( O(n \log 3) \), where \( n \) is the total number of characters added to the result string. Since we are pushing and popping from a max heap, each operation takes logarithmic time, and we perform a limited number of operations (due to the three characters).

- **Space Complexity**: 
  - The space complexity is \( O(1) \) if we consider the size of the heap to be constant (three characters), or \( O(n) \) where \( n \) is the number of characters if we consider the result string.

### Conclusion

The solution effectively utilizes a greedy approach and a priority queue to ensure that the longest diverse string is generated while respecting the constraints of character frequency. This algorithm is efficient and straightforward, making it a great example of combining data structures with greedy algorithms to solve combinatorial problems.

#### Key Takeaways:

- **Greedy Strategy**: Utilizing the character counts to decide the order of character addition ensures that the solution remains optimal.
- **Data Structures**: The use of a priority queue simplifies the retrieval of the most frequent characters efficiently.
- **Character Frequency Management**: The code handles character frequency dynamically, allowing for a flexible construction of the output string based on remaining character counts.

Overall, this implementation provides an elegant solution to the problem, demonstrating the power of combinatorial algorithms in generating structured outputs from given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-happy-string/description/)

---
{{< youtube 8u-H6O_XQKE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
