from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Delete "world" from form
        name = request.form.get("name")
        return render_template("greet.html", name=name)
    return render_template("index.html")
