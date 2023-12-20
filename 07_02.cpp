#include <opencv2/opencv.hpp>

int main() {
    // 加载图像
    cv::Mat image = cv::imread("1.jpg");

    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // 显示原始图像并等待按键
    cv::imshow("Original Image", image);
    cv::waitKey(0);
    cv::destroyWindow("Original Image");

    // 将图像转换为灰度图
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    
    // 显示灰度图像并等待按键
    cv::imshow("Gray Image", grayImage);
    cv::waitKey(0);
    cv::destroyWindow("Gray Image");

    // 将灰度图像二值化
    cv::Mat thresholded;
    cv::threshold(grayImage, thresholded, 127, 255, cv::THRESH_BINARY);
    
    // 显示二值化图像并等待按键
    cv::imshow("Thresholded Image", thresholded);
    cv::waitKey(0);
    cv::destroyWindow("Thresholded Image");

    // 高斯模糊处理灰度图像
    cv::Mat blurred;
    cv::GaussianBlur(grayImage, blurred, cv::Size(5, 5), 0);
    
    // 显示高斯模糊图像并等待按键
    cv::imshow("Blurred Image", blurred);
    cv::waitKey(0);
    cv::destroyWindow("Blurred Image");

    return 0;
}