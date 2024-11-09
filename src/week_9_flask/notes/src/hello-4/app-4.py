from flask import Flask, render_template, request

# Pass the file name to Flask, without specifying it
app = Flask(__name__)

# "/" - default folder
@app.route("/")
def index():
    # If `name` exists
    if "name" in request.args:
        name = request.args["name"]
    # If no name were provided
    else:
        name = "world"
    return render_template("index.html", placeholder=name)