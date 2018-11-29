#include <iostream>
#include <opencv2/opencv.hpp>
#include <rpc/client.h>

std::vector<unsigned char> buff;
cv::Mat image;

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

    while (true) {
        buff = client.call("capture").as<std::vector<unsigned char>>();
        image = cv::imdecode(buff, 1);

        cv::imshow("image", image);
        int key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
    }

    return 0;
}