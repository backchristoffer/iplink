FROM rhel8/gcc-toolset-12-toolchain
WORKDIR /app
USER root
RUN chown default .
USER default
COPY . /app
RUN gcc -o iplink iplink.c
CMD ["./iplink"]