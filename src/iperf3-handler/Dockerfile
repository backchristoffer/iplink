FROM python:latest
WORKDIR /app
COPY ./src/iperf3-handler/. .
RUN pip install pipenv
RUN pipenv install
CMD ["pipenv", "run", "python", "iperf3-handler.py"]