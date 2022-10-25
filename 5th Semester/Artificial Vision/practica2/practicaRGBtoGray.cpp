// Convertir RGB a Escala de grises 
// - Uso de funcion de opencv
// - Por promedio
// - Con algoritmo NTSC
// - Salidas de las 3 imagenes respectivamentes y a excel
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

// Gets the matrix address and the filename to save on the proyect folder the .csv file
void saveMatToCsv(Mat &matrix, string filename) {
	ofstream outputFile(filename);
	outputFile << format(matrix, cv::Formatter::FMT_CSV) << endl;
	outputFile.close();

	cout << "Archivo csv generado satisfactoriamente\n";
}
// Gets the original image and the void grayscale image, set the grayscaled image using average
void convertWithAverage(Mat& image, Mat& grayscale) {
	// Rows
	for (int i = 0; i < image.rows; i++) {
		// Cols
		for (int j = 0; j < image.cols; j++) {
			grayscale.at<uchar>(Point(i,j)) = (uchar)( (image.at<Vec3b>(Point(i,j)).val[0] + image.at<Vec3b>(Point(i,j)).val[1] + image.at<Vec3b>(Point(i,j)).val[2]) / 3);
		}
	}
}

// Gets the original image and the void grayscale image, set the grayscaled image using NTSC coefficients
void convertWithNTSC(Mat& image, Mat& grayscale) {
	// Rows
	for (int i = 0; i < image.rows; i++) {
		// Cols
		for (int j = 0; j < image.cols; j++) {
			grayscale.at<uchar>(Point(i, j)) = (uchar)( (0.299 * image.at<Vec3b>(Point(i, j)).val[0]) + (0.587 * image.at<Vec3b>(Point(i, j)).val[1]) + (0.11 * image.at<Vec3b>(Point(i, j)).val[2]) );
		}
	}
}

int main() {
	// Variables

	// Read the image and save it on a matrix
	string image_path = "C:/Users/aliki/Documents/VisionArtificial/lenna.png";
	Mat image = imread(image_path, IMREAD_COLOR);

	// Greyscale images
	Mat gray_function_image;										// Opencv function 
	Mat gray_average_image(image.rows, image.cols, CV_8UC1);		// Average
	Mat gray_NTSC_image(image.rows, image.cols, CV_8UC1);			// NTSC coefficients

	// Image convertion to Grayscale
	// Using opencv function
	cvtColor(image, gray_function_image, COLOR_BGR2GRAY);

	// Using average
	convertWithAverage(image, gray_average_image);
	
	// Using NTSC coefficients
	convertWithNTSC(image, gray_NTSC_image);


	// Output
	imshow("Original image", image);
	imshow("Grayscale function image", gray_function_image);
	imshow("Grayscale averaged image", gray_average_image);
	imshow("Grayscale NTSC coefficient image", gray_NTSC_image);

	// CSV color
	saveMatToCsv(image, "matriz_original.csv");

	// CSV function grayscale
	saveMatToCsv(gray_function_image, "matriz_funcion_escalagrises.csv");

	// CSV average grayscale
	saveMatToCsv(gray_average_image, "matriz_promedio_escalagrises.csv");

	// CSV NTSC coefficient grayscale
	saveMatToCsv(gray_NTSC_image, "matriz_NTSC_escalagrises.csv");

	// Save all the images
	imwrite("original.jpg", image);
	imwrite("imagen_funcion_escalagrises.jpg", gray_function_image);
	imwrite("imagen_promedio_escalagrises.jpg", gray_average_image);
	imwrite("imagen_NTSC_escalagrises.jpg", gray_NTSC_image);


	waitKey(0);
	
	return 0;


}