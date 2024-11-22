
+++
authors = ["grid47"]
title = "Leetcode 1381: Design a Stack With Increment Operation"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1381: Design a Stack With Increment Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Design"]
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
class CustomStack {
    vector<int> stk;
    int ptr, m;
public:
    
    CustomStack(int mx) {
        stk.resize(mx);
        ptr = -1;
        m = mx;
    }
    
    void push(int x) {
        if (ptr < m - 1) {
            ptr++;
            stk[ptr] = x;
        }
    }
    
    int pop() {
        if(ptr == -1) return -1;
        return stk[ptr--];
    }
    
    void increment(int k, int val) {
        
        for(int i = 0; i < min(m, k); i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
{{< /highlight >}}
---

### Problem Statement

The task is to design a custom stack data structure that supports three primary operations: pushing an element onto the stack, popping the top element from the stack, and incrementing the bottom `k` elements of the stack by a given value. The stack has a fixed maximum size, and any attempts to push elements beyond this limit should be ignored. The main goal is to implement these functionalities efficiently while adhering to the stack's LIFO (Last In First Out) principle.

### Approach

To implement the `CustomStack` class, we can utilize a vector to store the stack elements, along with an integer pointer to track the current top of the stack. The operations can be defined as follows:

1. **Constructor**: Initialize the stack with a maximum size and set the pointer to indicate an empty stack.

2. **Push Operation**: Add an element to the top of the stack, ensuring that the stack does not exceed its maximum size.

3. **Pop Operation**: Remove and return the top element from the stack, checking if the stack is empty beforehand.

4. **Increment Operation**: Increment the bottom `k` elements of the stack by a specified value. This operation should be carefully implemented to respect the current number of elements in the stack.

### Code Breakdown (Step by Step)

The provided C++ code implements the `CustomStack` class with the described functionalities. Here’s a detailed breakdown of how it works:

1. **Class Definition**:
   ```cpp
   class CustomStack {
       vector<int> stk;
       int ptr, m;
   public:
   ```
   - The `CustomStack` class contains a vector `stk` to hold the stack elements, an integer `ptr` to keep track of the current top index, and an integer `m` for the maximum size of the stack.

2. **Constructor**:
   ```cpp
       CustomStack(int mx) {
           stk.resize(mx);
           ptr = -1;
           m = mx;
       }
   ```
   - The constructor takes an integer `mx` which represents the maximum size of the stack. It initializes the vector `stk` with the specified size, sets the pointer `ptr` to `-1` (indicating an empty stack), and assigns `m` to `mx`.

3. **Push Method**:
   ```cpp
       void push(int x) {
           if (ptr < m - 1) {
               ptr++;
               stk[ptr] = x;
           }
       }
   ```
   - The `push` method takes an integer `x` and checks if the stack can accommodate more elements (i.e., if `ptr` is less than `m - 1`). If there is space, it increments the pointer `ptr` and assigns the value `x` to `stk[ptr]`.

4. **Pop Method**:
   ```cpp
       int pop() {
           if(ptr == -1) return -1;
           return stk[ptr--];
       }
   ```
   - The `pop` method checks if the stack is empty (i.e., if `ptr` is `-1`). If the stack is not empty, it returns the top element (`stk[ptr]`) and decrements the pointer.

5. **Increment Method**:
   ```cpp
       void increment(int k, int val) {
           for(int i = 0; i < min(m, k); i++)
               stk[i] += val;
       }
   ```
   - The `increment` method takes two parameters: `k`, the number of bottom elements to increment, and `val`, the value to increment by. It uses a loop to iterate through the bottom `k` elements (up to the current maximum size of the stack) and adds `val` to each of those elements. The loop runs for `min(m, k)` to ensure that we do not exceed the bounds of the vector.

### Complexity

- **Time Complexity**:
  - **Push Operation**: The `push` operation runs in \(O(1)\) time since it only involves checking a condition and updating a pointer.
  - **Pop Operation**: The `pop` operation also runs in \(O(1)\) time, as it involves checking the pointer and returning an element.
  - **Increment Operation**: The `increment` operation has a time complexity of \(O(k)\), where \(k\) is the number of elements to increment. In the worst case, this could be up to \(O(m)\) if all elements need to be incremented.

- **Space Complexity**: The space complexity is \(O(m)\) due to the storage of the stack elements in the vector.

### Conclusion

The `CustomStack` class is an efficient implementation of a stack with additional functionalities, including a push operation, a pop operation, and an increment operation that modifies the bottom elements of the stack. The use of a vector allows dynamic management of the stack size, while the pointer helps maintain the current state of the stack efficiently. The operations are designed to be efficient and straightforward, adhering to the principles of stack data structures. This implementation serves as a practical reference for developers and students learning about data structures, particularly for applications requiring dynamic array management and stack operations. Furthermore, understanding this design can provide a foundation for exploring more complex data structure implementations and algorithms in computer science.

[`Link to LeetCode Lab`](https://leetcode.com/problems/design-a-stack-with-increment-operation/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
