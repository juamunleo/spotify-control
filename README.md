# Spotify Player Control

## Dev container
### Build the image
Assuming you are in the project root folder:
```
cd docker
```
```
docker build -t c_devcontainer . --no-cache
```
### Start the container
```
docker compose up -d
```

### Connect to the container
Using vscode remote containers

<br><br>

## Configure the project
### .env file
Read .env.template to create your own .env file in order to build the application.

<br><br>

## Debug the project
### Launch
Launch the application using the launch.json file

### Get spotify tokens
Start the python server to get spotify tokens (must be in the project root folder):
```
python3 scripts/authorization.py
``` 
