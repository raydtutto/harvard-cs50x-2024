# Week 7: SQL / Section

Instructor: [**Carter Zenke**](https://github.com/carterzenke)

---

**Database** - a collection of data organized for creating, reading, updating, and deleting.
- Scale
- Frequency
- Speed

---

## Database Management System

Software via which you can interact with a database:
- MySQL
- Oracle
- PostgreSQL
- SQLite
- ...

**SQL** - a language via which you can create, read, update, and delete data in a database.

---

## Design principles

Imagine that we need to implement a database for "Goodreads". Maybe there will be these data fields:
- Book title;
- Publication date (YYYY-MM-DD);
- Author;
- Author's birthdate;
- Book's rating.

This is a quick table draft:

| title              | published  | author           | author_birth | rating |
|--------------------|------------|------------------|--------------|--------|
| Flights            | 2017-05-17 | Olga Tokarczuk   | 1962         | 4      |
| The Books of Jacob | 2021-11-15 | Olga Tokarczuk   | 1962         | 5      |
| Paradais           | 2022-03-23 | Fernanda Melchor | 1982         | 4      |
| Hurricane Season   | 2020-02-19 | Fernanda Melchor | 1982         | 5      |
| The other name     | 2019-10-10 | Jon Fosse        | 1959         | 5      |
| A new name         | 2021-09-08 | Jon Fosse        | 1959         | 4      |

We can have some thought on it and decide to separate books table from authors table to avoid repetition:

| title              | published  | rating |
|--------------------|------------|--------|
| Flights            | 2017-05-17 | 4      |
| The Books of Jacob | 2021-11-15 | 5      |
| Paradais           | 2022-03-23 | 4      |
| Hurricane Season   | 2020-02-19 | 5      |
| The other name     | 2019-10-10 | 5      |
| A new name         | 2021-09-08 | 4      |

| author           | author_birth |
|------------------|--------------|
| Olga Tokarczuk   | 1962         |
| Fernanda Melchor | 1982         |
| Jon Fosse        | 1959         |

But now we have a new problem: how to stitch those tables together? We can use Primary and Foreign keys:
- add PRIMARY KEY `id` for books and authors.

| id | title              | published   | rating |
|----|--------------------|-------------|--------|
| 1  | Flights            | 2017-05-17  | 4      |
| 2  | The Books of Jacob | 2021-11-15  | 5      |
| 3  | Paradais           | 2022-03-23  | 4      |
| 4  | Hurricane Season   | 2020-02-19  | 5      |
| 5  | The other name     | 2019-10-10  | 5      |
| 6  | A new name         | 2021-09-08  | 4      |

| id | author           | author_birth |
|----|------------------|--------------|
| 1  | Olga Tokarczuk   | 1962         |
| 2  | Fernanda Melchor | 1982         |
| 3  | Jon Fosse        | 1959         |

But we still didn't solve our problem. We can try to associate our tables:
- create a new table `authored`;
- add FOREIGN KEY `author_id` and `book_id` in the new table.

| author_id | book_id |
|-----------|---------|
| 1         | 1       |
| 1         | 2       |
| 2         | 3       |
| 2         | 4       |
| 3         | 5       |
| 3         | 6       |

The table like that can be called `associative entity`, `junction table` or `joint table`. The idea is to associate
_Foreign keys_ from this table to _Primary keys_ from other tables.

---

## `reads.db`

### --- Creating a database

Let's create our books' database.

> ### Design principles:
> - Create one table for each **entity** in your dataset;
> - All tables should have a `primary key`;
> - The information in the table should depend on the primary key **only**.

```sqlite
$ sqlite3 reads.db
Are you sure you want to create reads.db? [y/N] y
sqlite>
```

### --- Creating a `books` table

> Now we can create a table using this syntax:
> 
> ```sqlite
> sqlite> CREATE TABLE table_name (
> ...> column0 TYPE,
> ...> column1 TYPE,
> ...> column2 TYPE,
> ...> column3 TYPE,
> ...> PRIMARY KEY(column0)
> ...> );
> ```

```sqlite
sqlite> CREATE TABLE books (
   ...>     id INTEGER,
   ...>     title TEXT,
   ...>     published NUMERIC,
   ...>     rating INTEGER,
   ...>     PRIMARY KEY(id)
   ...> );
```

Now we can check what tables do we have inside our database:

```sqlite
sqlite> .tables
books
```

Also, we can check the `books` schema:

```sqlite
sqlite> .schema books
CREATE TABLE books (
    id INTEGER,
    title TEXT,
    published NUMERIC,
    rating INTEGER,
    PRIMARY KEY(id)
);
sqlite> 
```

### --- Creating an `authors` table

```sqlite
sqlite> CREATE TABLE authors (
   ...>     id INTEGER,
   ...>     author TEXT,
   ...>     author_birth INTEGER,
   ...>     PRIMARY KEY(id)
   ...> );
```

Now we have two tables in our database:

```sqlite
sqlite> .tables
authors  books  
```

### --- Creating an `authored` table

We do not have PRIMARY keys in `authored`, but we can make **_Primary key a combination of Foreign keys_**. 

```sqlite
sqlite>  CREATE TABLE authored (
    ...>     author_id INTEGER,
    ...>     book_id INTEGER,
    ...>     PRIMARY KEY(author_id, book_id),
    ...>     FOREIGN KEY(author_id) REFERENCES authors(id),
    ...>     FOREIGN KEY(book_id) REFERENCES books(id)
   ...> );
sqlite> .tables
authored  authors   books   
sqlite> 
```

### --- Insert and delete one row

PRIMARY KEYS are automatically added for us, so we don't need to specify data for `id`.

```sqlite
sqlite> INSERT INTO table (column0, column1)
...> VALUES(value0, value1);
```


Let's insert the first row of data into `books`:

```sqlite
sqlite> INSERT INTO books (title, published, rating)
   ...> VALUES('Flights', '2017-05-17', 4);


sqlite> SELECT * FROM books;
+----+---------+------------+--------+
| id |  title  | published  | rating |
+----+---------+------------+--------+
| 1  | Flights | 2017-05-17 | 4      |
+----+---------+------------+--------+
sqlite> 
```

Deletion has a quite simple syntax:

```sqlite
sqlite> DELETE FROM table
...> WHERE condition;
```

```sqlite
sqlite> DELETE FROM books WHERE title = 'Flights';
```

### --- Inserting multiple rows


```sqlite
sqlite> INSERT INTO table (column0, column1)
...> VALUES(value0, value1),
...> VALUES(value0, value1),
...> VALUES(value0, value1);
```

---

## Read .sql file

To read and run the command from .sql:

```sqlite
sqlite> .read <filename>
```

---

## Get the info about insides of database

```sqlite
sqlite> .tables 
```

---

## Schema of tables

```sqlite
sqlite> .schema <table name>
```

---

## Aggregate function

Keywords to calculate data from multiple data.
- SELECT `COUNT(column)`
- SELECT `AVG(column)`
- SELECT `MIN(column)`
- SELECT `MAX(column)`
- SELECT `ROUND(column)`

We can combine those function together:

```sqlite
sqlite> SELECT ROUND(AVG(energy), 2)
   ...> FROM songs;
+-----------------------+
| ROUND(AVG(energy), 2) |
+-----------------------+
| 0.66                  |
+-----------------------+
sqlite> 
```

---

## Combining tables

There are two ways to combine tables:
- Subqueries;
- Joins.

`Subqueries`:
```sqlite
-- The average energy of songs that are by Drake.
SELECT AVG(energy)
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = 'Drake'
);
```

`Joins`:
```sqlite
SELECT songs.name, energy, artists.name
FROM songs
JOIN artists ON artists.id = songs.artist_id
WHERE artists.name = 'Drake';
```

---

## Find words

`LIKE` keyword can be used to match strings with certain phrases.
- `'%feat%'` searches in the whole string;
- `'%feat'` searches at the end of string;
- `'feat%'` searches at the beginning of string.

```sqlite
SELECT name FROM songs WHERE name LIKE '%feat%';
```