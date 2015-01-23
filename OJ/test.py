from flask import Flask, url_for, render_template, request

app = Flask(__name__)

@app.route('/')
def Homepage():
	return render_template('homepage.html')

@app.route('/login')
def Login():
	return render_template('login.html')

@app.route("/sign_up")
def Sign_up():
	return render_template("sign_up.html")


if __name__ == '__main__':
	app.run()