#include <opencv2/opencv.hpp>

int main() {
    // 加载图像
    cv::Mat image = cv::imread("1.jpg");

    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // 显示原始图像
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    cv::destroyWindow("Original Image");

    // 检测图像边缘
    cv::Mat edges;
    cv::Canny(image, edges, 100, 200); // 调整阈值参数以获得所需的边缘
    cv::imshow("Edges", edges);
    cv::destroyWindow("Edges");

    // 膨胀操作
    cv::Mat dilated;
    cv::dilate(edges, dilated, cv::Mat(), cv::Point(-1, -1), 2, 1, 1); // 膨胀两次
    cv::imshow("Dilated", dilated);
    cv::waitKey(0);
    cv::destroyWindow("Dilated");

    // 侵蚀操作
    cv::Mat eroded;
    cv::erode(dilated, eroded, cv::Mat(), cv::Point(-1, -1), 1, 1, 1); // 侵蚀一次
    cv::imshow("Eroded", eroded);
    cv::waitKey(0);
    cv::destroyWindow("Eroded");

    // 缩放图像为原尺寸的50%
    cv::Mat resized;
    cv::resize(image, resized, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);
    cv::imshow("Resized", resized);
    cv::waitKey(0);
    cv::destroyWindow("Resized");

    return 0;
}
