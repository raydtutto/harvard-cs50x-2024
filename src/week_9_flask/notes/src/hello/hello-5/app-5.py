from flask import Flask, render_template, request

# Pass the file name to Flask, without specifying it
app = Flask(__name__)

# "/" - default folder
@app.route("/")
def index():
    # If there is no key "name", use a default key "world"
    name = request.args.get("name", "world")
    return render_template("index.html", name=name)