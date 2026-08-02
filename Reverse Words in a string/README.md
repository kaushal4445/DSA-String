# 🔄 Reverse Words in a String

This repository explains two similar problems from different platforms:

- ✅ LeetCode 151 – Reverse Words in a String
- ✅ GeeksforGeeks – Reverse Words

Although both problems look similar, **the separator between words is different**, so the implementation changes slightly.

---

# 📌 Difference Between LeetCode and GeeksforGeeks

| Platform | Separator | Example Input | Example Output |
|----------|-----------|---------------|----------------|
| LeetCode | Space `' '` | `"the sky is blue"` | `"blue is sky the"` |
| GeeksforGeeks | Dot `'.'` | `"i.like.this.program"` | `"program.this.like.i"` |

---

# ✅ Solution 1 : LeetCode (Reverse Words in a String)

## Problem

Given a string containing words separated by spaces, return the words in reverse order.

### Example

Input

```text
the sky is blue
```

Output

```text
blue is sky the
```

---

## 💡 Idea

Instead of moving words one by one,

1. Reverse the whole string.
2. Extract every reversed word.
3. Reverse each word again.
4. Append it into the answer.

---

## C++ Code

```cpp
class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {

            string word = "";

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length() > 0)
                ans += " " + word;
        }

        return ans.substr(1);
    }
};
```

---

## Step 1

Original

```text
the sky is blue
```

Reverse entire string

```text
eulb si yks eht
```

Diagram

```text
the sky is blue

↓

eulb si yks eht
```

---

## Step 2

Read first word

```text
eulb
```

Reverse

```text
blue
```

Answer

```text
blue
```

---

## Step 3

Read

```text
si
```

Reverse

```text
is
```

Answer

```text
blue is
```

---

## Step 4

Read

```text
yks
```

Reverse

```text
sky
```

Answer

```text
blue is sky
```

---

## Step 5

Read

```text
eht
```

Reverse

```text
the
```

Final

```text
blue is sky the
```

---

## Dry Run

| Current Word | Reverse Word | Answer |
|--------------|-------------|--------|
| eulb | blue | blue |
| si | is | blue is |
| yks | sky | blue is sky |
| eht | the | blue is sky the |

---

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n)
```

---

# ✅ Solution 2 : GeeksforGeeks (Reverse Words)

## Problem

Words are separated by dots (`.`).

Reverse only the order of the words.

### Example

Input

```text
i.like.this.program.very.much
```

Output

```text
much.very.program.this.like.i
```

---

# Method 1 : Reverse Entire String (Same Idea as LeetCode)

The logic is exactly the same.

The only difference is that words are separated by dots instead of spaces.

---

## Code

```cpp
class Solution {
public:
    string reverseWords(string &s) {

        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {

            string word = "";

            while(i < n && s[i] != '.') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(word.length() > 0)
                ans += "." + word;
        }

        return ans.substr(1);
    }
};
```

---

## Dry Run

Input

```text
i.like.this.program
```

Reverse string

```text
margorp.siht.ekil.i
```

Read words

```text
margorp

↓

program

Answer

program
```

Next

```text
siht

↓

this

Answer

program.this
```

Next

```text
ekil

↓

like

Answer

program.this.like
```

Next

```text
i

↓

i

Answer

program.this.like.i
```

---

## Diagram

```text
Original

i.like.this.program

↓

Reverse Entire String

margorp.siht.ekil.i

↓

Reverse Each Word

program.this.like.i
```

---

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n)
```

---

# ✅ Method 2 : Two Pointer (Recommended for GFG)

Instead of reversing the whole string,

we scan from the end and directly copy each word into the answer.

---

## Code

```cpp
class Solution {
public:
    string reverseWords(string &s) {

        string ans = "";
        int i = s.length() - 1;

        while(i >= 0) {

            int j = i;

            while(j >= 0 && s[j] != '.')
                j--;

            ans += s.substr(j + 1, i - j);

            if(j > 0)
                ans += ".";

            i = j - 1;
        }

        return ans;
    }
};
```

---

## Step-by-Step

Input

```text
i.like.this.program
```

Start from the end

```text
i.like.this.program
               ↑
```

Read

```text
program
```

Answer

```text
program
```

Move left

```text
i.like.this.program
          ↑
```

Read

```text
this
```

Answer

```text
program.this
```

Move left

```text
i.like.this.program
     ↑
```

Read

```text
like
```

Answer

```text
program.this.like
```

Move left

```text
i.like.this.program
↑
```

Read

```text
i
```

Final

```text
program.this.like.i
```

---

## Diagram

```text
Input

i.like.this.program

          ↑

Read "program"

↓

program

Move Left

↓

Read "this"

↓

program.this

Move Left

↓

Read "like"

↓

program.this.like

Move Left

↓

Read "i"

↓

program.this.like.i
```

---

## Dry Run Table

| i | Word Found | Answer |
|---|------------|--------|
| Last | program | program |
| | this | program.this |
| | like | program.this.like |
| | i | program.this.like.i |

---

## Time Complexity

```text
O(n)
```

## Space Complexity

```text
O(n)
```

---

# 🔥 Comparison

| Feature | LeetCode | GFG (Method 1) | GFG (Method 2) |
|----------|----------|----------------|----------------|
| Separator | Space | Dot | Dot |
| Reverse Entire String | ✅ | ✅ | ❌ |
| Reverse Each Word | ✅ | ✅ | ❌ |
| Scan from End | ❌ | ❌ | ✅ |
| Time Complexity | O(n) | O(n) | O(n) |
| Space Complexity | O(n) | O(n) | O(n) |

---

# 📚 Key Takeaways

### LeetCode

- Reverse the entire string.
- Reverse each word.
- Ignore multiple spaces.
- Return words separated by a single space.

### GeeksforGeeks

- Words are separated by `.` instead of spaces.
- You can either:
  - Reverse the whole string and then each word, or
  - Use the two-pointer approach (recommended), which scans from the end and avoids reversing the entire string.

Both approaches run in **O(n)** time, but the **two-pointer approach** is generally considered cleaner and is the one most commonly expected for the GeeksforGeeks version.
