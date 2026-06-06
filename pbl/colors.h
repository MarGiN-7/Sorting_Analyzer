#ifndef COLORS_H
#define COLORS_H

#ifdef _WIN32
  #include <windows.h>

  enum Color { RESET = 7, CYAN = 11, GREEN = 10, YELLOW = 14, MAGENTA = 13, RED = 12, BOLD_ON = 15 };

  static inline void setColor(enum Color color) {
    fflush(stdout);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)color);
  }

  static inline void initConsole() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  }

  #define COLOR_CYAN    setColor(CYAN)
  #define COLOR_GREEN   setColor(GREEN)
  #define COLOR_YELLOW  setColor(YELLOW)
  #define COLOR_MAGENTA setColor(MAGENTA)
  #define COLOR_RED     setColor(RED)
  #define COLOR_RESET   setColor(RESET)

#else
  #define initConsole() ((void)0)
  #define COLOR_CYAN    printf("\033[36m")
  #define COLOR_GREEN   printf("\033[32m")
  #define COLOR_YELLOW  printf("\033[33m")
  #define COLOR_MAGENTA printf("\033[35m")
  #define COLOR_RED     printf("\033[31m")
  #define COLOR_RESET   printf("\033[0m")
#endif


#endif
