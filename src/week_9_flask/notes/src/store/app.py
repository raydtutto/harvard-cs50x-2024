from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Connect to database
db = SQL("sqlite:///store.db")

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


@app.route("/")
def index():
    # Returns "books", the list of dictionaries, from database
    books = db.execute("SELECT * FROM books")
    return render_template("books.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():

    # Ensure cart exists, even if its empty
    if "cart" not in session:
        session["cart"] = []

    # If smth was submitted into cart, do POST
    if request.method == "POST":
        # Grabs the book's id
        book_id = request.form.get("id")
        # Checks valid id
        if book_id:
            # Go into list "cart" and add the book with that id
            session["cart"].append(book_id)
        return redirect("/cart")

    # GET
    # Grab books that were bought, search the list "books" for their id's
    # Within CS50 lib you can use `(?)` as a placeholder, it will generate commas between id's for you
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    # Opens cart.html
    return render_template("cart.html", books=books)
