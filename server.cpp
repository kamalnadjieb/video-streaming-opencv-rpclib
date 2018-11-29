#include <iostream>
#include <opencv2/opencv.hpp>
#include <rpc/server.h>

cv::VideoCapture cap;
cv::Mat image;
std::vector<unsigned char> buff;

int main(int argc, char *argv[]) {
    int index;
    int port = rpc::constants::DEFAULT_PORT;

    if (argc > 1) {
        index = atoi(argv[1]);
    } else {
        std::cout << "usage: ./server <camera_index> <addr_port default 8080>" << std::endl;
        exit(1);
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    cap.open(index);
    if (!cap.isOpened()) {
        std::cout << "Can't open camera by index " << index << std::endl;
        exit(1);
    }
    std::cout << "Open camera by index " << index << std::endl;

    rpc::server srv(port);
    std::cout << "Start server at port " << port << std::endl;

    srv.bind("capture", []() {
        cap >> image;

        std::vector<int> param(2);
        param[0] = cv::IMWRITE_JPEG_QUALITY;
        param[1] = 80;//default(95) 0-100
        cv::imencode(".jpg", image, buff, param);

        return buff;
    });

    srv.run();

    return 0;
}