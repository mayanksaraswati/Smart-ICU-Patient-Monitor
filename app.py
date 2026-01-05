from flask import Flask, request, render_template

app = Flask(__name__)

# Store latest data
data = {"heart": 0, "temp": 0, "oxygen": 0}

@app.route('/')
def index():
    return render_template('index.html', data=data)

@app.route('/update')
def update():
    heart = request.args.get('heart', type=float)
    temp = request.args.get('temp', type=float)
    oxygen = request.args.get('oxygen', type=float)
    
    data['heart'] = heart
    data['temp'] = temp
    data['oxygen'] = oxygen
    
    return "Data Updated"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
