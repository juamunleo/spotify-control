FROM lscr.io/linuxserver/code-server:4.20.0
WORKDIR /work
ENV PUID=1000
ENV PGID=1000
ENV TZ=Etc/UTC
ENV PASSWORD=password
ENV SUDO_PASSWORD=password
ENV DEFAULT_WORKSPACE=/work
RUN sudo apt update
RUN sudo apt install -y build-essential gdb cmake python3 python3-pip
RUN sudo pip install flask requests