# Video Streaming with OpenCV and rpclib

## Prerequisites
* A modern C/C++ compiler
* [OpenCV 3.4 or later](https://www.learnopencv.com/install-opencv-3-4-4-on-ubuntu-16-04/)
* [rpclib](https://github.com/rpclib/rpclib)

## Build Project

```bash
git clone https://github.com/kamalnadjieb/video-streaming-opencv-rpclib.git
cd video-streaming-opencv-rpclib
mkdir build
cd build
cmake ..
make
```

## Run Server
```bash
./server <port default 8080>
```

## Run Client
```bash
./client <addr default 127.0.0.1> <port default 8080>
```