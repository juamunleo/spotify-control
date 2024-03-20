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

### Start ST-Link server
Start the ST-Link GDB server to debug the code in a physical board.
```
<ST-LINK GDB LOCATION> -p 61234 -l 1 -d -s -cp <CUBE PROGRAMMER LOCATION> -m 0 -k
```
Example:
```
/Applications/STM32CubeIDE.app/Contents/Eclipse/plugins/com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.macos64_2.1.0.202305091550/tools/bin/ST-LINK_gdbserver -p 61234 -l 1 -d -s -cp /Applications/STM32CubeIDE.app/Contents/Eclipse/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.macos64_2.1.0.202305091550/tools/bin -m 0 -k
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