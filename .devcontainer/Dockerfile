FROM ubuntu:20.04
WORKDIR /toolchain
RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt install -y build-essential git gdb wget python3 python3-pip libncurses5
RUN pip install cmake
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-aarch64-linux.tar.bz2
RUN tar -xvf gcc-arm-none-eabi-10.3-2021.10-aarch64-linux.tar.bz2
RUN mv gcc-arm-none-eabi-10.3-2021.10 gnu-arm
RUN rm gcc-arm-none-eabi-10.3-2021.10-aarch64-linux.tar.bz2