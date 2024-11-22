
+++
authors = ["grid47"]
title = "Leetcode 1441: Build an Array With Stack Operations"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1441: Build an Array With Stack Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uK6JvnLUcck"
youtube_upload_date="2020-05-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uK6JvnLUcck/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int currElem=1;
        for(int i=0;i<target.size();i++){
            while(currElem!=target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                currElem++;
            }
            ans.push_back("Push");
            currElem++;
        }
        return ans;        
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to construct an array using a sequence of operations defined as "Push" and "Pop". You are given a target array, and you need to build this array from the empty state using integers from 1 to `n` sequentially. The operations "Push" and "Pop" correspond to pushing an integer onto a stack and removing the last pushed integer, respectively. The goal is to determine the exact sequence of operations needed to achieve the target array.

### Approach

To tackle this problem, we need to simulate the process of building the target array step by step. We can do this by iterating through the elements of the target array and performing the necessary operations. The approach can be summarized in the following steps:

1. **Initialize Variables**: We will maintain a result vector to store the operations and a variable to track the current integer being considered.

2. **Iterate Through Target Elements**: For each element in the target array:
   - If the current integer is less than the target element, we perform "Push" for the current integer and "Pop" for all integers up to but not including the target element.
   - Once the current integer matches the target element, we perform a "Push" to add the current integer to the result.

3. **Return the Result**: After processing all elements in the target array, we will return the sequence of operations stored in the result vector.

### Code Breakdown (Step by Step)

Let’s analyze the provided code in detail:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```

   - We define a class named `Solution`, which encapsulates the method to generate the required operation sequence.

2. **Function Declaration**:
   ```cpp
   vector<string> buildArray(vector<int>& target, int n) {
   ```

   - The function `buildArray` accepts two parameters: a vector of integers `target`, representing the desired array, and an integer `n`, representing the range of numbers that can be used (from 1 to `n`).

3. **Variable Initialization**:
   ```cpp
   vector<string> ans;
   int currElem = 1;
   ```

   - We declare a vector of strings `ans` to store the sequence of operations. The integer `currElem` is initialized to 1, indicating the next integer to consider for pushing onto the stack.

4. **Iterate Through Target Elements**:
   ```cpp
   for(int i = 0; i < target.size(); i++) {
   ```

   - A loop iterates through each element in the target array using the index `i`.

5. **Inner While Loop for Non-Matching Elements**:
   ```cpp
   while(currElem != target[i]) {
       ans.push_back("Push");
       ans.push_back("Pop");
       currElem++;
   }
   ```

   - Inside the loop, we check if the current element (`currElem`) is not equal to the target element at index `i`. If they are not equal, we perform the "Push" operation followed by the "Pop" operation. This is repeated until `currElem` matches the target element.

6. **Push the Current Element**:
   ```cpp
   ans.push_back("Push");
   currElem++;
   ```

   - Once `currElem` matches the target element, we perform a final "Push" operation to add this element to the sequence and increment `currElem` for the next iteration.

7. **Return the Result**:
   ```cpp
   return ans;        
   }
   ```

   - After processing all elements in the target array, we return the vector `ans`, which contains the complete sequence of operations.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(m)\), where \(m\) is the length of the target array. In the worst-case scenario, the number of operations performed may approach \(2m\) (when each target element requires pushing and popping for all preceding elements). However, since we are effectively processing each element in the target once, the overall complexity remains linear with respect to the length of the target array.

- **Space Complexity**: The space complexity is also \(O(m)\) due to the space required to store the output operations in the result vector.

### Conclusion

This solution efficiently constructs the desired array from a sequence of "Push" and "Pop" operations using a straightforward approach. By maintaining a counter for the current integer and iterating through the target elements, we ensure that the operations are performed in a manner that accurately reflects the rules of stack manipulation.

#### Key Takeaways:

1. **Stack Operations**: Understanding the operations of a stack (LIFO - Last In First Out) is crucial in solving problems involving dynamic construction of arrays or sequences.

2. **Simulation Approach**: The approach taken in this solution is a simulation of the desired process, highlighting how simple algorithms can effectively solve complex problems.

3. **Efficiency Considerations**: The solution is optimized to operate in linear time and space relative to the input size, making it suitable for scenarios where performance is critical.

Overall, this implementation serves as a solid example of how to model array construction using stack operations, and it can be extended or modified for similar problems in competitive programming or software development tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/build-an-array-with-stack-operations/description/)

---
{{< youtube uK6JvnLUcck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
