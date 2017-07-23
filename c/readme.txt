The C Languagei :
	C Program Compilation
	Execution Process
	Tokens of C Program
	C Instructions
	Constants, Variables
	Identifiers and Keywords
	Primitive Data Types
	Structures – The Definition
	Structures – Declaration & Type
	Accessing Elements of Structure
	Range of Signed/Unsigned Data-types
	Efficient way of Printing Pointer
	Compiler Memory Allocation for Data-types
	Compiler Memory Allocation for Structures
	Data-type Alignments
	Compiler Memory Allocation for Unions
	Union – Data Corruption
	Practical Usage of Unions
	Practical Usage of Bitfields
	Bitfields Overflow
	Printing every byte of an Integer
	Enumeration
	Typedef Statements
	Practical example of Typedef Usage
	typedef’ing a Function Pointer
	Bit-Fields in Structure
	Practical examples of Bitfield Usage
	Structure Padding & Pitfalls
	Programming Model & Memory Sizes
	Why Sizeof Int and Long is 4 or 8?
	Use of long long in 32-bit Architecture
	Practical Example of long long
	IA-32, IA-64, ILP-32, LP64, x86-64
	Array – Representation
	Array – Memory Allocation
	Array – Declaration & Initialization
	Two Dimensional Arrays

	Pointers
	Accessing a Variable Through Pointer
	Pointer – Memory Allocation
	Pointer – Declaration & Initialization
	Pointer – Dereferencing
	Pointers & Arrays
	Character Arrays using Pointers
	Array of Character Pointers
	Memory Diagram – Array of Char Pointers
	Arrays as Pointers – a[i] == i[a]?
	Constant Pointers
	Pointer Arithmetic
	String Handling Functions
	String Conversion Functions
	Efficient usage of sscanf()/sprintf()

	Computing Basic
	Binary & Octal Systems
	Decimal & Hexadecimal Systems
	Signed Representations in Memory
	Binary Shifts – Right & Left
	Sign Bits and Bit-Shift Operations
	Right Shift – Logical Vs Arithmetic Shift
	Bit-Shift Overflow
	ASCII Representations
	Endian-ness – Little Vs Big
	Endian-ness – Portability Issues
	Operators
	Bitwise Operations
	Logical Operators – Short Circuit
	Bitwise Vs Logical Operations
	sizeof() operator
	Pitfalls/Issues with sizeof() usage
	Pointer Increment & Scaling
	Operator Precedence
	Operator Associativity
	True meaning of Associativity
	Examples of Precedence & Associativity
	Ternary Operator Associativity Rule
	Data-type Conversion Rules
	Float to Int to Float Conversions
	Variadic functions & default promotion rules
	Printf Idiosynchracies
	Pointer Format Specifiers
	Signed Vs Unsigned – Pitfalls
	Evaluation of i = ++i + ++i
	Evaluation of i = ++i + ++i + ++i
	Concept of Sequence Points
	Example of Sequence Points
	
	Storage Classes
	Storage Class Specifiers
	Scope of a Variable
	Register, Auto, Static, Extern
	Why Register Class and Practical Examples
	Automatic Variables and Stack
	Static Variables and Functions
	True meaning of Extern
	How to Use extern across Multiple Files with Examples
	Best Practices for Extern Usage
	Local/Block/Global Scope
	Nesting of Scope
	Lifetime of a Variable
	Linkage of a Variable
	What is Const?
	Practical Examples of Const Qualifier
	Usage of Constant in library functions (libc)
	What is Volatile?
	Practical Examples of Volatile Qualifier
	Const Volatile Together?
	Register Vs Volatile Performance?
	Practical Examples of Const Volatile
	Pointer Aliasing
	What is Restrict Qualifier?
	Restrict Keyword and Compiler Optimization
	Examples of Restrict Qualifier
	

	Memory
	Dynamic Memory Allocations
	malloc, calloc, realloc, free
	malloc Vs calloc
	Heap Memory
	Stack Memory – Pitfalls
	Dangling Pointers
	DMA – Errors
	Best Practices for malloc() & free()
	DMA – Unspecified Behaviour

	Functions & Pointers
	Invoking Functions
	Passing Arguments to Functions
	Call by Value & Reference
	Is C call by Value?
	Is C call by Reference?
	Array as Function Argument
	Rules for Array Argument Passing
	Multi-dimensional Array Argument Passing
	Structure as Function Argument
	Static Vs Dynamic Runtime Environment
	Function Call and Runtime Stack
	Rules for Evaluation of Function Arguments
	Memory Organization
	Code Segment
	Data Segment
	Heap Segment
	Stack Segment
	free space
	register space
	Stack Frames
	Calling Sequence
	View of Runtime Stack with Example
	Access to Local Variable in Stack
	Local Temporaries
	Function Pointers
	Declaration and Usage of Function Pointers
	Function Pointers as Function Parameters
	Practical Example of Function Pointers
	Pointer to an Integer Array
	C Pointers Complexity Chart
	int **p
	int (*p)()
	int (*p)[] int *p()
	int *(*p[])()
	int *(**p)[]

	Preprocessor
	Preprocessor – #include statements
	Multiple Inclusion of a Header File?
	Preprocessor – #define statements
	Preprocessor – Conditional Compilation
	Preprocessor – Nested Macros
	Preprocessor – Multiline Macros
	Preprocessor – Stringizer
	Preprocessor – Token Concatenation
	Preprocessor – Useful Directives
	Conditional Directives for Debugging
	Where Macros are Heavily Used
	Practical Examples of Macros
	Macros Pitfalls
	Macros Vs Enums
	Inline Functions
	Macros Vs Inline
	Inline Recursive Functions

	Command Line Argument
	Environment Variables in C Programs
	Recursion Example
	Recursion Vs Iteration
	Code/Space/Time Complexity

	Standard I/O Library
	Files & Streams
	Streams Buffers
	IO Buffers – Line Vs Full Vs No-Buffers
	Setting & Flushing Buffers
	File Access
	File Access Modes
	Sequential Vs Random Access
	Concept of File Offsets
	File Operation Errors
	End-of-File Condition?
	Return Values and Error Values
	Character Based File I/O
	Line Based File I/O
	Formatted File I/O
	Block File I/O
	Dangerous – gets() Vs fgets()
	File Random Access Methods 
 
