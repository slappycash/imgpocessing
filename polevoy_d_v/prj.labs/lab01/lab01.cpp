#include <opencv2/opencv.hpp>
#include <cmath>
#include <iostream>
int main() {
	cv::Mat img(180, 768, CV_8UC1);
	cv::Mat img3(180, 768, CV_8UC1);
	cv::Mat img1(180, 768, CV_8UC1);
	// draw dummy image
	/*img = 0;
	cv::Rect2d rc = {0, 0, 768, 60 };
	cv::rectangle(img, rc, { 100 }, 1);
	rc.y += rc.height;
	cv::rectangle(img, rc, { 250 }, 1);
	rc.y += rc.height;
	cv::rectangle(img, rc, { 150 }, 1);*/
	for (size_t j = 0; j < 180; j++)
	{
		for (size_t i = 0; i < 768; i += 3)
		{
			img.at<uint8_t>(j, i) = i / 3;

			img.at<uint8_t>(j, i + 1) = i / 3;
			img.at<uint8_t>(j, i + 2) = i / 3;

		}
	}
	float st = clock();

	img.convertTo(img1, CV_32F, 1 / 255.0);
	cv::pow(img1, 2.4, img1);
	img1.convertTo(img1, CV_8UC1, 255);

	float timeResult = clock() - st;
	float st1 = clock();
	for (size_t j = 0; j < 180; j++)
	{
		for (size_t i = 0; i < 768; i += 3)
		{
			img3.at<uint8_t>(j, i) = pow((int)(i / 3) / 255.0, 2.4) * 255;

			img3.at<uint8_t>(j, i + 1) = pow((int)(i / 3) / 255.0, 2.4) * 255;
			img3.at<uint8_t>(j, i + 2) = pow((int)(i / 3) / 255.0, 2.4) * 255;

		}
	}
	float timeRuslt1 = clock() - st1;
	cv::Mat result(180, 768, CV_8UC1);
	cv::Mat threeImages(180, 768, CV_8UC1);
	cv::Rect2d rc(0, 0, 768, 60);
	cv::Rect2d rc1(0, 0, 768, 60);
	img(rc).copyTo(result(rc1));
	cv::rectangle(result, rc1, { 100 }, 1);
	rc1.y += 60;
	img1(rc).copyTo(result(rc1));
	cv::rectangle(result, rc1, { 250 }, 1);
	rc1.y += rc.height;
	img3(rc).copyTo(result(rc1));
	cv::rectangle(result, rc1, { 350 }, 1);
	cv::imwrite("lab03.png", result);
	cv::imshow("lab03.png", result);
	std::cout << timeResult << " ms";
	std::cout << '\n';


	std::cout << timeRuslt1 << " ms";

	cv::waitKey(0);





}