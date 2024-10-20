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

## Insert