debugging:


    C program to Process
    Compilation Steps
    Preprocessor
    Compiler
    Assembler
    Linker / Loader
    GCC options
    Fixing Warnings in the Code
    Include Files
    Libraries
    Static Vs Dynamic Library
    Static Library Generation
    Dynamic Library Generation
    Linking with Libraries
    File Formats
    ELF Format
    Symbol Tables
    Anatomy of a Process
    Process Map
    Memory Layout
    Code Segment
    Data Segment
    Stack Segment
    Heap Segment
    Object Dump
    Stack Frames
    Mapping Assembly to C
    Managing Heap
    Pmap / Pstack
    Strace
    Debugging Tools
    GDB Debugger
    Debugging Running Process
    Core dump analysis
    Symbols & Optimizations
    Default Optimization Levels
    Common Failures
    Failure Notifications
    Common Faults
    Segmentation Violation
    Stack Overflow
    Heap Overflow
    Arithmetic Overflow
    Illegal code execution
    Stack Issue
    Endian-ness issue
    C library assertion
    Data Type mismatch


C PROGRAMMING INTERVIEW QUESTIONS AND ANSWER

C programming interview questions and answer for freshers

(1) If static storage in c will not work then what problem will you face?
(2) If extern storage in c will not work then what problem will you face?
(3) Why we cannot initialize extern variables?
(4) What is trigraph in C?
(5) Why char data type can store two characters at a time?
(6) What is prototype of printf function?
Answer
(7) As we know any program which is possible using loop is also possible using function recursion. Then why loop in C?
(8) Add any two numbers without using addition operator.
(9) Subtract any two numbers without using subtraction operator?
(10) Declare and define a structure at the same time?
(11) What is self referential structure?
(12) What is difference between declaration and definition?
(13) Write a c program to print hello world without using any semi colon.
(14) What is difference between following two declarations?
1. char * a, b;
2. #define char * string
string a, b;
(15) Write a sacnf statement which can store a sentence which includes blank space to a variable.
(16) What is array of function?
(17) Write a function in c which executes before the main function?
(18) Write a function in c which executes after the main function?
(19) What is FILE pointer?
Answer
(20) What is far pointer in c?
(21) What is normalization in C?
(22) How does preprocessor work?
(23) Why typedef is storage class?
(24) If auto storage in c will not work then what problem will you face?
(25) Does printf function follow function overloading in c?
(26) What is command line argument?
(27) What is cyclic nature of data type?
(28) Can you modify const. variable by program? If yes then how?
(29) How integer data stores in memory?
(30) What is generic pointer?
(31) What is NULL pointer?
(32) What is dangling pointer?
(33) What is huge pointer?
(34) In which data type we cannot use storage class and why?
(35) What is use of void pointer?
(36) What is difference between malloc and calloc function in c?
(37) What is difference between c and c++?
(38) What are global structures and unions?
(39) What is difference between structure and union?
(40) What is use of structure?
(41) What is use of union?
(42) What is variable number argument in C?
(43) What is ellipsis in C?
Answer
(44) How can you check particular bit is on or off?
(45) What is function recursion?
(46) What is nesting of function call?
(47) What is pointer?
(48) What is array in C?
(49) What is array of array?
(50) What is code and data area of memory?
(51) Find the size of data type without using sizeof operator?
(52) Compare two strings without using any string library function?
(53) What is necessity of declaration of a function?
(54) Write a printf statement without using any semi colon.
(55) What is array of pointer?
(56) What is array of function?
(57) What is array of structure?
(58) What is difference between pass by value and pass by reference?
(59) What is use of stack?
(60) What is use of void?
(61) What are Lvalue and Rvalue of data type?
(62) What is volatile qualifier in C?
(63) Write a c program to add two matrixes?
(64) Write a c program to multiple two matrixes?
(65) Write a c program to print diagonal element of a matrix?
(66) In which area of memory static variables store?
(67) What is heap area of memory?
(68)What are global identifiers in C?
(69) How can you assign an octal number to a variable in C?
(70) How can you assign a hexadecimal number to a variable in C?
(71) How to create own library function in C?
(72) What are enumerators in C?
(73) What is wild pointer?
(74) What is FILE pointer?
(75) What is far pointer?
(76) What is near pointer?
(77) What is difference between array and link list?
(78) What is difference between array of character and string?
(79) How can you open a file in C?
(80) How can you write in a file in C?
(81) How can you calculate size of union?
(82) How can you calculate size of a function?
(83) How can you calculate size of structure?
(84) How will initialize the member of union?
(85) Why we can initialize only first member of union?
(86) Which storage call is not allowed with structure?
(87) What is difference between structure and array?
(88) What is self referential structure?
(89) What is slack byte in structure?
(90) Why we cannot compare two same type of structure?
(91) What is alignment of structure member variables?
(92) How can you rename a structure?
(93) How can you rename a union?
(94) How can you rename a function?
(95) How can you rename an array?
(96) What is use of typdef keyword?
(97) How can you access the member of structure variables?
(98) How can you access the member of union variables?
(99) How bit level programming is possible using structure or union?
(100) what is nested structure?


