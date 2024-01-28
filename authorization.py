# Simple server to receive the token needed for the app authorization
from flask import Flask, request, Response
import requests
import base64

app = Flask(__name__)

envFile = '.env'
serverUrl = "http://localhost:3000"

with open(envFile, "r") as file:
    client_id = file.readline().strip()
    client_secret = file.readline().strip()

print('client_id:'+client_id)
print('client_secret:'+client_secret)

@app.route('/', methods=['GET'])
def root():
    return app.redirect("https://accounts.spotify.com/authorize?"+
        "response_type=code"+
        "&client_id="+client_id+
        "&scope=user-read-playback-state user-modify-playback-state user-read-currently-playing"+
        "&redirect_uri="+serverUrl+"/callback"
    )


@app.route('/callback', methods=['GET'])
def callback():
    code = request.values.get('code')
    if(code is not None):
        headers = {
            'content-type':'application/x-www-form-urlencoded',
            'Authorization':'Basic '+base64.b64encode(bytes(client_id + ':' + client_secret, encoding='utf8')).decode('utf8')
        }
        forms = {
            'grant_type':'authorization_code',
            'redirect_uri':serverUrl+'/callback',
            'code':code
        }
        returnedResponse = requests.post('https://accounts.spotify.com/api/token', data=forms, headers=headers)
        if(returnedResponse.json()['access_token'] is not None):
            return returnedResponse.json()['access_token']
        return returnedResponse.content
    return 'Error'

app.run(host="0.0.0.0", port=3000, debug=False)