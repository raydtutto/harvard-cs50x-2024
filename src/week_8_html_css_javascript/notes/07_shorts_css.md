# CSS

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

**CSS** (_Cascading Style Sheets_) is another language we use to when constructing websites.

If HTML is used to organize the content that we aim to display on our pages, then CSS is the tool we use
to customize our website’s look and feel.

Like HTML, CSS is not a programming language; it lacks logic. Rather, it is a styling language and its syntax
describes how certain attributes of HTML elements should be modified.

```css
body
{
    background-color: blue;
}
```

- `body` take everything between "body" tags -->
- `background-color` set the background color of them -->
- `blue`

A style sheet is constructed by identifying a _selector_ (in the last example, body) and then an open curly brace
to indicate the beginning of the style sheet for that selector.

In between the curly brace you place a list of `key-value` pairs of style properties and values
for those properties, each _declaration_ ending with a semicolon.

Then a closing curly brace terminates the style sheet.

## Common CSS properties

### Color

- `border: style color width` Applies a border of the specified color, width, and style (e.g., dotted, dashed,
solid, ridge…).
- `background-color: [keyword]` or `[#<6-digit hex>]` Sets the background color. Some colors are pre-defined in CSS.
- `color: [keyword]` or `[#<6-digit hex>]` Sets the foreground color (usually text).

### Fonts

- `font-size: [absolute size]` or `[relative size]` Can use keywords (xx-small, medium…), fixed points (10pt, 12pt…), 
percentage (80%, 120%), or base off the most recent font size (smaller, larger).
- `font-family: [font name]` or `[generic name]` Certain “web safe” fonts are pre-defined in CSS.
- `text-align: [left | right | center | justify]` For displaying text.

> Your selectors don’t have to apply only to HTML tag categories. There also exist ID selectors and class selectors.

### Tag

A **tag** selector will apply to all elements with a given HTML tag.

```css
h2
{
    font-family: times;
    color: #fefefe;
}
```

Your selectors don’t have to apply only to HTML tag categories. 

There also exist ID selectors and class selectors.

### #ID

An **ID** selector will apply only to an HTML tag with a unique
identifier.

```css
#unique
{
    border: 4px dotted blue;
    text-align: right;
}
```

### .Class

Your selectors don’t have to apply only to HTML tag categories. There also exist ID selectors and class selectors.

A **class** selector will apply only to those HTML tags that have been given identical “class” attributes.

```css
.students
{
    background-color: yellow;
    opacity: 0.7;
}
```

---

Style sheets can be written directly into your HTML.
- Place them within `<style>` tags within your page’s head.

Style sheets can also be written as separate CSS files and then linked in to your document.
- Use `<link>` tags within your page’s head to accomplish this.

---

## Table.html

```html
<html>
  <body>
    <table>
      <tr>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
      </tr>
      <tr>
        <td>2</td>
        <td>4</td>
        <td>6</td>
        <td>8</td>
      </tr>
      <tr>
        <td>3</td>
        <td>6</td>
        <td>9</td>
        <td>12</td>
      </tr>
      <tr>
        <td>4</td>
        <td>8</td>
        <td>12</td>
        <td>16</td>
      </tr>
    </table>
  </body>
</html>
```

Let's make more pretty our previously made table.

### table2.html

We slightly changed our table with a blue border outside the table:

```html
<html>
<head>
  <style>
    table
    {
      border: 2px solid blue;
    }
  </style>
</head>
<body>
<table>
  <tr>
    <td>1</td>
    <td>2</td>
    <td>3</td>
    <td>4</td>
  </tr>
  <tr>
    <td>2</td>
    <td>4</td>
    <td>6</td>
    <td>8</td>
  </tr>
  <tr>
    <td>3</td>
    <td>6</td>
    <td>9</td>
    <td>12</td>
  </tr>
  <tr>
    <td>4</td>
    <td>8</td>
    <td>12</td>
    <td>16</td>
  </tr>
</table>
</body>
</html>
```

### table3.html

This time we are embedding a separate stylesheet:

```html
<html>
<head>
    <link href="tables.css" rel="stylesheet" />
</head>
<body>
<table>
    <tr>
        <td>1</td>
        <td>2</td>
        <td>3</td>
        <td>4</td>
    </tr>
    <tr>
        <td>2</td>
        <td>4</td>
        <td>6</td>
        <td>8</td>
    </tr>
    <tr>
        <td>3</td>
        <td>6</td>
        <td>9</td>
        <td>12</td>
    </tr>
    <tr>
        <td>4</td>
        <td>8</td>
        <td>12</td>
        <td>16</td>
    </tr>
</table>
</body>
</html>
```

Let's have a look at `tables.css`

```css
table
{
    border: 5px solid darkgrey;
}

tr
{
    height: 50px;
}

td
{
    /* Lots being applied here */

    background-color: royalblue;
    color: white;
    font-size: 22pt;
    font-family: georgia;
    text-align: center;
    width: 50px;
}
```