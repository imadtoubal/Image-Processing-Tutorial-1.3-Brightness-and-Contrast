#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    // Make sure the commandline arguments are correct
    if (argc < 4)
    {
        std::cout << "Usage:\n\t./brightness intensity_value input_image_filename output_image_filename" << std::endl;
        return 1;
    }
    int16_t intensityValue = std::stoi(argv[1]);
    std::string inpImagePath = argv[2];
    std::string outImagePath = argv[3];

    // Read the image
    cv::Mat image = cv::imread(inpImagePath, 0);
    int H = image.size[0];
    int W = image.size[1];

    // Initialize an empty grayscale image (8-bit unsigned integer matrix with one channel)
    cv::Mat outputImage(H, W, CV_8UC1);

    // Loop through the pixels of the image
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            // Retrieve the pixel from location (r, c)
            cv::uint8_t pix = image.at<cv::uint8_t>(r, c);

            // Add intensity and clip to 0-255
            int res = (int) pix + intensityValue;
            if (res > 255)
            {
                outputImage.at<uint8_t>(r, c) = 255;
            }
            else if (res < 0)
            {
                outputImage.at<uint8_t>(r, c) = 0;
            }
            else
            {
                outputImage.at<uint8_t>(r, c) = res;
            }
        }
    }

    // Show original and grayscale images
    cv::imshow("Image", image);
    cv::imshow("OutputImage", outputImage);

    // Save the image to the output location
    cv::imwrite(outImagePath, outputImage);

    // Wait for keyboard input to close imshow windows
    cv::waitKey(0);
    return 0;
}
