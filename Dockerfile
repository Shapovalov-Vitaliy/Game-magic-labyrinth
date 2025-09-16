FROM debian:12-slim

ADD *.cpp .
ADD *.h .

RUN apt-get update
RUN apt-get install -y g++
RUN g++ Character.cpp Field.cpp Game.cpp -o game

ENTRYPOINT ["./game"]