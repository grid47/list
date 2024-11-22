
+++
authors = ["grid47"]
title = "Leetcode 1124: Longest Well-Performing Interval"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1124: Longest Well-Performing Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Stack","Monotonic Stack","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Cu21ILZBx8"
youtube_upload_date="2024-03-19"
youtube_thumbnail="https://i.ytimg.com/vi/1Cu21ILZBx8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        int n = hours.size(), res = 0, score = 0;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            
            score += (hours[i] > 8) ? 1 : -1;
            
            if(score > 0)res = i + 1;
            else {

                if  (!mp.count(score))    mp[score] = i;
                if  (mp.count(score - 1)) res = max(res, i - mp[score -1]);

            }
        
        }
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to determine the length of the longest contiguous subarray in which the number of days with working hours greater than 8 exceeds the number of days with working hours less than or equal to 8. In simpler terms, we are to find the longest period during which the employee is more productive than not.

Given an array `hours` where each element represents the number of hours worked on a particular day, our objective is to find the length of the longest well-performing interval. 

For example, if the input is:
```
hours = [9, 7, 9, 7, 9, 9, 6]
```
The expected output would be `6`, as the longest subarray `[9, 7, 9, 9, 6]` has more days where hours worked exceeded 8.

### Approach
To tackle this problem, we can utilize a combination of prefix sums and a hash map to keep track of the earliest occurrences of each score. The algorithm follows these steps:
1. **Score Calculation**: Convert the hours worked into a score where:
   - A day with more than 8 hours contributes `+1` to the score.
   - A day with 8 hours or fewer contributes `-1` to the score.
   
2. **Tracking Prefix Sums**: As we traverse the `hours` array, we keep a running score. If the score is greater than `0`, it indicates that we have a valid well-performing interval from the start to the current index.

3. **Using a Map**: For scores that are not greater than `0`, we use a hash map to store the earliest index where each score occurred. This allows us to check if there exists an earlier score that could help extend our well-performing interval.

4. **Max Length Calculation**: Finally, we compare the current length of the well-performing interval with the maximum length found so far and update it accordingly.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class is defined to encapsulate the function `longestWPI`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Declaration**: The public function `longestWPI` takes a reference to a vector of integers, `hours`, and returns an integer.

   ```cpp
       int longestWPI(vector<int>& hours) {
   ```

3. **Variable Initialization**: Inside the function, variables for length, result, and score are initialized. A map to track scores is also defined.

   ```cpp
           int n = hours.size(), res = 0, score = 0;
           map<int, int> mp; // Map to store the first occurrence of each score
   ```

4. **Main Loop**: A loop iterates over each element in the `hours` vector to calculate the score based on working hours.

   ```cpp
           for(int i = 0; i < n; i++) {
               score += (hours[i] > 8) ? 1 : -1; // Calculate score
   ```

5. **Immediate Check for Positive Score**: If the score becomes positive, it means all days up to index `i` are part of a well-performing interval.

   ```cpp
               if(score > 0) res = i + 1; // Update result if score is positive
   ```

6. **Handling Non-Positive Scores**: If the score is not positive, we check the map. If the score does not exist in the map, we store the current index.

   ```cpp
               else {
                   if (!mp.count(score)) mp[score] = i; // Store first occurrence of score
   ```

7. **Checking for Previous Scores**: We check if there is a score one less than the current score in the map. If it exists, we calculate the possible interval length.

   ```cpp
                   if (mp.count(score - 1)) 
                       res = max(res, i - mp[score - 1]); // Update result based on the found score
               }
           }
   ```

8. **Return Statement**: Finally, the function returns the maximum length of the well-performing interval found.

   ```cpp
           return res;        
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \(O(N)\), where \(N\) is the number of days (or length of the `hours` array). This is because we are only making a single pass through the array.
  
- **Space Complexity**: The space complexity is \(O(N)\) in the worst case for the hash map that stores scores and their indices.

### Conclusion
The `longestWPI` function effectively finds the length of the longest well-performing interval of working hours using a straightforward and efficient algorithm. By transforming the problem into one of score accumulation and leveraging a hash map for quick lookups, the solution maintains optimal performance.

This approach illustrates how combining different programming techniques, such as prefix sums and hash maps, can yield efficient solutions to problems involving subarrays and conditions on their elements. Developers can apply similar techniques to a variety of problems in competitive programming and real-world applications.

In summary, this solution not only provides the correct result but does so with a time-efficient approach, making it a practical choice for similar tasks involving performance intervals in arrays.


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-well-performing-interval/description/)

---
{{< youtube 1Cu21ILZBx8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
