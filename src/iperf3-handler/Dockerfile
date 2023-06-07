FROM python:latest
WORKDIR /app
COPY ./src/iperf3_handler/* .
RUN pip install pipenv
RUN pipenv install
CMD ["pipenv", "run", "python", "iperf3-handler.py"]