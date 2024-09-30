# hexdump


`hexdump` is a program that prints out the contents of memory in hexadecimal format, 16 bytes to a line. It can be useful to inspect the contents of memory while we're debugging a program. For example, we could have used it in Homework 1 to verify that the contents of the `bss` segment had been cleared to zero.

You can use the Linux/Mac OS command `hexdump` to print out the contents of a file on your disk in hex format:

        neil@Neils-MacBook-Pro ~ $ hexdump -C somefile
        00000000  00 08 08 38 00 00 04 00  00 00 04 b6 00 00 04 74  |...8...........t|
        00000010  00 00 04 50 00 00 05 06  00 00 04 f2 00 00 04 de  |...P............|
        00000020  00 00 04 ca 00 00 05 1a  00 00 04 14 00 00 04 32  |...............2|
        00000030  00 00 05 56 00 00 05 56  00 00 04 a2 00 00 05 2e  |...V...V........|
        00000040  00 00 05 56 00 00 05 56  00 00 05 56 00 00 05 56  |...V...V...V...V|
        *
        00000060  00 00 05 42 00 00 05 6a  00 00 05 88 00 00 05 a6  |...B...j........|
        00000070  00 00 06 1e 00 00 05 c4  00 00 05 e2 00 00 06 00  |................|
        00000080  00 00 05 56 00 00 05 56  00 00 05 56 00 00 05 56  |...V...V...V...V|
        *
        000000c0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        *

In the first column, `hexdump` prints the offset from the beginning of the file (in hex). Then it prints out 16 bytes of data in hex format, two characters each. At the end of the line, it prints out the ASCII equivalent representation of the 16 bytes. In this activity, you're going to write `hexdump` in C to print out the contents of memory in the same format instead of the contents of a file. Your function should take two arguments: the address beginning of the memory buffer to print and the number of bytes to print:

        void hexdump(char *buffer, unsigned int length) {

        }

You will write this program and test it **in Linux**, not in the Pi OS operating system. You should use the `printf` function to print the address at the beginning of every line. Then call `printf` again sixteen times to print the data at that address. You can stop when you have printed the number of bytes requested (length in the function prototype above).


## Hints

`printf` has [a bunch of different format specifiers](https://www.cplusplus.com/reference/cstdio/printf/) you can use. In this assignment you're going to want to use the the ones that print integers in hex format. 

 | Format Specifier | Output Type                           | Example Usage                                          | Example Output  |
 |------------------|---------------------------------------|--------------------------------------------------------|-----------------|
 | `%p`             | Pointer                               | `int *ptr = 0x800;`<br>`printf("%p",ptr);`             | 0x800           |
 |------------------|---------------------------------------|--------------------------------------------------------|-----------------|
 | `%x`             | Hex Integer (lowercase)               | `int number = 0xDEADBEEF;`<br>`printf("%x",number);`   | deadbeef        |
 |------------------|---------------------------------------|--------------------------------------------------------|-----------------|
 | `%02x`           | Hex Int w/ Specified Number of Digits | `int number = 0x05;`<br>`printf("%02x",number);`       | 05              |
 |------------------|---------------------------------------|--------------------------------------------------------|-----------------|


### Testing Your `hexdump`


There are couple of ways to check if your implementation is working.

#### Testing `hexdump` by Disassembling your Binary

One would be to `hexdump` your main function. For example:

        void main() {
          hexdump(main, 32); // Print out 32 bytes of instruction encodings of the main function
        }

Output:

        004011b4   55 48 89 e5 be 20 00 00 00 48 8d 3d f0 ff ff ff 
        004011c4   e8 6d ff ff ff b8 00 00 00 00 5d c3 f3 0f 1e fa

Apparently the `main` function starts at address `0x4011b4` in memory, and the first byte is `0x55`. We can check to see if this output is correct by disassembling our binary and checking to see what address `main` lives at and what the instruction encodings are:

        [neil@archvm ~]$ objdump -D hexdump

        00000000004011b4 <main>:
          4011b4:       55                      push   %rbp
          4011b5:       48 89 e5                mov    %rsp,%rbp
          4011b8:       be 20 00 00 00          mov    $0x20,%esi
          4011bd:       48 8d 3d f0 ff ff ff    lea    -0x10(%rip),%rdi        # 4011b4 <main>
          4011c4:       e8 6d ff ff ff          callq  401136 <hexdump>
          4011c9:       b8 00 00 00 00          mov    $0x0,%eax
          4011ce:       5d                      pop    %rbp
          4011cf:       c3                      retq

In the disassembly output, the first column is the address (starting with `4011b4`), the second column is the hex representation of the instruction encoding (`55`) and the third column is the human-readable assembly instruction (`push %rbp`). If you read the instruction encodings off sequentially, you can see that they are the same as the `hexdump` printout.

#### Testing `hexdump` by Printing the Contents of an Array

        char dummy_buffer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        void main() {
          hexdump(dummy_buffer, 32);
        }

Output:

        00404040   00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 
        00404050   10 11 12 13 14 00 00 00 00 00 00 00 00 00 00 00

