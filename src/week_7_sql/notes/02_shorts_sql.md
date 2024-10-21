# SQL

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

## Database

To build the most functional website we can depend on a database to store information.

> **SQL** (_the Structured Query Language_) is a programming language whose purpose is to query a database.
>
> **MySQL** is an _open-source platform_ on which you can establish the type of relational database that SQL
> is most adept at working with.
> 
> **SQLite** is another, we are using it in CS50.

Many installations of **MySQL** come with a **GUI** tool called **phpMyAdmin** which can be used to execute
database queries in a more user-friendly way.

---

## Create a table

After you create a database, the next thing you’ll most likely want to do is create a table:

- The syntax for doing this is actually a bit awkward to do programmatically, at least at the outset, and so this is
where **phpMyAdmin** will come in handy.
- As part of the process of creating a table, you’ll be asked to specify all the **columns** in that table.
- Thereafter, all your queries will refer to **rows** of the table.

---

## Data types

> Each column of your **SQL** table is capable of holding data of a _particular data type_.
> - `INT` other variations of `int` below just have different upper-bounds;
> - `SMALLINT`
> - `TINYINT`
> - `MEDIUMINT`
> - `BIGINT`
> - `DECIMAL` = double
> - `FLOAT` = float
> - `BIT`
> - `DATE`
> - `TIME`
> - `DATETIME`
> - `TIMESTAMP`
> - `CHAR` is a **fixed-length** string, unlike in C;
>   - In most relational databases, including MySQL, you actually specify
>   the fixed-length as part of the type definition, e.g. `CHAR(10)`;
> - `VARCHAR` refers to a **variable-length** string;
>   - Require you to specify the maximum possible length 
>   of a string that could be stored in that column, e.g. `VARCHAR(99)`;
> - `BINARY`
> - `BLOB`
> - `TEXT` = strings
> - `ENUM` stores limited set of enumerated values that can be stored within column;
> - `GEOMETRY` and LINESTRING used to drawing an area on a map, such as using `GIS` data;
> - `LINESTRING`
> - and many others...
> 
> > **SQLite** has these data types as well, but affiliates each with `type affinity` to simplify things:
> > - `NULL`
> > - `INTEGER` just a whole numbers;
> > - `REAL` includes decimal and float;
> > - `TEXT` includes CHAR and VARCHAR;
> > - `BLOB` is a large number of bits/bytes like GEOMETRY.

---

## Primary key

One other important consideration when constructing a table in **SQL** is to choose one column to be your `primary key`.

> **Primary keys** enable rows of a table to be uniquely and quickly identified.
>
> Choosing your primary key appropriately can make subsequent operations on the table much easier.

It is also possible to establish a `joint primary key` – a combination of two columns that is always guaranteed
to be unique.

---

## Operations

SQL is a programming language, but its vocabulary is fairly limited.

We will primarily consider just four operations that one may perform on a table:
- `INSERT`
- `SELECT`
- `UPDATE`
- `DELETE`

> For the next examples we will use these two tables:

### `users` table
| idnum | username  | password | fullname         |
|-------|-----------|----------|------------------|
| 10    | jerry     | fus!II!  | Jerry Seinfield  |
| 11    | gcostanza | b0sc0    | George Constanza |

### `moms` table
| username  | mother            | 
|-----------|-------------------|
| jerry     | Helen Seinfield   |
| gcostanza | Estelle Constanza |

---

### --- `INSERT`

> Add information to a table. Syntax:
>
> ```
> INSERT INTO <table> (<columns>) VALUES (<values>);
> ```

```sqlite
INSERT INTO users (username, password, fullname) VALUES (‘newman’, ‘USMAIL’, ‘Newman’);
```

### `users` table
| idnum | username  | password | fullname         |
|-------|-----------|----------|------------------|
| 10    | jerry     | fus!II!  | Jerry Seinfield  |
| 11    | gcostanza | b0sc0    | George Constanza |
| 12    | newman    | USMAIL   | Newman           |

We just added a new user, but from where we get `idnum`?

> ### --- Auto increment
>
> When defining the column that ultimately ends up being your table’s `primary key`, it’s usually a good idea
> to have that column be an `integer`.
> 
> Moreover, to eliminate the situation where you may accidentally forget to specify a real value for the primary key
> column, you can configure that column to `autoincrement`, so it will _**pre-populate that column for you automatically**_
> when rows are added to the table.

Let's add row to another table:

```sqlite
INSERT INTO moms (username, mother) VALUES (‘kramer’, ‘Babs Kramer’);
```

### `moms` table
| username  | mother            | 
|-----------|-------------------|
| jerry     | Helen Seinfield   |
| gcostanza | Estelle Constanza |
| kramer    | Babs Kramer       |

---

### --- `SELECT`

> Extract information **from** a table. Syntax:
> ```sqlite
> SELECT <columns> FROM <table> WHERE <condition or predicate> ORDER BY <column>;
> ```
> 
> `WHERE` and `ORDER BY` are optional.

```sqlite
SELECT idnum, fullname FROM users;
```

It will select all rows (except for the header) from columns `idnum` and `fullname`:

### `users` table
| idnum | username  | password | fullname         |
|-------|-----------|----------|------------------|
| 10    | jerry     | fus!II!  | Jerry Seinfield  |
| 11    | gcostanza | b0sc0    | George Constanza |
| 12    | newman    | USMAIL   | Newman           |

