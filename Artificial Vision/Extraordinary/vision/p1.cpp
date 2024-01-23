// Programa 1.
// Hecho por García King Ricardo Neftaly 5BV1
// Abrir una imagen y hacer operacion entre imagenes

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "libprocesadoimagenes.h"

int main() {
    // Apertura de imagenes
    ImageRGB img1 = load_ppm("image1.ppm");
    ImageRGB img2 = load_ppm("imagen2.ppm");


    // Padding de imagenes 
    ImageRGB img1_padded = add_square_padding(img1);
    save_ppm(img1_padded, "img1_padded.ppm");
    ImageGrayscale img1_grayscale = to_grayscale_coefficients(img1);
    save_pgm(img1_grayscale, "imagen1grayscale.pgm");

    ImageRGB img2_padded = add_square_padding(img2);
    save_ppm(img2_padded, "img2_padded.ppm");
    ImageGrayscale img2_grayscale = to_grayscale_mean(img2);
    save_pgm(img2_grayscale, "imagen2grayscale.pgm");


    // Suma de imagenes
    ImageRGB img_res = add_ppm(img1_padded, img2_padded);

    save_ppm(img_res, "img_res.ppm");



    // Debug
    //std::cout << "Datos de imagen con padding: " << "\nWidth: " << img1_padded.w << "\nHeight: " << img1_padded.h << std::endl;
    //std::cout << "Datos de imagen 1: " << "\nWidth: " << img1.w << "\nHeight: " << img1.h << "\nDatos: " << std::endl;
    //for(int i = 0; i <= img1.data.size(); i++)
    //    std::cout << test[i] << std::endl;

    //std::cout << "\nDatos de imagen 2: " << "\nWidth: " << img2.w << "\nHeight: " << img2.h << std::endl;
    //std::cout << "\nDatos de imagen resultante: " << "\nWidth: " << img_res.w << "\nHeight: " << img_res.h << std::endl;


    return 0;
}
