# compile release
i686-w64-mingw32-gcc -o test.exe *.c utils/*.c

# compile debug
i686-w64-mingw32-gcc -o test.exe *.c utils/*.c -D DEBUG
