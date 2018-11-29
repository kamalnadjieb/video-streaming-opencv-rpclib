#include <vector>
#include <rpc/msgpack.hpp>

struct CustomMat {
    int rows;
    int cols;
    int type;
    std::vector<unsigned char> data;
    MSGPACK_DEFINE_ARRAY(rows, cols, type, data)
};
