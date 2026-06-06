#ifndef COLORS_H
#define COLORS_H

#ifdef _WIN32
  #include <windows.h>
  #include <stdio.h>

  #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
  #endif

  static inline void initConsole() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode)) {
      SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
  }

  static inline void _setColor(int attr) {
    fflush(stdout);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)attr);
  }

  #define COLOR_CYAN    _setColor(11)
  #define COLOR_GREEN   _setColor(10)
  #define COLOR_YELLOW  _setColor(14)
  #define COLOR_MAGENTA _setColor(13)
  #define COLOR_RED     _setColor(12)
  #define COLOR_RESET   _setColor(7)

#else
  #include <stdio.h>
  #define initConsole() ((void)0)
  #define COLOR_CYAN    printf("\033[36m")
  #define COLOR_GREEN   printf("\033[32m")
  #define COLOR_YELLOW  printf("\033[33m")
  #define COLOR_MAGENTA printf("\033[35m")
  #define COLOR_RED     printf("\033[31m")
  #define COLOR_RESET   printf("\033[0m")
#endif

#endif
