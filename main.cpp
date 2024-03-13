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