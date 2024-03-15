#include "depthai/depthai.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
    // Define the pipeline
    dai::Pipeline pipeline;
    // Create nodes for a mono camera and XLinkOut
    auto monoCam = pipeline.create<dai::node::MonoCamera>();
    auto xoutMono = pipeline.create<dai::node::XLinkOut>();
    // Set properties for mono camera
    monoCam->setResolution(dai::MonoCameraProperties::SensorResolution::THE_720_P); // Example resolution
    monoCam->setBoardSocket(dai::CameraBoardSocket::CAM_B); // Choose LEFT or RIGHT mono camera
    // Set XLinkOut properties
    xoutMono->setStreamName("mono");
    monoCam->out.link(xoutMono->input);
    // Set the device information with the static IP address
    auto deviceInfo = dai::DeviceInfo("169.254.1.222");
//     auto deviceInfo = dai::DeviceInfo();
//     deviceInfo.desc.protocol = dai::XLinkProtocol::TCP_IP;
//     deviceInfo.desc.name = "169.254.1.222";
    // Try to connect to the specified device
    dai::Device device(pipeline, deviceInfo);
    try {
        //device = dai::Device(pipeline, deviceInfo);
        std::cout << "Successfully connected to the device!" << std::endl;
    } catch(const std::exception& e) {
        // std::cerr << "Failed to connect to the device at " << deviceInfo.desc.name << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    // Get the video stream
    auto videoQueue = device.getOutputQueue("mono", 8, false);
    // Create an OpenCV window
    cv::namedWindow("Mono Video", cv::WINDOW_AUTOSIZE);
    while(true) {
        // Get the frame
        auto frame = videoQueue->get<dai::ImgFrame>();
        if(frame) {
            // Convert the frame to a cv::Mat and display it
            cv::imshow("Mono Video", frame->getCvFrame());
            // Break out of the loop on user input
            int key = cv::waitKey(1);
            if(key == 'q' || key == 27) { // 'q' or ESC
                break;
            }
        }
    }
    return 0;
}

#if 0


#define WIDTH 640
#define HEIGHT 480

static void dumpHWFeatures(bool showAll = false)
{
    std::cout << "OpenCV's HW features list:" << std::endl;
    int count = 0;
    for (int i = 0; i < CV_HARDWARE_MAX_FEATURE; i++)
    {
        cv::String name = cv::getHardwareFeatureName(i);
        if (name.empty())
            continue;
        bool enabled = cv::checkHardwareSupport(i);
        if (enabled)
            count++;
        if (enabled || showAll)
        {
            printf("    ID=%3d (%s) -> %s\n", i, name.c_str(), enabled ? "ON" : "N/A");
        }
    }
    std::cout << "Total available: " << count << std::endl;

}


static uint8_t frameData[720 * 1280];


// Not sure if this is the best way to convert a cv::Mat to a uint8_t* array
static uint8_t* get8BitGreyscale(const cv::Mat& frame, cv::Mat& outputGray)
{
    // Ensure the output matrix is empty
    outputGray.release();

    // Convert the input frame to grayscale if it's not already
    if (frame.channels() == 3 || frame.channels() == 4) {
        cv::cvtColor(frame, outputGray, cv::COLOR_BGR2GRAY);
    }
    else {
        outputGray = frame.clone();
    }

    // Now, outputGray is an 8-bit single-channel image
    cv::Mat frameMat = outputGray;
    if (frameMat.rows * frameMat.cols > 720 * 1280) {
        return frameData;
    }

    for (int i = 0; i < frameMat.rows; i++) {
        for (int j = 0; j < frameMat.cols; j++) {
            frameData[i * frameMat.cols + j] = frameMat.at<uchar>(i, j);
        }
    }

    return frameData;
}

// OpenCV Video Capture
int main(int argc, char** argv) {

    int frameNo=0;

    cv::VideoCapture cap(0);

    dumpHWFeatures();

    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Unable to open the camera" << std::endl;
        return -1;
    }

    cv::Mat frame;

    cap >> frame;

    // If the frame is empty, skip this.
    if (!frame.empty()) {
        printf("Image width: %d, Image height: %d\n", frame.cols, frame.rows);
    }

    cv::Mat outputGray;

    while (true) {
        // Capture frame-by-frame from the camera
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // get8BitGreyscale(frame, outputGray);
        // Convert the frame to a cv::Mat
        cv::Mat frameMat = frame; // outputGray;

        // Display the resulting frame

        cv::imshow("Video", frameMat);
        
        // Wait for 1 ms until any key is pressed
        // If 'q' or 'Q' is pressed, break from the loop
        char key = (char)cv::waitKey(1);
        if (key == 'q' || key == 'Q')
            break;
    }

    // When everything done, release the video capture and close all the frames
    cap.release();
    cv::destroyAllWindows();

    return 0;
}

#endif