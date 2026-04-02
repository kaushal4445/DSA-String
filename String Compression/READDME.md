🧩 String Compression (LeetCode 443)
<p align="center"> <img src="https://img.shields.io/badge/LeetCode-443-orange?style=for-the-badge"/> <img src="https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge"/> <img src="https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge"/> <img src="https://img.shields.io/badge/Approach-Two%20Pointers-green?style=for-the-badge"/> </p>
📌 Problem Statement

Given an array of characters chars, compress it using the following rules:

For each group of consecutive repeating characters:
If length = 1 → append character
If length > 1 → append character + count

⚠️ Modify the array in-place and return the new length.

🧠 Intuition

We group consecutive characters and replace them with:

character + frequency
📊 Visual Diagram
🔹 Example 1
Input:
[a, a, b, b, c, c, c]

Step 1: Grouping
[aa] [bb] [ccc]

Step 2: Compression
[a2] [b2] [c3]

Final Output:
[a, 2, b, 2, c, 3]
🔹 Example 2
Input:
[a, a, a, b, b, a, a]

Grouping:
[aaa] [bb] [aa]

Compression:
[a3] [b2] [a2]

Output:
[a, 3, b, 2, a, 2]
⚙️ Approach (Two Pointer Technique)
🔁 Core Idea

We use two pointers:

Pointer	Role
i	Reads input
idx	Writes compressed output
🧭 Flow Diagram
Start
  ↓
Pick character (ch)
  ↓
Count consecutive occurrences
  ↓
Write character
  ↓
Is count > 1?
   ↙        ↘
 Yes        No
 ↓           ↓
Write count  Skip
  ↓
Move to next group
  ↓
End
🔍 Step-by-Step Dry Run
Input:
[a, a, b, c, c]
Step	Character	Count	Array State
1	a	2	a2
2	b	1	a2b
3	c	2	a2bc2
✅ Final Output:
[a, 2, b, c, 2]
Length = 5
💻 C++ Solution
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while(i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Write character
            chars[idx++] = ch;

            // Write count if greater than 1
            if(count > 1) {
                string str = to_string(count);
                for(char digit : str) {
                    chars[idx++] = digit;
                }
            }

            i--; // adjust index
        }

        // Resize to final length
        chars.resize(idx);
        return idx;
    }
};
⚠️ Important Concepts
🔸 Why i--?
The while loop already moves i forward
The for loop will also increment it
So we step back once to avoid skipping elements
🔸 Handling Multi-Digit Counts
count = 12
→ "12"
→ stored as '1', '2'
⏱️ Complexity Analysis
Type	Complexity
🕒 Time	O(n)
🧠 Space	O(1) (in-place)
🚀 Key Features

✔️ In-place compression
✔️ Efficient (single pass)
✔️ Handles large counts
✔️ Clean two-pointer logic

🧪 Edge Cases
Single character → ['a']
No repetition → ['a','b','c']
Large counts → ['a' x 12] → ['a','1','2']
🏁 Conclusion

This problem is a perfect example of:

✨ Two Pointer Technique
✨ In-place Array Manipulation
✨ String Processing

Mastering this helps in many real interview problems 🔥
