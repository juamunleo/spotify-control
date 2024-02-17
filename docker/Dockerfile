FROM ubuntu:24.04
WORKDIR /toolchain
RUN apt update
RUN apt install -y build-essential gdb cmake python3 python3-pip python3-flask python3-requests git wget flex bison gperf python3-venv ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
RUN git clone --recursive https://github.com/espressif/esp-idf.git
WORKDIR /toolchain/esp-idf
RUN ./install.sh esp32
RUN . ./export.sh