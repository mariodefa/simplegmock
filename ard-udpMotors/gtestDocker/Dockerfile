FROM alpine:3.19.1

RUN apk add --no-cache -q -f git cmake make g++

RUN git clone -q https://github.com/google/googletest.git /googletest \
  && mkdir -p /googletest/build \
  && cd /googletest/build \
  && cmake .. && make && make install \
  && cd / && rm -rf /googletest

# docker build -t mario-gtest .