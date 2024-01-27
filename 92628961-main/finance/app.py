from flask import Flask, redirect, render_template, request, session
from flask_session import Session
import sqlite3


# Configure app
app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure database
conn = sqlite3.connect("login.db")
db = conn.cursor()
db.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)")

# Define routes

@app.route("/")
def welcome():
    return render_template("welcome.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        user = db.execute("SELECT * FROM users WHERE username = ? AND password = ?", (username, password)).fetchone()
        if user:
            session["user_id"] = user[0]
            return redirect("/welcome")
        else:
            return render_template("login.html", message="Invalid username or password")
    else:
        return render_template("login.html")

@app.route("/signup", methods=["GET", "POST"])
def signup():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if password != confirmation:
            return render_template("signup.html", message="Passwords do not match")
        user = db.execute("SELECT * FROM users WHERE username = ?", (username,)).fetchone()
        if user:
            return render_template("signup.html", message="Username already taken")
        db.execute("INSERT INTO users (username, password) VALUES (?, ?)", (username, password))
        conn.commit()
        return redirect("/login")
    else:
        return render_template("signup.html")

@app.route("/welcome")
def welcome():
    user_id = session.get("user_id")
    if user_id:
        user = db.execute("SELECT * FROM users WHERE id = ?", (user_id,)).fetchone()
        return render_template("welcome.html", username=user[1])
    else:
        return redirect("/login")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")

if __name__ == "__main__":
    app.run(debug=True)
