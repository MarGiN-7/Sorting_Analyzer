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
✅ Multiple data generation modes  
✅ Color-coded console output  
✅ Cross-platform compatibility (Windows & Linux)  

## Building & Running

```bash
cd pbl
gcc -o sorter *.c -lm
./sorter
```

## Usage

1. Select input mode (Auto-generate or Manual)
2. Specify array size or enter elements
3. Choose sorting algorithms to compare
4. View detailed performance analysis

## Project Structure

```
pbl/
├── main.c              # Entry point
├── analyzer.c/.h       # Algorithm orchestration
├── *_sort.c/.h         # Sorting implementations
├── input_handler.c/.h  # User input processing
├── data_generator.c/.h # Test data creation
├── timer.c/.h          # Performance timing
├── metrics.h           # Metrics structure
└── colors.h            # Console coloring utilities
```

## License

Open source - feel free to use and modify!
