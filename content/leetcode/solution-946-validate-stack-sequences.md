
+++
authors = ["grid47"]
title = "Leetcode 946: Validate Stack Sequences"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 946: Validate Stack Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YF5ZWSWvMT0"
youtube_upload_date="2023-04-13"
youtube_thumbnail="https://i.ytimg.com/vi/YF5ZWSWvMT0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 1, j = 0;
        stk.push(pushed[0]);
        int n = pushed.size();
        while(i < n) {
            while(j < n && !stk.empty() && stk.top() == popped[j]) {
                j++;
                stk.pop();
            }
            stk.push(pushed[i++]);
        }
        while(j < n && !stk.empty() && stk.top() == popped[j]) {
            j++;
            stk.pop();
        }        
        
        return stk.empty();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine whether a sequence of operations is possible given two sequences, `pushed` and `popped`, representing a stack's push and pop operations. The `pushed` sequence represents the order in which elements are pushed onto the stack, while the `popped` sequence represents the order in which they are popped from the stack. The task is to verify whether it's possible to achieve the `popped` sequence using the `pushed` sequence while respecting the rules of a stack (i.e., LIFO order).

### Approach

To solve this problem, we need to simulate the stack operations based on the given `pushed` and `popped` sequences. The basic idea is to push elements onto a stack as per the `pushed` sequence and pop elements from the stack when they match the current element in the `popped` sequence. We need to ensure that the operations adhere to the LIFO (Last In, First Out) property of stacks. If, after processing both sequences, we have successfully matched the entire `popped` sequence, the result is `true`. Otherwise, it’s `false`.

Here’s how we can break down the approach:

1. **Simulate Stack Operations**: We will iterate through the `pushed` sequence, pushing elements onto the stack. At each step, we will check if the top of the stack matches the current element in the `popped` sequence. If they match, we pop the stack and move to the next element in `popped`. This simulates the operation of the stack as we process the elements.
  
2. **Ensure Stack Validity**: At the end of the process, if the stack is empty, then the operations were valid and we return `true`. If there are still elements in the stack that haven’t been popped in the correct order, we return `false`.

3. **Edge Case Handling**: We ensure that the process stops once all elements are processed, and the final stack check ensures that all pops have occurred in the correct order.

### Code Breakdown (Step by Step)

1. **Initial Setup**:
   ```cpp
   stack<int> stk;
   int i = 1, j = 0;
   stk.push(pushed[0]);
   int n = pushed.size();
   ```
   - We initialize a stack `stk` to simulate the stack operations.
   - We start with `i = 1` because we’ve already pushed the first element from `pushed` onto the stack. `j = 0` is the pointer for iterating through the `popped` sequence.
   - `n` holds the size of the `pushed` sequence to control the iteration.

2. **Push Elements and Pop When Possible**:
   ```cpp
   while(i < n) {
       while(j < n && !stk.empty() && stk.top() == popped[j]) {
           j++;
           stk.pop();
       }
       stk.push(pushed[i++]);
   }
   ```
   - The outer `while(i < n)` loop ensures that we keep pushing elements from `pushed` onto the stack.
   - The inner `while(j < n && !stk.empty() && stk.top() == popped[j])` loop checks if the top of the stack matches the current element in `popped`. If they match, we pop the stack and move to the next element in `popped`.
   - After checking for possible pops, we push the next element from `pushed` into the stack (`stk.push(pushed[i++])`).

3. **Final Check After the Loop**:
   ```cpp
   while(j < n && !stk.empty() && stk.top() == popped[j]) {
       j++;
       stk.pop();
   }
   ```
   - After we’ve pushed all elements from `pushed` to the stack, there might still be some elements in the stack that need to be popped. We check if the stack’s top matches the current element in `popped`. If they do, we pop the stack and move to the next element in `popped`.

4. **Final Return**:
   ```cpp
   return stk.empty();
   ```
   - If the stack is empty after processing both sequences, it means all elements were popped in the correct order as per the `popped` sequence, and we return `true`.
   - If the stack is not empty, it indicates that some elements were not popped in the expected order, so we return `false`.

### Complexity

1. **Time Complexity**:
   - The time complexity of this solution is O(n), where `n` is the number of elements in the `pushed` sequence. Each element is pushed and popped at most once from the stack, making the total number of operations proportional to the length of the sequences.
   
2. **Space Complexity**:
   - The space complexity is O(n), where `n` is the number of elements in the `pushed` sequence. We use a stack to store the elements temporarily, and in the worst case, the stack could hold all `n` elements.

### Conclusion

The solution efficiently simulates the stack operations using two pointers to track the `pushed` and `popped` sequences. By iterating through the `pushed` sequence and popping elements from the stack when they match the current element in `popped`, we can verify if the sequences can represent valid stack operations. The solution is optimal with a time complexity of O(n) and a space complexity of O(n), making it suitable for handling large inputs within reasonable limits.

[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-stack-sequences/description/)

---
{{< youtube YF5ZWSWvMT0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
