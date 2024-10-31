# HTML

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

**HTML** (_Hypertext Markup Language_) is a fundamental component of every website.

HTML is a language, but it is not a programming language, it is a _markup language_, using angle-bracket
enclosed `tags` to semantically define the structure of a web page, causing the plain text inside of sets of tags
to be interpreted by web browsers in different ways.

```html
// Simple HTML page:
 
<html>
    <head>
        <title>
            Hello, world
        </title>
    </head>
    <body>
        World, hello
    </body>
</html>
```

- `<html>`
- `<head>`
- `<title>`
- `<body>`

```html
<html><head><title>Hello,
world</title></head><body>World,
hello</body></html>
```

Notice how the markup allows us to convey extra information about the text we’ve written.

There are over 100 HTML tags, and lots of great resources online to find them. We won’t cover them all here.

Another interesting way to learn about HTML tags is to view the source of a website you frequent by opening up
your browser of choice’s developer tools.

---

## Common HTML tags

### Text formatting

- `<b>`, `</b>` Text between these tags will be rendered in **boldface** by the browser.
- `<i>`, `</i>` Text between these tags will be rendered in _italics_ by the browser.
- `<u>`, `</u>` Text between these tags will be rendered underlined by the browser.

```html
<html>
    <body>
    This text is <b>bold</b>, this text is <i>italic</i>,
    this text is <u>underlined</u>.
    </body>
</html>
```

- `<p>`, `</p>` Text between these tags will be rendered as a paragraph by the browser,
with space above and below.
- `<hX>`, `</hX>` Text between these tags will be rendered as an X-level section header.
  -  `h1`, `h2`, `h3`, `h4`, `h5` or `h6`.

```html
<html>
  <body>
    <h1>First level header</h1>
      <p>
        Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore
        et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
        aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
        cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa
        qui officia deserunt mollit anim id est laborum.
      </p>
      <p>
        Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore
        et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
        aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
        cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa
        qui officia deserunt mollit anim id est laborum.
      </p>
    <h2>Second level header</h2>
      <p>
        Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore
        et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
        aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
        cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa
        qui officia deserunt mollit anim id est laborum.
      </p>
  </body>
</html>
```

### Lists

- `<ul>`, `</ul>` Demarcate the beginning and end of an unordered (**bulleted**) list.
- `<ol>`, `</ol>` Demarcate the beginning and end of an ordered (**numbered**) list.
- `<li>`, `</li>` Demarcate **list items** with an ordered or unordered list.

```html
<html>
  <body>
    <ul>
      <li>alpha</li>
      <li>beta</li>
      <li>gamma</li>
      <li>delta</li>
      <li>epsilon</li>
    </ul>
    
    // Start counting at 6
    <ol start="6">
      <li>zeta</li>
      <li>eta</li>
      <li>theta</li>
      <li>iota</li>
      <li>kappa</li>
    </ol>
  </body>
</html>
```

### Table

- `<table>`, `</table>` Demarcate the beginning and end of a **table** definition.
  - `<tr>`, `</tr>` Demarcate the beginning and end of a **row** within a table.
    - `<td>`, `</td>` Demarcate the beginning and end of a **column** within a row within a table.

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

### HTML form

- `<form>`, `</form>` Demarcate the beginning and end of an HTML form.
- `<div>`, `</div>` Demarcate the beginning and end of an arbitrary HTML page division.
- `<input name=X type=Y />` Define a field within an HTML form. X is a unique identifier for that field, Y is
  what type of data it accepts.
  - `< ... />` self-closing tag.

```html
<html>
  <body>
    <div>
      Arbitrary first division
    </div>
    Here is the form:
    <div>
      <form>
        Text: <input name="a" type="text" />
        Password: <input name="b" type="password" />
        Radio: <input name="c" type="radio" />
        Checkbox: <input name="d" type="checkbox" />
        Submit: <input name="e" type="submit" />
      </form>
    </div>
  </body>
</html>
```

### Hyperlink

- `<a href=X>`, `</a>` Creates a hyperlink to web page X, with the text between the tags rendered
  and functional as the [link text]().
- `<img src=X ... />` Another self-closing tag for displaying an image located at X, with possible
  additional attributes (such as specifying width and height).

### HTML5

- `<!DOCTYPE html>` Specific to HTML5, lets the browser know that’s the standard you’re using.

### Comment

- `<!--, -->` Demarcate the beginning and end of an HTML comment.

```html
<html>
  <body>
    <div>
      <!-- Here is a picture of a cat -->
      <img src="../img/cat.jpg">
    </div>
    <div>
      <!-- Here is an internal link to another page -->
      <a href="hello.html">To hello.html</a>

      <!-- Here is an external link -->
      To <a href="https://cs50.harvard.edu/">CS50's website</a>
    </div>
  </body>
</html>
```

---

> Beyond the tags as explained here, each can also have multiple `attributes` that slightly modify the tag.
> 
> For example, you can usually add an `id=X` attribute, to uniquely identify a tag within an overall page.

It is important that the HTML you write be well-formed. Every tag you open should be closed (unless it is
a self-closing tag), and tags should be closed in reverse order of when they were opened.