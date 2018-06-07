# Compile release
i686-w64-mingw32-gcc -o test.exe *.c utils/*.c

# Compile debug
i686-w64-mingw32-gcc -o test.exe *.c utils/*.c -D DEBUG
