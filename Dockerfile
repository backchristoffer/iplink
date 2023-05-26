FROM rhel8/gcc-toolset-12-toolchain
COPY . /app
WORKDIR /app
RUN gcc -o iplink iplink.c
CMD ["./iplink"]