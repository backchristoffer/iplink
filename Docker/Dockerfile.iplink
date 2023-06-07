FROM centos/devtoolset-7-toolchain-centos7
WORKDIR /app
USER root
RUN yum -y install net-tools iproute
RUN chown default .
USER default
COPY . /app
RUN gcc -pthread -o iplink src/iplink.c
CMD ["./iplink"]