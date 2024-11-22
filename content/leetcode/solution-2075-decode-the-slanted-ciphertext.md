
+++
authors = ["grid47"]
title = "Leetcode 2075: Decode the Slanted Ciphertext"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2075: Decode the Slanted Ciphertext in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vFxVjspTM-0"
youtube_upload_date="2021-11-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vFxVjspTM-0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeCiphertext(string et, int rows) {
        cout << et.size() << " " << rows;
        string res = "";
        int col = et.size() / rows;
        int idx = 0;
        string space = "";
        // cout << col << " " << rows << " ";
        while(idx < col - rows + 2) {
            for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
                if(et[idx + i + i * col] == ' ')
                    space += ' ';
                else {
                    res += (space + et[idx + i + i * col]);                    
                    space = "";
                }

            }
            idx++;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to decode a ciphered text that has been formatted into a grid with a specified number of rows. Given a string `et` (the encoded text) and an integer `rows`, the goal is to reconstruct the original message by reading the characters in a specific zigzag pattern from the grid. The text is filled in column-wise from the top down and then continues to the next column, which introduces spaces that need to be handled appropriately.

### Approach

To decode the text effectively, we follow these steps:

1. **Input Interpretation**: The encoded text is represented by a string `et`, and we know how many rows were used to format this string into a grid. The columns can be inferred based on the length of `et` divided by `rows`.

2. **Determine Grid Dimensions**: Calculate the number of columns in the grid by dividing the total length of the encoded text by the number of rows.

3. **Iterative Decoding**: We iterate through the encoded text in a loop to reconstruct the original message. The decoding involves reading characters from the encoded string in a manner that respects the row structure, specifically:
   - Reading the characters at intervals determined by the grid layout.
   - Collecting characters while managing spaces that separate words.

4. **Handle Spaces**: As we reconstruct the message, we need to ensure that spaces are preserved correctly. If a character is a space, we need to manage it by adding it to a temporary string, which can be appended to the result once a non-space character is encountered.

5. **Return the Result**: After completing the iterations, we return the decoded string as the final output.

### Code Breakdown (Step by Step)

1. **Function Definition**: The function `decodeCiphertext` is defined to accept the encoded string `et` and an integer `rows`.

   ```cpp
   string decodeCiphertext(string et, int rows) {
   ```

2. **Initialization**: We initialize the resultant string (`res`), calculate the number of columns (`col`), and set the starting index (`idx`). We also prepare a string to handle spaces.

   ```cpp
   string res = "";
   int col = et.size() / rows;
   int idx = 0;
   string space = "";
   ```

3. **Main Loop**: A while loop is initiated to iterate over potential starting points in the grid. This loop continues as long as `idx` is less than `col - rows + 2`, which ensures that we stay within the bounds of the encoded text.

   ```cpp
   while(idx < col - rows + 2) {
   ```

4. **Nested Loop**: Inside the while loop, we have a nested for loop that iterates through the number of rows. For each row, we compute the corresponding character position in the encoded string using the formula `idx + i + i * col`.

   ```cpp
   for(int i = 0; i < rows && idx + i + i * col < et.size(); i++) {
   ```

5. **Character Handling**:
   - If the character at the calculated position is a space, we add a space to the `space` string.
   - If it is not a space, we append any accumulated spaces to the result followed by the current character, and reset the `space` string.

   ```cpp
   if(et[idx + i + i * col] == ' ')
       space += ' ';
   else {
       res += (space + et[idx + i + i * col]);                    
       space = "";
   }
   ```

6. **Incrementing Index**: After processing the current index, we increment `idx` to move to the next starting point in the grid.

   ```cpp
   idx++;
   ```

7. **Return Statement**: Finally, we return the constructed string `res`.

   ```cpp
   return res;
   }
   ```

### Complexity

- **Time Complexity**: The overall time complexity of this approach is \(O(n)\), where \(n\) is the length of the encoded text. This is because each character is processed at most once in the nested loops.

- **Space Complexity**: The space complexity is \(O(m)\), where \(m\) is the size of the resulting decoded string. Additional space is used for temporary variables, but it does not grow with input size.

### Conclusion

The `decodeCiphertext` function effectively reconstructs the original message from an encoded string formatted in a grid layout. By iterating through the string in a structured manner and managing spaces properly, the solution demonstrates a clear and efficient way to decode text based on specified dimensions.

This solution is applicable in various scenarios, such as deciphering encoded messages in communication protocols or processing formatted data that requires careful arrangement and extraction of meaningful information. Its linear time complexity ensures that it can handle larger inputs efficiently, making it a robust choice for similar decoding problems.

Overall, this implementation serves as a solid example of how to manipulate and decode strings in a structured format, highlighting the importance of understanding the underlying data representation and the strategies needed to extract useful information from it. Future improvements could focus on optimizing space usage or extending the functionality to handle more complex decoding schemes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/decode-the-slanted-ciphertext/description/)

---
{{< youtube vFxVjspTM-0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
