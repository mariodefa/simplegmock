FROM mario-gtest:latest

RUN mkdir /myproject
WORKDIR /myproject
COPY . .
# setup config project
RUN cmake -S . -B build
# compile project's tests
RUN cmake --build build
# ENTRYPOINT [ "cd build && ctest" ]
ENTRYPOINT ["tail", "-f", "/dev/null"]

# docker build -t tmotrs .