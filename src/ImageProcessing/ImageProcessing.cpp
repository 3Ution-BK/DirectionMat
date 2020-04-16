#include "ImageProcessing.h"

#include "opencv2/imgproc/imgproc.hpp"

#include <cassert>

namespace DirectionMat
{

namespace
{

void cartesianToPolar(const cv::Mat &mat, cv::Mat &magnitude, cv::Mat &angle);
void hsvToDirectionMat(const cv::Mat &hsv, cv::Mat &mat);
void polarToHsv(const cv::Mat &magnitude, const cv::Mat &angle, cv::Mat &hsv);

void cartesianToPolar(const cv::Mat &mat, cv::Mat &magnitude, cv::Mat &angle)
{
    assert(mat.channels() >= 2);

    std::vector<cv::Mat> channels(mat.channels());
    cv::split(mat, channels.data());

    cv::cartToPolar(channels[0], channels[1], magnitude, angle, true);
}

void hsvToDirectionMat(const cv::Mat &hsv, cv::Mat &mat)
{
    cv::Mat rgb;
    cv::cvtColor(hsv, rgb, cv::COLOR_HSV2BGR);

    rgb.convertTo(mat, CV_8U, 255, 0);
}

void polarToHsv(const cv::Mat &magnitude, const cv::Mat &angle, cv::Mat &hsv)
{
    assert(magnitude.size == angle.size);

    cv::Mat value;
    cv::normalize(magnitude, value, 1.0f, 0.0f, cv::NORM_MINMAX);
    cv::Mat saturation{cv::Mat::ones(magnitude.size(), magnitude.type())};

    cv::Mat channels[3] = {angle, saturation, value};

    cv::merge(channels, 3, hsv);
}

} // namespace

cv::Mat directionMat(const cv::Mat &mat)
{
    cv::Mat magnitude;
    cv::Mat angle;
    cartesianToPolar(mat, magnitude, angle);

    cv::Mat hsv;
    polarToHsv(magnitude, angle, hsv);

    cv::Mat image;
    hsvToDirectionMat(hsv, image);

    return image;
}

} // namespace DirectionMat
