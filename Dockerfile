FROM ubuntu:latest

RUN apt-get -y update && apt-get -y install gcc libcurl4-openssl-dev

COPY main.c /opt/

RUN gcc /opt/main.c -lcurl -o push
