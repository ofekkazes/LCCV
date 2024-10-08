#include <lccv.hpp>
#include <libcamera_app_options.hpp>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image;
    lccv::PiCamera cam;
    //cam.options->width=4056;
    //cam.options->height=3040;
    cam.options->photo_width=1920;
    cam.options->photo_height=1080;
    cam.options->verbose=true;
    cam.options->gain = 2.0f;
    cam.options->shutter = 0.1f;
    cam.options->setWhiteBalance(WB_INDOOR);
    cam.capturePhoto(image);
    cv::rotate(image, image, cv::ROTATE_90_CLOCKWISE);
    cv::Mat denoised;
    cv::fastNlMeansDenoisingColored(image, denoised, 5, 5, 7, 21);
    imwrite("test.jpg", denoised);
}
