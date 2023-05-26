FROM rhel8/gcc-toolset-12-toolchain
WORKDIR /app
USER root
RUN yum -y install net-tools iproute
RUN yum -y libmicrohttpd libjansson libgnutls libcurl libsystemd zlib
RUN chown default .
USER default
COPY . /app
RUN gcc -o iplink iplink.c
CMD ["./iplink"]