1. What is wild pointer?
2. What is dangling pointer problem?
3. What is generic pointer?
4. What is NULL pointer?
5. What is far pointer?
6. What is huge pointer?
7. What are demerits of pointers?
8. Give an example of pointer to function.
9. What is array of pointer?
10. Array name is constant pointer. Is it true?

Do you memory representation of float data type in c?

 Structure questions with explanation in c

Structure in c example

(q) What will be output of following c code?

void main()
{
struct employee
{
unsigned id: 8;
unsigned sex:1;
unsigned age:7;
};
struct employee emp1={203,1,23};
clrscr();
printf("%d\t%d\t%d",emp1.id,emp1.sex,emp1.age);
getch();
}

Output: 203 1 23
We can access the data member in same way.
How bit data is stored in the memory:

Minimum size of structure which data member in bit is two byte i.e. 16 bit. This is called word size of microprocessor. Word size depends on microprocessor. Turbo c is based on 8086 microprocessor which word size is two byte.


Bits are filed in from right to left direction 8 bit for id,1 bit for sex and 7 bit for age.

(q) What will be output of following c code?

void main()
{
	struct bitfield
	{
	unsigned a:5;
	unsigned c:5;
	unsigned b:6;

	}bit;
	char *p;
	struct bitfield *ptr,bit1={1,3,3};
	p=&bit1;
	p++;
	clrscr();
	printf("%d",*p);
	getch();
}

