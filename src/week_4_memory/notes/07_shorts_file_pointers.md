# File pointers

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

The ability to read data from and write data to files is the primary means of storing `persistent data`, data that does
not disappear when your program stops running.

The abstraction of files that C provides is implemented in a data structure known as a `FILE`.
- Almost universally when working with files, we will be using pointers to them, `FILE*`.

The file manipulation functions all live in `stdio.h`.
- All of them accept `FILE*` as one of their parameters, except for the function `fopen()`, which is used to get
a file pointer in the first place.

Some of the most common file input/output (I/O) functions that we’ll be working with are:
1. `fopen()`
2. `fclose()`
3. `fgetc()`
4. `fputc()`
5. `fread()`
6. `fwrite()`

---

## 1. `fopen()`
- Opens a file and returns a file pointer to it;
- Always check the return value to make sure you don’t get back `NULL`.

[Operations](https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-fopen-open-file):
- `"r"` - Open a text file for reading (The file must exist).
- `"w"` - Open a text file for writing. If the `w` mode is specified for a `ddname` that has `DISP=MOD`, the behavior
is the same as if a had been specified. Otherwise, if the file already exists, its **_contents are destroyed_**.
- `"a"` - Open a text file in append mode for **_writing at the end_** of the file. `fopen()` creates the file if it does
not exist.

```c++
// Template
FILE* ptr = fopen(<filename>, <operation>);

// Example
FILE* ptr1 = fopen("file1.txt", "r");
    // Opens file "file1.txt" to read
```

---

## 2. `fclose()`

- Closes the file pointed to by the given file pointer.

```c++
// Template
fclose(<file pointer>);

// Example
FILE* ptr1 = fopen("file1.txt", "r"); // opens a file

fclose(ptr1); // you need to close `ptr1` not "file1.txt"
```

---

## 3. `fgetc()`

_"file get a character"_

- Reads and returns the next character from the file pointed to. 
> - _Note:_ The operation of the file pointer passed in as a parameter must be `“r”` for read, or you will suffer an error.
> - So you might need to create separate file variables for reading and writing the same file.

```c++
// Template
char ch = fgetc(<file pointer>);

// Example
FILE* ptr1 = fopen("file1.txt", "r");

char ch = fgetc(ptr1);
```

The ability to get single characters from files, if wrapped in a loop, means we could read all the characters
from a file and print them to the screen, one-by-one, essentially.

```c++
char ch;

while((ch = fgetc(ptr)) != EOF)
    printf("%c", ch);
```

We might put this in a file called `cat.c`, after the Linux command “cat” which essentially does just this.

- `(ch = fgetc(ptr)` - obtaining one character from the file
- `!= EOF` - then we compare that character with a special value `EOF` or "end-of-file" (a condition in a computer operating system
where no more data can be read from a data source).
- In conclusion, `while((ch = fgetc(ptr)) != EOF)` means `while` this is not the end of a file `printf()`.

---

## 4. `fputc()`

_"file put a character"_

- Writes or appends the specified character to the pointed-to file.
> - _Note:_ The operation of the file pointer passed in as a parameter must be `“w”` for write or `“a”` for append,
> or you will suffer an error.

```c++
// Template
fputc(<character>, <file pointer>);

// Example
FILE* ptr2 = fopen("file2.txt", "w");
fputc('A', ptr2); // puts char 'A' into file file2.txt
```

Now we can read characters from files and write characters to them. Let’s extend our previous example to copy one file
to another, instead of printing to the screen.

```c++
FILE* ptr2 = fopen("file2.txt", "w");

char ch;
while((ch = fgetc(ptr)) != EOF)
    fputc(ch, ptr2); // reading from ptr's file putting to ptrs2's file
```

We might put this in a file called `cp.c`, after the Linux command cp which essentially does just this.

---

## 5. `fread()`

- Reads `<qty>` units of size `<size>` from the file pointed to and stores them in memory in a buffer (usually an array)
pointed to by `buffer`.

For example, we can read a file and then store the size of a file into array.

> - _Note:_ The operation of the file pointer passed in as a parameter must be `“r”` for read, or you will suffer
> an error.

```c++
// Template
fread(<buffer>, <size>, <qty>, <file pointer>);
// `<buffer>` - a pointer to the location where we are going to store info
// `<size>` - how large each unit of info will be
// `<qty>` - how many units of info
// `<file pointer>` - from which file we want to get them

//----------------------------------
// Examples
FILE* ptr = fopen("file1.txt", "r");


// Static memory allocation
//
// Assume that we declare an array of integers
int arr[10];
//
// Reads the size of `n * sizeof(int)` ~ `10 * 4 bytes` --> 40 bytes.
fread(arr, sizeof(int), 10, ptr);
// `arr` - passing a pointer in this case


// Dynamic memory allocation
//
// Another example for `Heap`
double* arr2 = malloc(sizeof(double) * 80); // 640 bytes 
fread(arr2, sizeof(double), 80, ptr);

// Example like in `fgetc()`
char c;
fread(&c, sizeof(char), 1, ptr); // gets one character from a file
// pointed to by a <buffer> ~ `&c` - we need to use an address of `c`
```

---

## 6. `fwrite()`

- Writes `<qty>` units of size `<size>` to the file pointed to by reading them from a buffer (usually an array)
pointed to by `<buffer>`.

> Note: The operation of the file pointer passed in as a parameter must be `“w”` for write or `“a”` for append,
> or you will suffer an error.

```c++
// Template
fwrite(<buffer>, <size>, <qty>, <file pointer>);
// Like at `fread()` but reverse and for writing purposes
// <buffer> to the <file>

// Examples

// Static
int arr[10];
fwrite(arr, sizeof(int), 10, ptr);

// Dynamic
double* arr2 = malloc(sizeof(double) * 80);
fwrite(arr2, sizeof(double), 80, ptr);

// Chars
char c;
fwrite(&c, sizeof(char), 1, ptr);
```

---

## Other I/O functions

Lots of other useful functions abound in `stdio.h` for you to work with:

- `fgets()` - reads a full string from a file _(like `fgetc()` but for a string)_.
- `fputs()` - writes a full string to a file _(like `fputc()` but for a string)_.
- `fprintf()` - writes a formatted string to a file.
- `fseek()` - allows you to rewind or fast-forward within a file.
- `ftell()` - tells you at what (byte) position you are at within a file.
- `feof()` - tells you whether you’ve read to the end of a file.
- `ferror()` - indicates whether an error has occurred in working with a file.