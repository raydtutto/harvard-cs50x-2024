# Week 7: SQL

Instructor: **[David J. Malan](https://github.com/dmalan)**

---

- This week, we will be continuing more syntax related to Python.
- Further, we will be integrating this knowledge with data.
- Finally, we will be discussing SQL or Structured Query Language.
- Overall, one of the goals of this course is to learn to program generally – not simply how to program in the languages described in this course.

---

Imagine a survey that questions you some topics. All the input that were given to this survey can often be described
in patterns of columns and rows.

> A simplest way to store a bunch of data is to save as `flat-file database`. 

**Spreadsheets** like those created in _Microsoft Excel_ and _Google Sheets_ can be outputted to a `csv`
or `Comma-Separated Values` file.

If you look at a `csv` file, you’ll notice that the file is flat in that all of our data is stored
in a single table represented by a text file. We call this form of data a `flat-file database`.

> Python comes with native support for csv files.

- First, download `favorites.csv` and upload it to your file explorer inside `cs50.dev`.

The `favorites.csv` will look like this:
- The first line is a `Header row`, which describes what each of those columns means.

```
Timestamp,language,problem
10/30/2023 13:38:01,Python,"Hello, World"
10/30/2023 13:38:03,Python,DNA
10/30/2023 13:38:03,Python,"Hello, World"
10/30/2023 13:38:05,Scratch,Scratch
10/30/2023 13:38:08,Python,Speller
10/30/2023 13:38:09,Python,"Hello, World"
10/30/2023 13:38:10,Python,Cash
10/30/2023 13:38:10,Python,Readability
and so on...
```

- Second, in your terminal window, type code favorites.py and write code as follows:

We could write code this way, more similar to C way:

```python
import csv

file = open("favorites.csv", "r")
# Do comething
close(file)
```

But let's write it in more `pythonic` way in `favorites_1.py`:
- `with` will close the opened file for you, when program will be out of this block of code;

```python
# Prints all favorites in CSV using csv.reader

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create reader
    reader = csv.reader(file)

    # Skip header row
    next(reader)

    # Iterate over CSV file, printing each favorite
    for row in reader:
        print(row[1])
```

Notice that the `csv` library is imported. Further, we created a reader that will hold the result
of `csv.reader(file)`. The `csv.reader` function reads each row from the file, and in our code we store
the results in `reader`. `print(row[1])`, therefore, will print the language from the `favorites.csv` file.

```python
# We may assign a variable to a specific row, but there is a big issue:
# What if they were changed or swapped in the original file?
favorite = row[1]
```

The better approach is to dance over Header row instead.

Let's make our code better `favorites_2.py`:
- The difference between `DictReader` and `reader` is that it automatically analyzes that first line in the file,
figures out what are all of your columns called and, thereafter, when you iterate over `reader` it's no longer
a `list[3]`. Each row in this loop is now a `dictionary` instead. The `keys` are getting from the `Header`, the values
are all rows beneath.

```python
import csv

# Open CSV file
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row["language"])
```

This way we don't lose our columns, well, if they weren't renamed in the file.

Let's analyze how many people prefer Python over C or Scratch, or visa-versa.

We could create counters like this:

```python
# Votes counters
scratch = 0
c = 0
python = 0
```

But let's write it in another way favorites_2.py:

```python
import csv

# Open the file
with open("favorites.csv", "r") as file:
    # Read data and import into reader
    reader = csv.DictReader(file)

    # Votes counters
    scratch, c, python = 0, 0 ,0

    for row in reader:
        favorite = row["language"]
        if favorite == 'C':
            c += 1
        elif favorite == 'Python':
            python += 1
        elif favorite == 'Scratch':
            scratch += 1

# Printing is outside the loop, because at this step
# we don't need an opened file anymore.          
print(f"C: {c}")
print(f"Python: {python}")
print(f"Scratch: {scratch}")
```

Let's remember that Dictionary contains keys and values. So, we can try to keep track of the values instead
of creating a redundant counters.

`favorites_3.py`

```python
import csv

# Open the file
with open("favorites.csv", "r") as file:
    # Read data and import into reader
    reader = csv.DictReader(file)

    # Create an empty dictionary
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
```

- We used 1 dictionary instead of 3 variables.

