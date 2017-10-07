#include "opencv.hpp"
using namespace cv;
using namespace std;
int main()
{
	int w = 0, h = 0;

	int Ynum = 385;
	int Nnum = 1275;
	String Y = "Y\\Y";
	String N = "N\\N";

	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(100);


	Mat srcImage = imread("cell_test.jpg");
	if (srcImage.empty())
		return -1;
	Mat srcImage2 = srcImage.clone();

	bool bEscKey = false;
	int nKey;
	while (!bEscKey)
	{
		Rect roi(w * 28, h * 28, 28, 28);
		rectangle(srcImage2, roi, Scalar(0, 255, 0));
		imshow("srcImage2", srcImage2);
		nKey = waitKey(0);
		switch (nKey)
		{
			
		case 27:
			bEscKey = true;
			break;
		case 'w':
			if (h > 0)
				h -= 1;
			break;
		case 'a':
			if (w > 0)
				w -= 1;
			break;
		case 's':
			if ((h + 2) <= srcImage.size().height / 28)
				h += 1;
			break;
		case 'd':
			if ((w + 2) <= srcImage.size().width / 28)
				w += 1;
			break;

		case 'Y':
		case 'y': {
			rectangle(srcImage2, roi, Scalar(255, 0, 0));
			cout << "Y" << endl;
			
			imshow("srcImage2", srcImage2);
			Mat dstImage = srcImage(roi);

			string tmp;
			tmp = std::to_string(Ynum);
			cv::String fileName = Y + tmp + ".jpg";
			Ynum++;

			imwrite(fileName, dstImage, params);

			if ((w + 2) <= srcImage.size().width / 28) {
				w++;

			}
			else if ((h + 2) <= srcImage.size().height / 28) {
				h++;
				w = 0;
			}
			else
				break;

			break;
		}	
		case 'N':
		case 'n':{
			rectangle(srcImage2, roi, Scalar(0, 0, 255));
			cout << "N" << endl;

			imshow("srcImage2", srcImage2);
			Mat dstImage = srcImage(roi);

			string tmp;
			tmp = std::to_string(Nnum);
			cv::String fileName = N + tmp + ".jpg";
			Nnum++;

			imwrite(fileName, dstImage, params);

			if ((w + 2) <= srcImage.size().width / 28) {
				w++;

			}
			else if ((h + 2) <= srcImage.size().height / 28) {
				h++;
				w = 0;
			}
			else
				break;
			
		}
		}
	}

}
	
