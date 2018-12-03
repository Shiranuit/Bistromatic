## Bistromatic
An expression evaluator that can compute Big Integers

### Computer Limit
Every Computer has some built-in computation limit
- 16 bits integers limit `65536`
- 32 bits integers limit `4294967296`
- 64 bits integers limit `18446744073709551616`
- and so on ...

### Goal
- The goal of this project was to make a calculator that can compute Infinite Integers

### More Realistic Goal
- In reality the notion of infinity does not realy exist when you're working with computers, 
you're just computing bigger and bigger numbers.
Actualy with this program you can't compute integers with more than `2147483647` digits
- The goal now would be to extend this limitation

### Usage
- Usage: `echo <mathematical_expression> | ./calc <base_characters> <operators_symbols> <expression_length>

### Examples
- Base 2: `echo "10+1" | ./calc "01" "()+-*/%" 3`
- Base 8: `echo "7+2" | ./calc "01234567" "()+-*/%" 3`
- Base 10: `echo "3+3" | ./calc "0123456789" "()+-*/%" 3`
- Base 16: `echo "A+B" | ./calc "0123456789ABCDEF" "()+-*/%" 3`
