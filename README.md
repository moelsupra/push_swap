*This project has been created as part of the 42 curriculum by moelamma.*


# Push Swap

## Description

**Push_swap** is a sorting algorithm project that sorts a stack of integers using a limited set of operations with the minimum number of moves.

### Goal
Sort integers in ascending order using only these operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

**Performance targets:**
- 100 numbers: < 700 operations
- 500 numbers: < 5500 operations

**Achieved performance:**
- 100 numbers: ~550-600 operations ✅
- 500 numbers: ~5000-5200 operations ✅

---

## Instructions

### Compilation
```bash
make            # Compile
make clean      # Remove objects
make fclean     # Remove all generated files
make re         # Recompile
```

### Usage
```bash
./push_swap [integers]

# Examples
./push_swap 3 2 1
./push_swap "5 2 8 1 9"
./push_swap $(shuf -i 1-100 -n 100)
```

### Testing & Visualization
```bash
# Test performance
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# Visualize sorting
# Use: https://push-swap42-visualizer.vercel.app/
```

---

## Algorithm

### Small stacks (2-5 numbers)
Hardcoded optimal solutions.

### Large stacks (100-500 numbers)
**Chunk sorting algorithm:**
1. Divide numbers into chunks by sorted index
2. Push chunks to stack B strategically (smallest first)
3. Push back to A from largest to smallest
4. Result: sorted stack A

## Resources

### Documentation

- [least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

- [Turk algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

- [Push_swap Subject](https://cdn.intra.42.fr/pdf/pdf/189070/en.subject.pdf)

- [Visualizer Tool](https://push-swap42-visualizer.vercel.app/)

### AI Usage

AI was used as a **learning assistant and debugging tool**, not as a code generator. Specific uses:

**Understanding Concepts:**
- Learning optimal sorting algorithm approaches for different input sizes

**Development Process:**
- Iterative debugging of memory leaks and edge cases
- Optimizing chunk size selection through performance analysis
- Code review for best practices and optimization opportunities

**Knowledge Verification:**
- Confirming algorithm correctness and time complexity
- Validating test case coverage
- Ensuring proper error handling for all input scenarios

All implementations were coded manually with full understanding of the logic, data structures, and algorithms used. AI served as a guide to deepen comprehension and improve code quality, similar to having a knowledgeable peer reviewer.