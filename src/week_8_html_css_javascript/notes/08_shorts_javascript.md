# JavaScript

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

Like PHP, JavaScript is a modern programming language that is derived from the syntax at C.

It has been around just about as long as PHP, also having been invented in 1995.

JavaScript, HTML, and CSS make up the three languages defining most of the user experience on the web.

To start writing JavaScript, open up a file with the .js file extension.

No need for any code delimiters like we had in PHP. Our website will know that our file is JavaScript
because we'll explicitly tell it as much in an HTML tag.

Unlike PHP which runs server-side, JavaScript applications run client-side, on your own machine.

---

## Including JavaScript in your HTML

1. Just like CSS with `<style>` tags, you can directly write your JavaScript between `<script>` tags.

2. Just like CSS with `<link>` tags, you can write your JavaScript in separate files and link them in by using
the src attribute of the `<script>` tag.

The second variant is more preferable.

---

## Variables

JavaScript variables are similar to PHP variables.
- No type specifier.
- When a local variable is first declared, preface with the var keyword.

```javascript
// Local variable
var x = 44;

// Global variable
x = 44;
```

---

## Conditionals

All the old favorites from C are still available for you to use.

- `if`
- `else if`
- `else`
- `switch`
- `?:`

---

## Loops

All the old favorites from C are still available for you to use.

- `while`
- `do-while`
- `for`

---

## Functions

All functions are introduced with the `function` keyword.

> JavaScript functions, particularly those bound specifically to HTML elements, can be anonymous—you
> **_don't have to give them a name_**.

We'll revisit anonymity a little later, and we'll revisit "binding to HTML elements" in the video
on the Document Object Model.

---

## Arrays

Declaring an array is pretty straightforward.

```javascript
// Declares a local array
var nums = [1, 2, 3, 4, 5];

// Declares a local array with different element types
var mixed = [1,
             true,
             3.333,
             'five'];
```

---

## Objects

JavaScript has the ability to behave as an object-oriented programming language.

An object is sort of analogous to a C structure.

C structures contain a number of _fields_ or _members_, which we might also call _properties_.
- But the properties themselves can not ever stand on their own.

```c++
// C structure
struct car
{
    int year;
    char model[10];
}

// Creates a herbie car and assignes its members in C
struct car herbie;
herbie.year = 1963;
herbie.model = "Beetle";
```

> Objects, meanwhile, have _properties_ but also _methods_, or functions that are inherent to the object,
> and mean nothing outside of it.
>
> Thus, like properties can methods not ever stand on their own.
>
> > Instead of `function(object);`  in C, we have `object.function();` in JavaScript .

The fields and methods of an object are similar in spirit to the idea of an associative array,
with which we're familiar from PHP.

```javascript
// Creates a herbie car and assignes its members in JavaScript
var herbie = {year : 1963, model: 'Beetle'};
```

---

## Loops (redux)

How do we iterate across all the key-value pairs of an object (or indeed, all the elements of an array)?

```python
# Python loop
for key in list:
    # use key in here as a stand-in for list[i]
```

```javascript
for (var key in object)
{
    // use object[key] in here
}

// or

for (var key of object)
{
    // use key in here
}
```

Example of a loop with an array:

```javascript
var wkArray = ['Monday',
               'Tuesday',
               'Wednesday',
               'Thursday',
               'Friday',
               'Saturday',
               'Sunday'];

// in
for (var day in wkArray)
{
    // Printf() analogue
    console.log(day);
}

// of
for (var day of wkArray)
{
    // Printf() analogue
    console.log(day);
}
```

---

## Printing and variable interpolation

What if we sent to concatenate information to tie different information? We can do it with `+` in JavaScript.

```javascript
console.log(wkArray[day] + ' is day number '
+ (day + 1) + ' of the week!');
```

- `(day + 1)` will work as not expected, it will add the strings like this "day1".

```javascript
console.log(wkArray[day] + ' is day number '
+ (parseInt(day) + 1) + ' of the week!');
```

- `(parseInt(day) + 1)` will work as expected, because now we are adding an integers.

## Functions (redux)

Arrays are a special case of an object (in fact, everything in JavaScript is a special case of an object),
and has numerous methods that can applied to them:

- `array.size()` function checks the length of an array;
  - `array.length` property is more preferable to use;
- `array.pop()` removes the last element from an array and returns that element;
- `array.push(x)` adds new items to the end of an array;
- `array.shift()` removes the first element from an array and returns that removed element.

There is also a **method** for arrays called `map()`, which can be used to apply a function to all elements of an array.
- A great situation to use an **_anonymous function_**.

Example of an anonymous function use:

```javascript
// Declares local array
var nums = [1, 2, 3, 4, 5];

// Doubles the elements of an array
nums = nums.map(function(num) {
    return num * 2;
});

// Array after updating
var nums = [2, 4, 6, 8, 10];
```

---

## Events

An event in **HTML** and **JavaScript** is a response to user interaction with the web page.

A user clicks a button, a page has finished loading, a user has hovered over a portion of the page,
the user typed in an input field.

**JavaScript** has `support` for `event handlers`, which are callback functions that respond to HTML events.

Many HTML elements have `support` for events as an attribute.

```html
<html>
    <head>
        <title>Event Handlers</title>
    </head>
    <body>
        <button onclick="">Button 1</button>
        <button onclick="">Button 2</button>
    </body>
</html>
```

- `onclick=""` - an attribute, a definition for an event handler: "something happens on click the button"

We can write a _**generic event handler**_ in JavaScript, creating an `event object`, that will tell us which of these
two buttons was clicked.

```html
<html>
    <head>
        <title>Event Handlers</title>
    </head>
    <body>
        <button onclick="alertName(event)">Button 1</button>
        <button onclick="alertName(event)">Button 2</button>
    </body>
</html>
```

- `onclick="alertName(event)"` when button is clicked, the `alertName()` function will be called and `event`
will be passed in, `event` is automatically generated by the page and contains all the info about what just happened. 

An example of an `alertName()`:

```javascript
function alertName(event)
{
    var trigger = event.srcElement;
    alert('You clicked on ' + trigger.innerHTML);
}
```

- `event.srcElement` tracks the button that was clicked;
- `...innerHTML` is what is between the `<button>` tags, we have two strings: "Button 1" and "Button 2".
- So, the probable output may look like this: "You clicked on Button 1"