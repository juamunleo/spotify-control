# Spotify Player Control

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

## Build the project
### Desktop platform
```
rm -rf ./build && cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Debug -DDESKTOP=ON -DREAD_ENV_FILE=TRUE && cmake --build ./build
```

### Embedded platform
```
rm -rf ./build && cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake -DEMBEDDED=ON -DREAD_ENV_FILE=TRUE && cmake --build ./build
```