// Programa 3. Hacer una operación sobre una imagen utilizando kernels, tal como detección de bordes

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "libprocesadoimagenes.h"


int main(){

    //Apertura de imagen
    ImageRGB img1 = load_ppm("image1.ppm");
    ImageRGB img1_padded;
    
    // Valida si la imagen es divisible entre 3
    if (img1.w % 3 != 0 || img1.h % 3 != 0) {
        // Si no es divisible, aumenta el padding
        int padding = 1;
        while (img1.w % 3 != 0 || img1.h % 3 != 0) {
            padding++;
            img1.w += 2 * padding;
            img1.h += 2 * padding;
        }

        // Llama a la función de padding
        img1_padded = add_padding(img1, padding);
        std::cout << "\nPadding aplicado correctamente..." << std::endl;
    } else {
        // Si es divisible, no hace nada
        img1_padded = img1;
    }
    
    // Conversión a escala de grises
    ImageGrayscale img1_grayscale_mean = to_grayscale_mean(img1_padded);
    
    // Despliegue de datos
    std::cout << "Imagen 1\nWidth: " << img1.w << "\t Height: " << img1.h << std::endl;

    std::cout << "Imagen 1 con padding (en caso de proceder)\nWidth: " << img1_padded.w << "\t Height: " << img1_padded.h << std::endl;


    // Aplicación de kernel sobel (guardado en cabecera)
    // Sobel horizontal
    ImageGrayscale img1_sobelx = apply_kernel(img1_grayscale_mean, sobel_x[0], 3, 0.2F, 1);
    // Sobel vertical
    ImageGrayscale img1_sobely = apply_kernel(img1_grayscale_mean, sobel_y[0], 3, 0.2F, 1);    
    // Suma de sobel_x y sobel_y
    ImageGrayscale img_sobel = add_pgm(img1_sobelx, img1_sobely);

    // Despliegue de info
    //display_image_info(img1_sobelx, "Sobel horizontal");
    //display_image_info(img1_sobely, "Sobel Vertical");
    //display_image_info(img_sobel, "Sobel Sumado");
    
    // Guardado
    // De primer imagen sobel
    if(save_pgm(img1_sobelx, "image1_sobelx.ppm") == true){
        std::cout << "\nImagen 'image1_sobelx.ppm' guardada correctamente" << std::endl;
    } else{
        std::cout << "\nError guardando la imagen" << std::endl;
    }

    // De segunda imagen sobel
    if(save_pgm(img1_sobely, "image1_sobely.ppm") == true){
        std::cout << "\nImagen 'image1_sobely.ppm' guardada correctamente" << std::endl;
    } else{
        std::cout << "\nError guardando la imagen" << std::endl;
    }
    
    // De sobel resultante
    
    if(save_pgm(img_sobel, "image1_sobel_added.ppm") == true){
        std::cout << "\nImagen 'image1_sobel_added.ppm' guardada correctamente" << std::endl;
    } else{
        std::cout << "\nError guardando la imagen" << std::endl;
    }
    /*
    // De imagen en blanco y negro   
    if(save_pgm(img1_grayscale_mean, "image1_grayscale_mean.pgm") == true){
        std::cout << "\nImagen 'image1_grayscale_mean.pgm' guardada correctamente" << std::endl;
    } else{
        std::cout << "\nError guardando la imagen" << std::endl;
    }
    */

    return 0;
}