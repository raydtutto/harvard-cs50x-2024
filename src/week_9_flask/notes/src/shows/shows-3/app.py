# Searches for shows using Ajax with JSON

from cs50 import SQL
# Import jsonify function (turn smth to JSON)
from flask import Flask, jsonify, render_template, request

app = Flask(__name__)

# Get .db from the parent directory
db = SQL("sqlite:///../shows.db")


@app.route("/")
def index():
    return render_template("index.html")

# The same code as it was in "shows-2"
@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    else:
        shows = []
    # BUT
    # Instead of passing any template, we turn that text to JSON
    return jsonify(shows)
