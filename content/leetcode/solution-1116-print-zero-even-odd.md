
+++
authors = ["grid47"]
title = "Leetcode 1116: Print Zero Even Odd"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1116: Print Zero Even Odd in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
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
class ZeroEvenOdd {
private:
    int n;
    mutex mtx1, mtx2, mtx;
public:
    ZeroEvenOdd(int n) {
        mtx1.lock();
        mtx2.lock();
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        int t = 0;
        for(int j = 0; j < n; j++) {
            // cout << j << " ";
            mtx.lock();
            printNumber(0);
            if(t == 0) {
                t = 1;
                mtx1.unlock();         
            }
            else {
                t = 0;
                mtx2.unlock();            
            }            
        }
    }

    void even(function<void(int)> printNumber) {
        int i = 2;
        while(i <= n) {
            mtx2.lock();
            printNumber(i);
            mtx.unlock();
            i += 2;
        }
    }

    void odd(function<void(int)> printNumber) {
        int i = 1;
        while(i <= n) {
            mtx1.lock();
            printNumber(i);        
            mtx.unlock();
            i += 2;
        }
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to create a class `ZeroEvenOdd` that synchronizes the printing of numbers in a specific order:
1. A method `zero` that prints `0`.
2. A method `even` that prints even numbers from `2` to `n`.
3. A method `odd` that prints odd numbers from `1` to `n`.

The challenge is to ensure that the numbers are printed in the following sequence: `0`, `odd`, `0`, `even`, `0`, `odd`, `0`, `even`, and so on, until all numbers up to `n` are printed. Each of the methods should work in a multithreaded environment, and the class should be thread-safe.

### Approach
To achieve this synchronization, the implementation utilizes:
1. **Mutexes**: Three mutexes (`mtx`, `mtx1`, and `mtx2`) are used to control access to the printing functions and ensure the correct order of execution.
2. **Flags for Synchronization**: The class maintains a flag (`t`) to track whether the next number to be printed should be odd or even.
3. **Looping Mechanism**: Each method contains a loop that runs according to the value of `n`, printing the appropriate values while maintaining the required order using mutex locking and unlocking.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `ZeroEvenOdd` class is defined with private members to manage state and synchronization.

   ```cpp
   class ZeroEvenOdd {
   private:
       int n;                   // The maximum number to print
       mutex mtx1, mtx2, mtx;  // Mutexes for synchronization
   ```

2. **Constructor**: The constructor initializes `n` and locks `mtx1` and `mtx2` to ensure that the `even` and `odd` methods do not execute until the `zero` method has completed its first print.

   ```cpp
       public:
           ZeroEvenOdd(int n) {
               mtx1.lock(); // Lock mtx1 to block odd printing
               mtx2.lock(); // Lock mtx2 to block even printing
               this->n = n; // Set the maximum number
           }
   ```

3. **Zero Method**: The `zero` method prints `0` and manages the alternation between odd and even prints. It uses a flag `t` to decide which mutex to unlock after printing `0`.

   ```cpp
           void zero(function<void(int)> printNumber) {
               int t = 0; // Initialize toggle for odd/even
               for(int j = 0; j < n; j++) {
                   mtx.lock(); // Lock the mutex before printing
                   printNumber(0); // Print 0
                   if(t == 0) {
                       t = 1; // Switch to odd
                       mtx1.unlock(); // Unlock odd printing
                   }
                   else {
                       t = 0; // Switch to even
                       mtx2.unlock(); // Unlock even printing
                   }            
               }
           }
   ```

4. **Even Method**: The `even` method prints even numbers, ensuring it only executes when `mtx2` is unlocked.

   ```cpp
           void even(function<void(int)> printNumber) {
               int i = 2; // Start from 2
               while(i <= n) {
                   mtx2.lock(); // Wait for even print signal
                   printNumber(i); // Print the even number
                   mtx.unlock(); // Unlock for zero to print
                   i += 2; // Move to the next even number
               }
           }
   ```

5. **Odd Method**: Similarly, the `odd` method prints odd numbers while ensuring it only executes when `mtx1` is unlocked.

   ```cpp
           void odd(function<void(int)> printNumber) {
               int i = 1; // Start from 1
               while(i <= n) {
                   mtx1.lock(); // Wait for odd print signal
                   printNumber(i); // Print the odd number
                   mtx.unlock(); // Unlock for zero to print
                   i += 2; // Move to the next odd number
               }
           }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The overall time complexity for each of the three methods (`zero`, `even`, and `odd`) is \(O(n)\), since they each perform a loop that runs \(n\) times, executing constant-time operations (printing and locking/unlocking).
- **Space Complexity**: The space complexity is \(O(1)\), as the algorithm uses a constant amount of additional space regardless of the input size. Only a few integer variables and mutexes are declared.

### Conclusion
The `ZeroEvenOdd` class provides a clear and effective solution for synchronizing the printing of numbers in a specified order using multithreading. By employing mutexes for synchronization and a simple toggling mechanism to alternate between odd and even prints, the class effectively ensures that the output follows the required sequence.

This implementation serves as an excellent example of how to manage concurrent operations in C++. The use of mutexes highlights important techniques in synchronization and resource management in multithreaded applications. 

Moreover, this code is a practical application of thread-safe programming, demonstrating the need for careful coordination between threads to maintain the integrity of shared resources. As such, it can serve as a valuable reference for developers encountering similar challenges in their programming tasks.

Overall, the `ZeroEvenOdd` class exemplifies the balance between simplicity and effectiveness in concurrent programming, making it a noteworthy addition to the toolkit of developers working with multithreaded environments.


[`Link to LeetCode Lab`](https://leetcode.com/problems/print-zero-even-odd/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
