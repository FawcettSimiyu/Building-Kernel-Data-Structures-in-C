# Warm-Up Assignment: Kernel Data Structures

**Course:** Operating Systems Principles  
**Professor:** Dr. Bhargav Bhatkalkar  
**Institution:** Knight Foundation School of Computing and Information Sciences, FIU  
**Term:** Spring 2025  
**Assignment:** Kernel Data Structures (Individual Submission)

---

## Student Group Information  
*Fill in your details:*

- **Full Name:** [Your Full Name]  
- **Panther ID:** [Your Panther ID]  
- **Email:** [Your FIU Email]  
- **Submission Date:** [MM/DD/YYYY]

---

## Project Overview  
Implement four core kernel data structures:

- **Stack** — call management and interrupt handling  
- **Circular Queue** — ring buffer and producer-consumer scheduling  
- **Circular Linked List** — round-robin schedulers  
- **Min-Priority Queue** — task prioritization and real-time scheduling  

---

## Implementation  
Completed source files (exact names):

- `Stack.c`  
- `Circular_Queue.c`  
- `Circular_Linked_List.c`  
- `Min_Heap.c` (Min-Priority Queue)

No changes made to `a1_header.h` or `driver.c`. All code follows provided interfaces.

---

## Testing  
Used these files:

- `TESTCASES.txt` — input test cases  
- `expected_output.txt` — instructor's expected output  
- `your_output.txt` — my program output  

## Build and test:

make  
./datastructure < TESTCASES.txt > your_output.txt  
diff expected_output.txt your_output.txt  
make clean  

### Generate expected output:

```bash
./A1_sample < TESTCASES.txt > expected_output.txt
```
