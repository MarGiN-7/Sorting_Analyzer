# Sorting Analyzer

A high-performance sorting algorithm analyzer written in **C**. This tool enables comprehensive performance testing and comparison of various sorting algorithms across different data scenarios.

## Overview

Sorting Analyzer provides an interactive platform to:
- Compare execution time across 6 different sorting algorithms
- Analyze performance metrics (comparisons and swaps)
- Test on auto-generated or manually input data
- Generate datasets with different patterns (random, sorted, reverse-sorted)

## Supported Sorting Algorithms

1. **Bubble Sort** - O(n²) simple comparison-based sort
2. **Selection Sort** - O(n²) minimizing swaps
3. **Insertion Sort** - O(n²) adaptive algorithm
4. **Merge Sort** - O(n log n) divide-and-conquer approach
5. **Quick Sort** - O(n log n) average, partitioning-based
6. **Count Sort** - O(n+k) non-comparative linear sort

## Features

✅ Real-time performance measurement (milliseconds)  
✅ Detailed metrics tracking (comparisons & swaps)  
✅ Multiple data generation modes (random, sorted, reverse-sorted)  
✅ Color-coded console output for easy visualization  
✅ Cross-platform compatibility (Windows & Linux)  
✅ Efficient memory management with dynamic arrays  
✅ Web interface for documentation and reference  

## Building & Running

### Prerequisites
- GCC compiler (or any C compiler)

### Compile
```bash
cd pbl
gcc -o sorter *.c -lm
```

### Run
```bash
./sorter
```

## Usage Guide

1. **Select Input Mode:**
   - Option 1: Auto-generate random/sorted/reverse-sorted data
   - Option 2: Manually enter array elements

2. **Specify Dataset:**
   - Enter array size
   - Choose data pattern (for auto-generation)

3. **Select Algorithms:**
   - Choose which sorting algorithms to compare
   - Can test multiple algorithms on the same dataset

4. **View Results:**
   - Execution time in milliseconds
   - Number of comparisons performed
   - Number of swaps performed
   - Performance summary (fastest/slowest)

## Project Structure

```
Sorting_Analyzer/
├── pbl/                      # C implementation
│   ├── main.c               # Program entry point
│   ├── analyzer.c/h         # Algorithm orchestration & result display
│   ├── bubble_sort.c/h      # Bubble Sort implementation
│   ├── selection_sort.c/h   # Selection Sort implementation
│   ├── insertion_sort.c/h   # Insertion Sort implementation
│   ├── merge_sort.c/h       # Merge Sort implementation
│   ├── quick_sort.c/h       # Quick Sort implementation
│   ├── count_sort.c/h       # Count Sort implementation
│   ├── input_handler.c/h    # User input management
│   ├── data_generator.c/h   # Test data generation
│   ├── timer.c/h            # Performance timing utilities
│   ├── metrics.h            # Metrics data structures
│   └── colors.h             # Cross-platform console coloring
│
├── src/                     # Web interface
│   ├── main.tsx            # React entry point
│   ├── App.tsx             # Main component
│   ├── index.css           # Styling
│   └── vite-env.d.ts       # TypeScript definitions
│
├── index.html              # Web interface entry
├── package.json            # Project dependencies
├── vite.config.ts          # Vite configuration
├── tsconfig.json           # TypeScript configuration
├── tailwind.config.js      # Tailwind CSS configuration
├── postcss.config.js       # PostCSS configuration
├── eslint.config.js        # ESLint configuration
├── .gitignore              # Git ignore rules
└── README.md              # This file
```

## Algorithm Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Count Sort | O(n+k) | O(n+k) | O(n+k) | O(k) |

## Example Usage

```
====================================================

   SORTING PERFORMANCE ANALYZER                    

====================================================

1.AUTO GENERATE
2. MANUAL INPUT
Choice: 1

-----------------------------------------------------

[OK] Data Generation Mode Selected
[OK] Data generated successfully.

Generated Array (100 elements):
[ 123456 654321 234567 ... ]

1.BUBBLE SORT
2.SELECTION SORT
3.INSERTION SORT
4.MERGE SORT
5.QUICK SORT
6.COUNT SORT
(press 0 to stop)
1
2
4
5
0

=====================================================================
| Algorithm        | Time (ms)     | Comparisons   | Swaps         |
=====================================================================
| Bubble Sort      |      12.3456  |        4950   |      2475     |
| Selection Sort   |       8.7654  |        4950   |        99     |
| Merge Sort       |       1.2345  |        668    |       100     |
| Quick Sort       |       0.8765  |        612    |       245     |
=====================================================================

--- PERFORMANCE SUMMARY ---
FASTEST: Quick Sort (0.8765 ms)
SLOWEST: Bubble Sort (12.3456 ms)
DIFFERENCE: 11.4691 ms
```

## Notes

- The program uses `malloc/free` for efficient memory management
- Timer uses `clock()` function for cross-platform compatibility
- Console colors are automatically handled for both Windows and Unix-like systems
- All sorting implementations maintain the same interface for easy comparison

## Future Enhancements

- [ ] Parallel sorting implementations
- [ ] Heap Sort and Shell Sort algorithms
- [ ] File input/output support
- [ ] Graph visualization of performance metrics
- [ ] Benchmark suite for automated testing

## License

Open source - Feel free to use, modify, and distribute!
