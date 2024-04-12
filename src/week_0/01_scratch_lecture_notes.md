# Week 0: Scratch
Computer programming is about taking some input and creating some output, thus solving problem.  
input -> ▢ <- output

---
## Numeral systems
### Unary system
The simplest numeral system to represent natural numbers.
### Binary system
Computers speak only 0's and 1's in binary system.
Single bit = 0 or 1 (binary digit).

Imagine two light bulbs, one light bulb can only count from 0 to 1, where 0 = off and 1 = on.  
00 = 0 in unary and binary  
01 = 1 in unary and binary  
10 = 2 in binary / 1 in unary  
11 = 3 in binary / 2 in unary  
Number 4 needs third light bulb:  
100 = 4 in binary  
101 = 5  
110 = 6  
111 = 7  

### Decimal system
Uses 'base-10' system: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9. Dec = 10  
In decimal system each of the digits is in a different column.

Imagine number 123:
- '3' - Rightmost digit is the ones place or the ones column.
- '2' - The tens place or the tens column.
- '1' - The hundreds place.
123 = (100 * 1) + (10 * 2) + (1 * 3)

### Back to binary system

Binary system use 'base-2' to count:

| 2^2         | 2^1        | 2^0        |
|-------------|------------|------------|
| 4           | 2          | 1          |
| Fours place | Twos place | Ones place |

That's why in binary 100 = 4, 101 = 5, 110 = 6 and so on.  
Four number 8 you need to add one more bit 1000 = 8.  

1 byte = 8 bits  
Like this:  
00000000 = 0  
11111111 = 255  

| 2^7          | 2^6        | 2^5        | 2^4         | 2^3          | 2^2         | 2^1        | 2^0        |
|--------------|------------|------------|-------------|--------------|-------------|------------|------------|
| 128          | 64         | 32         | 16          | 8            | 4           | 2          | 1          |
| 128'th place | 64's place | 32's place | 16'th place | Eights place | Fours place | Twos place | Ones place |

Actually, there is 256 bytes, but we start at 0.

---
## ASCII

A = 65 = 01000001

| 2^7          | 2^6        | 2^5        | 2^4         | 2^3          | 2^2         | 2^1        | 2^0        |
|--------------|------------|------------|-------------|--------------|-------------|------------|------------|
| 128'th place | 64's place | 32's place | 16'th place | Eights place | Fours place | Twos place | Ones place |
| 0            | 1          | 0          | 0           | 0            | 0           | 0          | 1          |
| = 0          | = 64       | = 0        | = 0         | = 0          | = 0         | = 0        | = 1        |

American Standard Code for Information Interchange - ASCII / [Wiki](https://en.wikipedia.org/wiki/ASCII)

8 bytes = 255 symbols

<img src="img/cs50Week0Slide93.png" alt="cs50Week0Slide93" height="395">

|         | 01001000 | 01001001 | 00100001 |
|---------|----------|----------|----------|
| Decimal | 72       | 73       | 33       |
| Symbol  | H        | I        | !        |

|         | 01000010 | 01001111 | 01010111 |
|---------|----------|----------|----------|
| Decimal | 66       | 79       | 87       |
| Symbol  | B        | O        | W        |

---
## Unicode
A text encoding standard / [Wiki](https://en.wikipedia.org/wiki/Unicode).  
Nowadays, everyone using Unicode instead of ASCII.  
May use 8 bits (1 byte), 16 bits (2 bytes), or 24 bits (3 bytes), or even 32 bits (4 bytes) per character.  
Unicode roughly represents 4 000 000 000 possible characters.  
The mission is to represent and to preserve all human languages digitally (past, present and future).

Emoji / [Wiki](https://en.wikipedia.org/wiki/Emoji)  
11110000100111111001100010000010 = 4036991106 = U+1F602 = 😂 = "face with tears of joy"

U+1F602 - Unicode code point that uses 'base-16' or hexadecimal.  
'U+' have no mathematical significance, just a visual clue.

👍 = U+1F44D  
👍🏻 = U+1F44D U+1F3FD for another skin tone

💑 = U+1F491 but if we want to change gender, look or heart representation:

|               |        |        |        |        |                |
|---------------|--------|--------|--------|--------|----------------|
| U+1F469       | U+200D | U+2764 | U+FE0F | U+200D | U+1F468        |
| Woman at left |        | Heart  | Heart  |        | Man at right   |
| U+1F469       | U+200D | U+2764 | U+FE0F | U+200D | U+1F469        |
| Woman at left |        | Heart  | Heart  |        | Woman at right |

U+200D - Zero Width Joiner (ZWJ) for connecting elements

Computer scientists faced a challenge when wanting to assign various skin tones to each emoji to allow the communication to be further personalized. In this case, the creators and contributors of emoji decided that the initial bits would be the structure of the emoji itself, followed by skin tone.

---
## RGB
How computer represent colors:
Red + Green + Blue = from 0 to 255
Every pixel has a three numbers (1 byte = 8 bits) associated with it.

72 73 33 = some kind of yellow