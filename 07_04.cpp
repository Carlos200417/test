#include <opencv2/opencv.hpp>

// 用于存储原始图像和调整后的图像
cv::Mat originalImage;
cv::Mat adjustedImage;

// 初始化亮度和对比度值为50
int brightnessValue = 50;
int contrastValue = 50;

// 更新图像函数
void updateImage() {
    // 计算 alpha 和 beta 参数
    double alpha = contrastValue / 50.0;
    int beta = brightnessValue - 50;

    // 调整图像亮度和对比度
    originalImage.convertTo(adjustedImage, -1, alpha, beta);
    
    // 在窗口中显示调整后的图像
    cv::imshow("Image", adjustedImage);
}

// 亮度滑动条回调函数
void onBrightnessTrackbar(int value, void* userdata) {
    // 更新亮度值并重新调整图像
    brightnessValue = value;
    updateImage();
}

// 对比度滑动条回调函数
void onContrastTrackbar(int value, void* userdata) {
    // 更新对比度值并重新调整图像
    contrastValue = value;
    updateImage();
}

int main() {
    // 加载图像
    originalImage = cv::imread("1.jpg");

    if (originalImage.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    
    // 克隆原始图像用于显示调整后的图像
    adjustedImage = originalImage.clone();

    // 创建窗口并显示原始图像
    cv::namedWindow("Image");
    cv::imshow("Image", adjustedImage);

    // 创建亮度滑动条并绑定回调函数
    cv::createTrackbar("Brightness", "Image", &brightnessValue, 100, onBrightnessTrackbar);

    // 创建对比度滑动条并绑定回调函数
    cv::createTrackbar("Contrast", "Image", &contrastValue, 100, onContrastTrackbar);

    // 等待按键事件
    cv::waitKey(0);
    return 0;
}
