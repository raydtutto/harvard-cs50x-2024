import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database

        name = request.form.get("name")
        if not name:
            return redirect("/")

        month = request.form.get("month")
        if not month:
            return redirect("/")

        day = request.form.get("day")
        if not day:
            return redirect("/")

        # print(f"Name is {name}, {month} month, {day} day")  # DEBUG

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        rows = db.execute("SELECT * FROM birthdays")
        # print(rows) # DEBUG

        return render_template("index.html", birthdays=rows)


@app.route("/delete", methods=["POST"])
def delete():
    if request.method == "POST":
        id = request.form.get("id")
        # print(f"ID is {id}")  # DEBUG
        if id:
            db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")

@app.route("/update", methods=["POST"])
def update_birthday():
    id_update = request.form["id"]
    name = request.form["name"]
    month = request.form["month"]
    day = request.form["day"]

    # Update the database with the new data
    db.execute("UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?", name, month, day, id_update)

    return redirect("/")