Output: 12
Explanation:
Binary value of a=1 is 00001 (in 5 bit)
Binary value of b=3 is 00011 (in 5 bit)
Binary value of c=3 is 000011 (in 6 bit)
In memory it is represented as:


Let address of bit1 is 500 which initialize to char pointer p. Since can is one byte data type so p++ will be 501. *p means content of memory location 501 which is (00001100) and its binary equivalent is 12. Hence output is 12.

(q) What will be output of following c code?

void main()
{
	struct bitfield
	{
	signed int a:3;
	unsigned int b:13;
	unsigned int c:1;
	};
	struct bitfield bit1={2,14,1};
	clrscr();
	printf("%d",sizeof(bit1));
	getch();
}

Output: 4
(q) What will be output of following c code?

void main()
{
	struct bitfield
	{
	unsigned a:3;
	char b;
	unsigned c:5;
	int d;
	}bit;
	clrscr();
	printf("%d",sizeof(bit));
	getch();
}

Output: 5

Note: (Actual output will 6 due to slack byte ,So Before executing this program first go to option menu then compiler then code generation then select word alignment then press OK)

(q) What will be output of following c code?
void main()
{
	struct field
	{
	int a;
	char b;
	}bit;
	struct field bit1={5,'A'};
	char *p=&bit1;
	*p=45;
	clrscr();
	printf("\n%d",bit1.a);
	getch();
}

Output: 45
Nesting of structure:

Nesting of structure is possible i.e. we can declare a structure within another structure but it is necessary inner structure must declares structure variable otherwise we can not access the data member of inner structure.
Example:

void main()
{
	struct world
	{
		int a;
		char b;
		struct india
		{
			char c;
			float d;
		}p;
	};
	struct world st ={1,'A','i',1.8};
	clrscr();
	printf("%d\t%c\t%c\t%f",st.a,st.b,st.p.c,st.p.d);
	getch();
}

Output: 1 A I 1.800000

(q) What will be output of following c code?

void main()
{
	struct india
	{
	char c;
	float d;
	};
	struct world
	{
		int a[3];
		char b;
		struct india orissa;
	};
	struct world st ={{1,2,3},'P','q',1.4};
	clrscr();
	printf("%d\t%c\t%c\t%f",st.a[1],st.b,st.orissa.c,st.orissa.d);
	getch();
}

C string questions and answers with explanation

 What will be output when you will execute following c code?

#include<stdio.h>
void main(){
    char arr[7]="Network";
    printf("%s",arr);
}

i C program examples | Interview Complete List

It is C programming FAQ code examples to Crack Interview. It has C language basic and simple source code by examples. It has arranged just like c tutorials with examples. This post contains a big collection of examples of c program. If you have any doubt in the following c program examples you are free to ask.



Frequently asked c programs in interview

1. Write a c program to check given number is perfect number or not.
2. Write a c program to check given number is Armstrong number or not.
3. Write a c program to check given number is prime number or not.
4. Write a c program to check given number is strong number or not.
5. C program to check a number is odd or even.
6. Write a c program to check given number is palindrome number or not.
8. Write a c program to check given string is palindrome number or not.
7. Write a c program to solve quadratic equation.
8.  Write a c program to print Fibonacci series of given range.
9. Write a c program to get factorial of given number.
10. Write a c program for Floyd’s triangle.
11. Write a c program to print Pascal triangle.
12. Write a c program to generate multiplication table.
13. Write a c program to print ASCII value of all characters.
14. C program to print hello world without using semicolon
15. Write a c program which produces its own source code as its output

