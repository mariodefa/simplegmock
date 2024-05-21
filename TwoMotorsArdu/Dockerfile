FROM mario-gtest:latest

RUN mkdir /myproject
WORKDIR /myproject
COPY . .
ENTRYPOINT ["tail", "-f", "/dev/null"]

# docker build -t tmotrs .