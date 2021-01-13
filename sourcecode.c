#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Compile with g++ code.cpp -lopencv_core -lopencv_highgui -lopencv_imgproc

int main()
{
    cv::Mat src = cv::imread("im.png", CV_LOAD_IMAGE_UNCHANGED);
    cv::Mat dst;

    cv::Point2f pc(src.cols/2., src.rows/2.);
    cv::Mat r = cv::getRotationMatrix2D(pc, -45, 1.0);

    cv::warpAffine(src, dst, r, src.size()); // what size I should use?

    cv::imwrite("rotated_im.png", dst);

    return 0;
}
