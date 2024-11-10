from flask import Flask, render_template, request

# Pass the file name to Flask, without specifying it
app = Flask(__name__)

# "/" - default folder
@app.route("/")
# route() defines the route of an application, so that when user visit "/" on this app
# it will call index() and write "hello, world"
def index():
    return "hello, world"
