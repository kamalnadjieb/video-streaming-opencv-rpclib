#include <iostream>
#include <opencv2/opencv.hpp>
#include <rpc/server.h>
#include "custom_mat.h"


cv::VideoCapture cap;

int main(int argc, char *argv[]) {
    int port = rpc::constants::DEFAULT_PORT;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    cap.open(0);
    if(!cap.isOpened()) {
        return -1;
    }

    rpc::server srv(port);
    std::cout << "Start server at port " << port << std::endl;

    srv.bind("capture", []() {
        cv::Mat m;
        cap >> m;

        CustomMat cm;
        cm.rows = m.rows;
        cm.cols = m.cols;
        cm.type = m.type();

        int size = m.total() * m.elemSize();
        cm.data.resize(size);
        std::memcpy(&cm.data[0], m.data, size * sizeof(uchar));

        return cm;
    });

    srv.run();
    return 0;
}