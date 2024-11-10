from flask import Flask, render_template, request

# Pass the file name to Flask, without specifying it
app = Flask(__name__)

# "/" - default folder
@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet")
def greet():
    name = request.args.get("name", "world")
    return render_template("greet.html", name=name)