C program with numbers

1. Write a c program to reverse any number.
2. Write a c program to find out sum of digit of given number.
3. Write a c program to find out power of number.          
4. Write a c program to add two numbers without using addition operator.
5. Write a c program to subtract two numbers without using subtraction operator.
6. Write a c program to find largest among three numbers using binary minus operator.
 7. Write a c program to find largest among three numbers using conditional operator
8. Write a c program to find out generic root of any number.
9. Write a c program to find out prime factor of given number.
10. Write a c program to find out NCR factor of given number.
11. How to convert string to int without using library functions in c
12. Program in c to print 1 to 100 without using loop
13. C program for swapping of two numbers
14. Program to find largest of n numbers in c
15. Split number into digits in c programming
16. C program to count number of digits in a number

Recursion

Example of recursion in c programming

L.C.M and H.C.F.

1.  Write a c program to find out L.C.M. of two numbers.
2. Write a c program to find out H.C.F. of two numbers.
3. Write a c program to find out G.C.D. of two numbers.

Swapping

1. Write a c program to swap two numbers.
2. Write a c program to swap two numbers without using third variable.
3. Write a c program for swapping of two arrays.
4. Write a c program for swapping of two string.

Conversion ( Number System )

1. Write a c program to convert decimal number to binary number.
2. Write a c program to convert decimal number to octal number.
3. Write a c program to convert decimal number to  hexadecimal number.
4. Write a c program to convert octal number to binary number.
5. Write a c program to convert octal number to decimal number.
6. Write a c program to convert octal number to hexadecimal number.
7. Write a c program to convert hexadecimal number to binary number.
8. Write a c program to convert hexadecimal number to octal number.
9. Write a c program to convert hexadecimal number to decimal number.
10. Write a c program to convert binary number to octal number.
11. Write a c program to convert binary number to decimal number.
12. Write a c program to convert binary number to hexadecimal number.
13. C program for addition of binary numbers . 
14. C program for multiplication of two binary numbers.
15. C program fractional binary conversion from decimal.
16. C program for fractional decimal to binary fraction conversion.
17. C program to convert decimal number to roman.
18. C program to convert roman number to decimal number.
19. C program to convert each digits of a number in words
20. C program to convert currency or number in word.

Conversion ( Unit )

1. C program for unit conversion.

String

1. Write a c program to convert the string from upper case to lower case.
2. Write a c program to convert the string from lower case to upper case.
3. Write a c program to delete the all consonants from given string.
4. Write a c program to count the different types of characters in given string.
5.  Write a c program to sort the characters of a string.
6. Write a c program for concatenation two strings without using string.h header file.
7. Write a c program to find the length of a string using pointer.  
8. Write a c program which prints initial of any name.
9. Write a c program to print the string from given character.
10. Write a c program to reverse a string
11. Reverse a string using recursion in c
12. String concatenation in c without using strcat
13. How to compare two strings in c without using strcmp
14. String copy without using strcpy in c
15. Convert a string to ASCII in c

Matrix

1. Write a c program for addition of two matrices.
2. Write a c program for subtraction of two matrices
3. Write a c program for multiplication of two matrices.
4. Write a c program to find out sum of diagonal element of a matrix.
5. Write a c program to find out transport of a matrix.
6. Write a c program for scalar multiplication of matrix.
7. C program to find inverse of a matrix
8. Lower triangular matrix in c
9. Upper triangular matrix in c
10. Strassen's matrix multiplication program in c
11. C program to find determinant of a matrix

File

