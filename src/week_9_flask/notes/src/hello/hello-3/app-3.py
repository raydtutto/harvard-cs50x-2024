from flask import Flask, render_template, request

# Pass the file name to Flask, without specifying it
app = Flask(__name__)

# "/" - default folder
@app.route("/")
def index():
    name = request.args["name"]
    return render_template("index.html", placeholder=name)
