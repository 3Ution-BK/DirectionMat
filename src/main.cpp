#include "CommandLineParser/CommandLineParser.h"
#include "ImageProcessing/ImageProcessing.h"

#include "opencv2/core.hpp"
#include "opencv2/core/mat.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

int main(int argc, char *argv[])
{
    DirectionMat::CommandLineParser parser{argc, argv};

    cv::Mat flow(parser.row(), parser.column(), CV_32FC2);

    cv::theRNG().state = cv::getTickCount();
    cv::randu(flow, -1, 1);

    cv::imwrite(parser.name(), DirectionMat::directionMat(flow));

    return 0;
}