Let's make our select more specific:

```sqlite
SELECT password FROM users WHERE idnum < 12;
```

It will select only `fus!II!` and `b0sc0` from the password column.

Let's make our select more specific:

```sqlite
SELECT * FROM moms WHERE username = 'jerry';
```
- `*` is a shorthand for every column = _"give me everything in that row"_

So, we will get the entire row where `jerry` exist:

| username  | mother            |
|-----------|-------------------|
| jerry     | Helen Seinfield   |

---

## Relational databases

> Databases empower us to organize information into tables efficiently.
>
> We don’t always need to store every possible relevant piece of information in the same table, but can use
> relationships across the tables to let us pull information from where we need it.

### --- `SELECT` (`JOIN`) query

> Extract information from multiple tables. Syntax:
> ```sqlite
> SELECT <columns> FROM <table1> JOIN <table2> ON <predicate>;
> ```

What if we now find ourselves in a situation where we need to get a user’s full name (from the users table)
and their mother’s name (from the mother table)?

```sqlite
SELECT users.fullname, moms.mother FROM users JOIN moms ON users.username = moms.username;
```

- `users.fullname` is `<table>.<column>`, a syntax for specifying a column from a table.

So, we are trying to get the common info (`users.username = moms.username`) from two tables. Those are:
- `jerry`
- `gcostanza`

### `users` table
| idnum | username        | password | fullname         |
|-------|-----------------|----------|------------------|
| 10    | **_jerry_**     | fus!II!  | Jerry Seinfield  |
| 11    | **_gcostanza_** | b0sc0    | George Constanza |
| 12    | newman          | USMAIL   | Newman           |

### `moms` table
| username        | mother            | 
|-----------------|-------------------|
| **_jerry_**     | Helen Seinfield   |
| **_gcostanza_** | Estelle Constanza |
| kramer          | Babs Kramer       |

So we get this joined temporary table `users & moms`:

| users.idnum | users.username, moms.username | users.password | users.fullname   | moms.mother       |
|-------------|-------------------------------|----------------|------------------|-------------------|
| 10          | jerry                         | fus!II!        | Jerry Seinfield  | Helen Seinfield   |
| 11          | gcostanza                     | b0sc0          | George Constanza | Estelle Constanza |

And now we can extract what we where looking for (`users.fullname, moms.mother`):

| users.fullname   | moms.mother       |
|------------------|-------------------|
|  Jerry Seinfield | Helen Seinfield   |
| George Constanza | Estelle Constanza |

---

### --- `UPDATE`

> Modify information in a table. Syntax:
> ```sqlite
> UPDATE <table> SET <column> = <value> WHERE <predicate>;
> ```

Let's update the password: for a user with idnum 10:

```sqlite
UPDATE users SET password = ‘yadayada’ WHERE idnum = 10
```

| idnum | username        | password   | fullname         |
|-------|-----------------|------------|------------------|
| 10    | **_jerry_**     | ‘yadayada’ | Jerry Seinfield  |

---

### --- `DELETE`

> Remove information from a table. Syntax:
> 
> ```sqlite
> DELETE FROM <table> WHERE <predicate>;
> ```

```sqlite
DELETE FROM users WHERE username = ‘newman’;
```

Our table looked like this **before** deletion operation:

### `users` table
| idnum | username        | password | fullname         |
|-------|-----------------|----------|------------------|
| 10    | **_jerry_**     | fus!II!  | Jerry Seinfield  |
| 11    | **_gcostanza_** | b0sc0    | George Constanza |
| 12    | newman          | USMAIL   | Newman           |

**After** deletion:

### `users` table
| idnum | username        | password | fullname         |
|-------|-----------------|----------|------------------|
| 10    | **_jerry_**     | fus!II!  | Jerry Seinfield  |
| 11    | **_gcostanza_** | b0sc0    | George Constanza |

---

## `query()`

All of these operations are pretty easy to do in the graphical interface of `phpMyAdmin`.

We want a way to do this programmatically, not just typing **SQL** commands into the “SQL” tab of `phpMyAdmin`.

Fortunately, **SQL** integrates with **PHP** very well, by way of functions like `query()`.

After you’ve connected to your database with **PHP** (using a process called MySQLi or PDO),
you can make pass query strings as arguments to functions in **PHP** and store the result set in an associative array.

```php
$results = query(“SELECT fullname FROM users WHERE idnum = 10”);
```

```php
$results = query(“SELECT fullname FROM users WHERE idnum = 10”);
print(“Thanks for logging in, {$results[‘fullname’]}!”);
```

```php
$results = query(“SELECT fullname FROM users WHERE idnum = ?”,
                $_SESSION[“id”]);
print(“Thanks for logging in, {$results[‘fullname’]}!”);
```

It’s also possible your result set might consist of multiple rows, in which case the result set would be an array
of associative arrays, so just need to iterate through it.

```
<p>The moms of TV’s Seinfeld:</p>
<table>
<?php
    $results = query(“SELECT mothers FROM moms”);
    if($results !== false)
    {
        foreach($results as $result)
        {
            print(“<tr><td>” . $result[‘mothers’] . “</td></tr>”);
        }
    }
?>
</table>
```