1. Write a c program to open a file and write some text and close its.
2.  Write a c program to delete a file.
3. Write a c program to copy a file from one location to other location.
4. Write a c program to copy a data of file to other file.
5. Write a c program which display source code as a output.
6. Write a c program which writes string in the file.
7. Write a c program which reads string from file.
8. Write a c program which writes array in the file.
9. Write a c program which concatenate two file and write it third file.
10. Write a c program to find out size of any file.
11. Write a c program to know type of file.
12. Write a c program to know permission of any file.
13. Write a c program to know last date of modification of any file.
14. Write a c program to find size and drive of any file.

Complex number

1. Complex numbers program in c
2. Write a c program for addition and subtraction of two complex numbers.
3. Write a c program for multiplication of two complex numbers.
4. Write a c program for division two complex numbers.

Series

1. Write a c program to find out the sum of series 1 + 2 + ….  + n.
2. Write a c program to find out the sum of series 1^2 + 2^2 + …. + n^2.
3. Write a c program to find out the sum of series 1^3 + 2^3 + …. + n^3.
4. Write a c program to find out the sum of given A.P.
5. Write a c program to find out the sum of given G.P.
6. Write a c program to find out the sum of given H.P.
7. Write a c program to find out the sum of series 1 + 2 + 4 + 8 … to infinity.

Array

1. Write a c program to find out largest element of an array.
2. Write a c program to find out second largest element of an unsorted array.
3. Write a c program to find out second smallest element of an unsorted array.
4. Write a c program which deletes the duplicate element of an array.
5. Write a c program for delete an element at desired position in an array.
6. Write a c program for insert an element at desired position in an array.
7. C program to find largest and smallest number in an array

Sorting

1. Write a c program for bubble sort.
2. Write a c program for insertion sort.
3. Write a c program for selection sort.
4. Write a c program for quick sort.
5. Write a c program for heap sort.
6. Write a c program for merge sort.
7. Write a c program for shell sort.

Recursion

1. Write a c program to find factorial of a number using recursion.
2. Write a c program to find GCD of a two numbers using recursion.
3. Write a c program to find out sum digits of a number using recursion.
4. Write a c program to find power of a number using function recursion.
5. Write a c program to reverse any number using recursion.

Size of data type

1. Write a c program to find the size of int without using sizeof operator.
2. Write a c program to find the size of double without using sizeof operator.     
3. Write a c program to find the size of structure without using sizeof operator.
4. Write a c program to find the size of union without using sizeof operator.

Using pointer

1. Write a c program for concatenation two string using pointer.

Searching

1. Write a c program for linear search.
2. Write a c program for binary search.
3. Write a c program for binary search using recursion.

Area and volume

1. Write a c program to find the area of circle.
2. Write a c program to find the area of any triangle.
3. Write a c program to find the area of equilateral triangle.
4. Write a c program to find the area of right angled triangle.
5. Write a c program to find the area of rectangle.
6. Write a c program to find the area of trapezium.     
7. Write a c program to find the area of rhombus.   
8. Write a c program to find the area of parallelogram.           
9. Write a c program to find the volume and surface area of cube.
10. Write a c program to find the volume and surface area of cuboids.
11. Write a c program to find the volume and surface area of cylinder.
12. Write a c program to find the surface area and volume of a cone.
13. Write a c program to find the volume and surface area of sphere.
14. Write a c program to find the perimeter of a circle, rectangle and triangle.

C program with very large numbers

1. Write a c program to find factorial of 100 or very large numbers
2. Write a c program to multiply the two very large number (larger the long int)
3. Write a c program for division of large number (larger than long int)
4. C code for modular division of large number.
5. C code for division of large number.
6. C code for power of large numbers.

Other

1. C program for ATM transaction.

2. Write a c program which passes one dimension array to function.
3. Write a c program which passes two dimension array to function.
4. Write a c program which takes password from user.
5. Write a scanf function in c which accept sentence from user.
6. Write a scanf function in c which accept paragraph from user.
7. Write a c program to print the all prime numbers between 1 to 300.
8. Write a c program which passes structure to function.
9. Palindrome in c without using string function
10. How to get the ASCII value of a character in c
11. C program to get last two digits of year
12. C program without main function

