from flask import Flask, redirect, render_template, request, session, url_for
from flask_login import UserMixin
from flask_sqlalchemy import SQLAlchemy
import sqlite3

# Configure app
app = Flask(__name__)
db = SQLAlchemy()
DB_NAME = "database.db"
app.config['SECRET_KEY'] = 'hjshjhdjah kjshkjdhjs'
app.config['SQLALCHEMY_DATABASE_URI'] = f'sqlite:///{DB_NAME}'
db.init_app(app)


class User(db.Model, UserMixin):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(20), nullable=False)
    password = db.Column(db.String(80), nullable=False)

downloads = 0

@app.route("/")
def welcome():
    return render_template('welcome.html', downloads=downloads)

@app.route("/increment_downloads", methods=["POST"])
def increment_downloads():
    global downloads
    downloads += 1
    return "", 204

@app.route("/login", methods=["GET", "POST"])
def login():
    return render_template("login.html")

@app.route("/signup", methods=["GET", "POST"])
def register():
    return render_template("signup.html")

@app.route("/welcome")
def greet():
    return render_template("welcome.html")

@app.route("/about")
def about():
    return render_template("about.html")

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(debug=True)
