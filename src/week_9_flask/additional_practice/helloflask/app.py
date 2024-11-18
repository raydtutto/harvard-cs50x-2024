from flask import Flask, render_template, request

app = Flask(__name__)

COLORS = [
    {"color_name": "Harvard Crimson", "color": "red"},
    {"color_name": "Yale Blue", "color": "blue"}
]

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html", colors=COLORS)
    else:
        print("Form submitted!")

        # Get color name from form
        color = request.form.get("color")

        # Ensure color exist and in COLORS[]
        if not color or not any(c["color_name"] == color for c in COLORS):
            return "Invalid color"

        # Get color value
        for item in COLORS:
            if color == item["color_name"]:
                color_value = item["color"]

        return render_template("color.html", color=color, color_value=color_value, colors=COLORS)
