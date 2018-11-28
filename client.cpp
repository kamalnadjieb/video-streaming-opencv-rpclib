#include <iostream>
#include <opencv2/opencv.hpp>
#include <rpc/client.h>
#include "custom_mat.h"

int main(int argc, char *argv[]) {
    std::string addr = "127.0.0.1";
    int port = rpc::constants::DEFAULT_PORT;

    if (argc > 1) {
        addr = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    rpc::client client(addr, port);
    std::cout << "Start listening " << addr << ":" << port << std::endl;

    CustomMat cm;
    cv::Mat image;

    while (true) {
        cm = client.call("capture").as<CustomMat>();

        image = cv::Mat(cm.rows, cm.cols, cm.type, &cm.data[0], cv::Mat::AUTO_STEP);

        cv::imshow("image", image);
        int key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
    }

    return 0;
}