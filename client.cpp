#include <opencv2/opencv.hpp>
#include <rpc/client.h>
#include "custom_mat.h"

int main(int argc, char *argv[]) {
    rpc::client client("127.0.0.1", rpc::constants::DEFAULT_PORT);

    while (true) {
        CustomMat cm = client.call("capture").as<CustomMat>();

        cv::Mat image(cm.rows, cm.cols, cm.type, &cm.data[0], cv::Mat::AUTO_STEP);

        cv::imshow("image", image);
        int key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
    }

    return 0;
}