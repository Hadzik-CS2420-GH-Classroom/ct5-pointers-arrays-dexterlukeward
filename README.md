# CT5 – Pointers & Arrays Basics

## Overview

An in-class code-together activity introducing pointers, arrays, and the relationship between them. Students complete TODO items in three source files while the instructor walks through concepts using discussion comments and diagrams.

## Files

| File | Focus | TODOs |
|---|---|---|
| `pointers_and_arrays.cpp` | Declaring pointers, addresses, dereferencing, pointer arithmetic | 10 |
| `pointers_as_arrays.cpp` | Using `[]` on pointers, looping with `ptr[i]` | 4 |
| `arrays_as_pointers.cpp` | Array decay, passing arrays to pointer parameters | 4 |

## Teaching Order

Work through the files in the order `main.cpp` calls them:

### 1. `pointers_and_arrays.cpp` — Foundation

1. **Declaring pointers and arrays** — what a pointer is, pointing at an array element
2. **Address of array elements** — arrays live in contiguous memory (the "aha" moment when addresses differ by 4 bytes)
3. **Dereferencing** — reading and writing through a pointer (`*` and `&` operators)
4. **Pointer arithmetic** — walking through memory with `start + n`

### 2. `pointers_as_arrays.cpp` — Natural follow-up

1. **Bracket indexing on a pointer** — `ptr[2]` works on a pointer too
2. **Looping with `ptr[i]`** — reinforces that `ptr[i]` is just `*(ptr + i)`

### 3. `arrays_as_pointers.cpp` — The flip side

1. **Array decay** — passing `grades` to a `const int*` parameter happens automatically
2. **Pointer arithmetic on array name** — `*(grades + 2)` works directly on the array

## Diagrams

Four SVG/PNG diagrams support the activity. Source SVGs are in `images/svg/`, PNG exports in `images/`.

| Diagram | Referenced In | Shows |
|---|---|---|
| `array_in_memory` | `pointers_and_arrays.cpp` | Array memory layout, addresses, pointer arithmetic arrows |
| `pointer_address_value` | `pointers_and_arrays.cpp` | `*` and `&` operators, addresses vs values, "* does double duty" |
| `pointer_as_array` | `pointers_as_arrays.cpp` | `data` and `ptr` pointing to same memory, `ptr[2] = *(ptr+2)` equivalence |
| `pre_vs_post_increment` | `pointers_and_arrays.cpp` | `++p` vs `p++` step by step, why pre-increment is preferred |

## Grading (40 points)

| Category | Points | What is tested |
|---|---|---|
| Build | 2 | Project compiles without errors |
| `pointers_and_arrays.cpp` | 22 | Declaring pointers, addresses, dereferencing, pointer arithmetic, pointer walking loop |
| `pointers_as_arrays.cpp` | 8 | Bracket indexing on pointers, looping with `ptr[i]` |
| `arrays_as_pointers.cpp` | 8 | Array decay, pointer arithmetic on array name |
| **Total** | **40** | |

## Comment Conventions

Uses [Better Comments](https://marketplace.visualstudio.com/items?itemName=OmarRwemi.BetterComments) for VS 2022:

| Prefix | Color | Purpose |
|---|---|---|
| `// !` | Important (red) | `DISCUSSION:` teaching notes for instructor walkthrough |
| `// ?` | Question (blue) | `SEE DIAGRAM:` references to visual aids |
| `// TODO:` | Task (orange) | Student exercises (main branch) |

