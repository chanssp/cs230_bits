/*
 * CS:APP Data Lab
 *
 * Chan Min Park / 20140854
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;
    
    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc. Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
 This file is part of the GNU C Library.
 
 The GNU C Library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 The GNU C Library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with the GNU C Library; if not, see
 <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
 include it implicitly at the start of every compilation.  It must
 not itself include <features.h> or any other header that includes
 <features.h> because the implicit include comes before any feature
 test macros that may be defined in a source file before it first
 explicitly includes a system header.  GCC knows the name of this
 header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
 and complex.  If the GCC (4.9 and later) predefined macros
 specifying compiler intent are available, use them to determine
 whether the overall intent is to support these features; otherwise,
 presume an older compiler has intent to support these features and
 define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
 Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    /*the following set of operations will calculate bitAnd */
    int input1 = ~x;
    int input2 = ~y;
    int calcOr = input1 | input2;
    return ~(calcOr);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /*implementation */
    int input = n << 3;
    int shift = x >> input;
    int out = shift & 0xff;
    return out;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    int deter = (0x01<<31) >> n; //used as determinant if number is negative or positive.
    int forand = ~(deter << 1);
    int out = (x >> n) & forand;
    return out;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int out;
    int for2byte = 0x11 | (0x11 << 8); //00000000 00000000 00010001 00010001
    int mask = for2byte | (for2byte << 16);  //00010001 00010001 00010001 00010001
    //this part calculates the number of 1s in every 4bits.
    int sum = x & mask;
    sum += ((x >> 1) & mask);
    sum += ((x >> 2) & mask);
    sum += ((x >> 3) & mask);
    //pushes 1s into first 2 bytes.
    sum += (sum >> 16);
    //pushes 1s into first byte.
    for2byte = 0xF | (0xF << 8);
    sum = (sum & for2byte) + ((sum >> 4) & for2byte);
    out = ((sum + (sum >> 8)) & 0x3F);
    return out;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    int opp = ~x;
    int deter = opp + 0x01; // determinant will make 0 if x is zero, or all bit 1 if else.
    int or = (x | deter) >> 31;
    int out = or + 0x01; //this alters 1111 to 0000, and 0000 to 1111.
    return out;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    int out = 0x1 << 31;
    return out;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int neg = ~n;
    int minus = 33 + neg; //this calculates 32 - n.
    int rem = (x << minus) >> minus; //makes change to x if n doesn't fit.
    int out = !(rem ^ x);
    return out;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int a = 0x01 << 31;
    int b = ((a & x) >> 31) & 0x01; //makes either 0 or 1.
    int deter = (b << n) + ((~b)+0x01); //this will be added if x <= 0.
    int out = (x + deter) >> n;
    return out;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    int opp = ~x;
    int out = opp + 0x01;
    return out;
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    int deter = 0x01 << 31;
    int and = x & deter; //checks if positive or negative.
    int iszero = and | (!x); //checks if zero or not.
    int out = !iszero;
    return out;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int negY = ~y; //negative of y.
    int xsign = x >> 31;
    int ysign = y >> 31; //sign bit of x and y.
    int sumShift = (x + negY) >> 31; //will be either -1 or 0.
    int deter = !(xsign ^ ysign); //1 if sign is equal, 0 if sign is different.
    int onezero = sumShift & deter; //1 if true and 0 if else, when sign is equal.
    int diff = xsign & !ysign;
    int out = onezero | diff;
    return out;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int out, total;
    //after the folding step, all bits below MSB will become 1.
    int fold1 = x | (x >> 1);
    int fold2 = fold1 | (fold1 >> 2);
    int fold3 = fold2 | (fold2 >> 4);
    int fold4 = fold3 | (fold3 >> 8);
    int fold5 = fold4 | (fold4 >> 16);
    //from here we use bitCount to count the number of 1s.
    //because this gives the position of MSB.
    int for2byte = 0x11 | (0x11 << 8);
    int mask = for2byte | (for2byte << 16);
    
    int sum = fold5 & mask;
    sum += ((fold5 >> 1) & mask);
    sum += ((fold5 >> 2) & mask);
    sum += ((fold5 >> 3) & mask);
    
    sum += (sum >> 16);
    
    for2byte = 0xF | (0xF << 8);
    sum = (sum & for2byte) + ((sum >> 4) & for2byte);
    total = ((sum + (sum >> 8)) & 0x3F);
    //the log2(x) is the positiion of the MSB - 1.
    out = total + (~0x00);
    return out;
}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    int out;
    unsigned minNaN = 0x7f800001; //this is minimum NaN as 0x7f800000 is inf.
    unsigned cond = uf & 0x7fffffff; //masks of the sign bit so easy to compare size.
    if (cond >= minNaN)
        return uf;
    else {
        out = (0x80000000) ^ uf;
        return out;
    }
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    int y,i,j,k,e,h,s,f; //420
    int mx = 0x01 << 31;
    int ffl, f22;
    int out;
    if (x == 0)
        return 0;
    
    if (x == mx)
        return (0xcf) << 24;
    
    ffl = (mx >> 8) - 0x01; //430
    j = 0;
    i = 0;
    s = x & mx;
    
    if (s)
        x = (~x + 0x01);
    y = x;
    
    while (y > 0) {
        y = y >> 0x01;
        i = i + 0x01;
    } //442
    if (i > 24) {
        int c = i - 24;
        f = (x >> c);
        k = 0x01 << c;
        h = k >> 0x01;
        k = k - 0x01;
        f22 = x & k;
        if ((f22) > h)
            j = 0x01;
        else if ((f22) == h) {
            if (f & 0x01)
                j = 0x01;
        }
    }
    else
        f = x << (24 - i);
    
    e = 126 + i;
    
    out = (s | (e << 23) | (f & ffl)) + j;
    return out;
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    int out;
    int msb = uf & 0x80000000;
    unsigned naninf = 0x7f800000;
    if ((uf & naninf) == naninf) //for NaNs and inf.
        return uf;
    else if ((uf & naninf) == 0x00) //for denormalized values.
        if ((uf & 0x007fffff) == 0x00) //when 0;
            return uf;
        else
            return (uf << 1) | msb;
        else { //everything else.
            out = uf + 0x800000;
            return out;
        }
}
