# Week 9: Flask / Section

Instructor: [**Carter Zenke**](https://github.com/carterzenke)

---

## Flask

**Flask** - a web framework, that helps more easily and more securely build web applications.

### -- Routes

```
https://birthdays.com/
```

- `https://` is a **protocol**, HTTPS (HyperText Transfer Protocol);
- `birthdays.com` is a **domain** name of your website;
- `/` is a default homepage `route` where we're accessing the application.
  - `/about-us` route to "about" section
  - `/register` route to "register" section
  - `/any-route-you-want`

**Flask** features:
- `Listen` for requests to a certain route.
- `Execute` Python code depending on the route requested.
- `Render` HTML files depending on the route requested.

```python
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")
```

### -- Request Methods

Browsers can use different methods to request a route.

- `GET` to get some data from server;
- `POST` to give some data to store within server.

```html
<form action="/" method="post">
  <input type="text">
  <button type="submit">
    Submit
  </button>
</form>
```

- `action="/"` route to request after "Submit" is clicked; 
- `method="post"` which method should we use to access that route.