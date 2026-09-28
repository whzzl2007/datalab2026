/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(~x&~y)&~(x&y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    return (!((!x)^(!y)))&&(!((x>>31)^(y>>31)));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int b16=((v>>16)>0)<<4;
    v>>=b16;
    int b8=((v>>8)>0)<<3;
    v>>=b8;
    int b4=((v>>4)>0)<<2;
    v>>=b4;
    int b2=((v>>2)>0)<<1;
    v>>=b2;
    int b1=((v>>1)>0);
    v>>=b1;
    return b16|b8|b4|b2|b1;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int N=n<<3;
    int M=m<<3;
    int i=0xFF&(x>>N);
    int j=0xFF&(x>>M);
    int a=j<<N;
    int b=i<<M;
    return (((x&~(0xFF<<N))|a)&~(0xFF<<M))|b;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    int i=16;
    while(i){
        int a=i+15;
        int b=16-i;
        unsigned t=0x1;
        unsigned k=(t&(v>>a))<<b;
        unsigned l=(t&(v>>b))<<a;
        v=((v&(~(t<<b))|k)&~(t<<a))|l;
        i--;
    }
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    /*int v=x;
    int b16=(!(v>>16))<<4;
    v<<=b16;
    int b8=(!(v&0xff000000))<<3;
    v<<=b8;
    int b4=(!(v&0xf0000000))<<2;
    v<<=b4;
    int b2=(!(v&0xc0000000))<<1;
    v<<=b2;
    int b1=(!(v&0x80000000));
    v<<=b1;
    x=v;*/
    int t=x;
    int a16=!(~(0xffff|t))<<4;
    t<<=a16;
    int a8=!(~(0xffffff|t))<<3;
    t<<=a8;
    int a4=!(~(0xfffffff|t))<<2;
    t<<=a4;
    int a2=!(~(0x3fffffff|t))<<1;
    t<<=a2;
    int a1=!(~(0x7fffffff|t));
    t<<=a1;
    int a0=!(~(0x7fffffff|t));
    return (a16+a8+a4+a2+a1+a0);
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned c = (x >> 31) & 0x1;      
    unsigned ux = x;
    if (x == 0)
        return 0;
    if (c)
        ux = ~ux + 1;                  
    int count = 0;
    int t = 0;
    while (!t) {
        count = count + 1;            
        t = 0x1 & (ux >> (32 - count));
    }
    int E = 32 - count + 127;         
    unsigned M;
    if (count == 32)                   
        M = 0;
    else
        M = ux << count;              
    unsigned m = M >> 9;              

    if (M & 0x100) {                   
        if (M & 0xFF)                  
            m = m + 1;
        else if (m & 0x1)            
            m = m + 1;
    }
    if (m == 0x800000) {             
        m = 0;
        E = E + 1;
    }
    return (c << 31) | (E << 23) | m;
}
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xFF) return uf;
    if (exp == 0) {
        if (frac == 0) return uf;               
        if (frac & 0x400000) {                  
            return (uf & 0x80000000) | 0x00800000 | ((frac << 1) & 0x7FFFFF);
        } else {
            return (uf & 0x80000000) | (frac << 1);
        }
    }
    if (exp == 0xFE) {
        return (uf & 0x80000000) | 0x7F800000;
    }
    return uf + 0x00800000;
}


/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;               
    unsigned exp = (uf2 >> 20) & 0x7FF;      
    unsigned fh = uf2 & 0xFFFFF;             
    unsigned fl = uf1;                       
    int E;
    unsigned result;

    if (!(exp - 0x7FF)) {
        return 0x80000000;
    }

    if (!exp) {
        return 0;
    }

    E = exp - 1023;                          

    if (E < 0) {
        return 0;
    }
    if (E >= 31) {
        return 0x80000000;
    }

    if (E <= 20) {
        result = (1 << E) + (fh >> (20 - E));
    } else {
        result = (1 << E) + (fh << (E - 20)) + (fl >> (52 - E));
    }
    if (sign) {
        return ~result + 1;
    }
    return result;
}


/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x > 127) return 0x7F800000;
    if (x < -149) return 0;
    if (x >= -126) {
        return (x + 127) << 23;
    }
    return 1 << (x + 149);
}