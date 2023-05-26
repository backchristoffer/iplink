FROM gcc:latest
COPY . /app
WORKDIR /app
RUN gcc -o iplink iplink.c
CMD ["./iplink"]