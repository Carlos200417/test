#include <opencv2/opencv.hpp>

int main() {
    bool showImage = true;
    bool showVideo = false;
    bool showCamera = false;

    // 加载并显示图像
    cv::Mat image = cv::imread("1.jpg");
    cv::imshow("Image", image);

    while (true) {
        if (showImage) {
            int key = cv::waitKey(0);
            if (key == 27) {  // 当按下 Esc 键时退出图像窗口
                showImage = false;
                showVideo = true;
                cv::destroyAllWindows();
            }
        } else if (showVideo) {
            cv::VideoCapture video("2.mp4");

            if (!video.isOpened()) { //识别：视频没有被正确打开
                std::cout << "Error opening video file" << std::endl;
                return -1;
            }

            cv::Mat frame;
            while (true) {
                int key = cv::waitKey(1);
                if (key == 27) {  // 当按下 Esc 键时退出视频窗口
                    cv::destroyAllWindows();
                    break;
                }
                if (!video.read(frame)) { //识别：如果没有读到视频的帧率
                    break;
                }
                cv::imshow("Video", frame);
            }

            showVideo = false;
            showCamera = true;
        } else if (showCamera) {
            cv::VideoCapture camera(0); 

            if (!camera.isOpened()) {
                std::cout << "Error opening camera" << std::endl;
                return -1;
            }

            cv::Mat frame;
            while (true) {
                int key = cv::waitKey(1);
                if (key == 27) {  // 当按下 Esc 键时退出摄像头窗口
                    cv::destroyAllWindows();
                    break;
                }
                if (!camera.read(frame)) {
                    break;
                }
                cv::imshow("Camera", frame);
            }

            showCamera = false;
            showImage = true;
        }
    }

    return 0;
}
