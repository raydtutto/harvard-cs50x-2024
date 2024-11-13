# Flask

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

Python is not just used for command-line programming, it contains native functionality to support networking and more, 
enabling site backends to be written in Python.

> **Web frameworks** make this process much easier, abstracting away the minutia of Python’s syntax and providing 
> helper functions.
> 
> Some of the most popular **web frameworks** include:
> - `Django`
> - `Pyramid`
> - `Flask`

We use Flask in CS50 because it is lightweight for ease of use in CS50 IDE, while still being feature-rich.

We know that we can use `HTML` to build websites, but websites built using pure HTML suffer from a serious limitation - 
they are **static**.

---

## Example "Time"

### -- Time #1 / `HTML` only

Imagine we want to create a website that displays the current time in Cambridge, MA, displaying it to the latest minute
and using _pure HTML_.

```html
<html>
    <head>
        <title>Current Time in Cambridge</title>
    </head>
    <body>
        The current time in Cambridge is 14:08
    </body>
</html>
```

Well, it may be accurate for a minute, but you definitely wouldn't want to change the time manually every minute
on your website.

> Websites that are _pure HTML_ are **completely static**. The only way we can update the content of our pages is to 
> manually open up our source files, edit and save, and then the next time the user visits or refreshes the page
> they’ll get the content.

### -- Time #2 / `HTML` + `Python`

Incorporating **Python** into our code can make our code quite a bit more _flexible_ and introduce a way for our
pages to update or be dynamic without requiring our intervention.

Let's add **Python** features to our code and show the user not only time, but a date, a day of the week and a year.

```python
from flask import Flask # Import Flask
from datetime import datetime # Import required module
from pytz import timezone # Import required module

# Run Flask
app = Flask(__name__)

@app.route("/")
def time():
    # Detect current time in this time zone
    now = datetime.now(timezone('America/New_York'))
    # Return time to user
    return "The current date and time in Cambridge is {}".format(now)
```

---

## Flask

### -- Start using Flask

t’s pretty simple to get started using Flask within CS50 IDE:

```python
from flask import Flask
```

After importing the Flask module, we need to _initiate_ a Flask application.
- `__name__` gets a name of your file, you don't need to change it specifically.

```python
app = Flask(__name__)
```

### -- Decorators

From there, it’s just a matter of writing functions that define the behavior of our application.

```python
from flask import Flask

app = Flask(__name__)

@app.route("/") # Decorator
def index():
    return "You are at the index page!"

@app.route("/sample") # Decorator
def sample():
    return "You are on the sample page!"
```

The lines just added are known as `decorators`. They are used, in Flask, to associate a particular function with
a particular URL.
- `@app.route("/")` - decorator example

Decorators also have more general use in Python, but that goes beyond the scope of CS50.

### -- Run Flask

There are three steps to run Flask application within CS50 IDE:

First two steps you need to run only once:
1. export `FLASK_APP`;
2. `FLASK_DEBUG=1` == `FLASK_DEBUG=True`, run debug mode.

```commandline
export FLASK_APP=application.py
export FLASK_DEBUG=1
```

3. Then you need only one command to run flask:

```commandline
flask run
```

### -- Pass data

Data can be passed in via URLs, akin to using HTTP `GET` by default.

```python
@app.route("/show/<number>")
def show(number):
    return "You passed in {}".format(number)
```

Data can be passed in via HTML forms, as with HTTP `POST`,
but we need to indicate that Flask should respond to HTTP POST requests explicitly.

```python
@app.route("/login", methods=['GET', 'POST'])
def login():
    # If there are no field called "username" in "form"
    if not request.form.get("username")
        return apology("must provide username")
```

### -- Receive data

We could also vary the behavior of our function depending on the type of HTTP request received:

```python
@app.route("/login", methods=['GET', 'POST'])
def login():
    if request.method == "POST":
        # do one thing
    else:
        # do a different thing
```

---

## Flask functions

Flask has a number of functions within its module that will be useful for application development.

- `url_for()`
  - instead of specifying the exact URL you want to go to, you can go to the URL for whatever function it is 
  (the URL from `decorator`).
- `redirect()`
  - redirects from one page to another.
- `session()`
  - useful for HTTP session data, e.g. track that the user is logged in. Something like a global variable, that 
  is accessible by all pages.
- `render_template()`
  - creates pages on your site mixing HTML and Python together.

> ### Guides
> - More information available at the Flask [quick start guide](http://flask.pocoo.org/docs/0.12/quickstart/).
> - More information on using [Jinja](http://jinja.pocoo.org/).