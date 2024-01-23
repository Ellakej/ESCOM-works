#include <iostream>
#include <string>
#include <cmath>

// Cabecera imagenes ppm: 
// No. mágico
// w = width
// h = height
// Máx color value (generalmente 255)


// No. Mágico
// P1, P4 = bitmap      PBM (portable bitmap)
// P2, P5 = grayscale   PGM (portable graymap)
// P3, P6 = fullcolor   PPM (portable pixmap)


// Estructuras útiles
// Estructura RGB
struct RGB {
    unsigned char r, g, b;
};
struct ImageRGB {
    int w, h;
    std::vector<RGB> data;
};
// Estructura escala de grises
struct Grayscale {
    float value;
};
struct ImageGrayscale {
    int w;
    int h;
    std::vector<Grayscale> data;
};
// Estructura bitmap
struct ImagePBM {
  int w;
  int h;
  std::vector<bool> data;
  //std::vector<uint8_t> data;       

};

// Estructura de perceptrones



// Kernels de Sobel
const float sobel_x[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

const float sobel_y[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

// Funciones
// IO
// Carga de imagenes
// Carga de imagen ppm
ImageRGB load_ppm(const std::string& name) {
    ImageRGB img;
    std::ifstream f(name, std::ios::binary);

    // Validador
    if (!f.is_open()) {
        std::cerr << "No se puede abrir la imagen: " << name << std::endl;
        return img;
    }

    // Número mágico solo para imágenes a color (ppm)
    std::string magic;
    f >> magic;
    // PPM = P3 y P6
    if ((magic != "P6") && (magic != "P3")) {
        std::cerr << "Número mágico no soportado: " << magic << std::endl;
        f.close();
        return img;
    }

    // Leer comentarios (líneas que comienzan con '#')
    char ch = f.peek();
    while (ch == '#' || ch == '\n' || ch == '\r') {
        std::string line;
        std::getline(f, line);
        ch = f.peek();
    }

    // Leer dimensiones y valor máximo
    f >> img.w >> img.h;
    int max_val;
    f >> max_val;

    // Validador de parámetros w, h y max value
    if (img.w <= 0 || img.h <= 0 || max_val != 255) {
        std::cerr << "Dimensiones de imagen o valor máximo inválido" << std::endl;
        f.close();
        return img;
    }

    // Consumir el carácter de nueva línea después del valor máximo
    f.get();

    // Redimensionar el vector de datos y leer los píxeles directamente
    img.data.resize(img.w * img.h);
    f.read(reinterpret_cast<char*>(img.data.data()), img.data.size() * sizeof(RGB));

    f.close();

    return img;
}
// Carga de imagenes PBM
// Función para cargar un archivo PBM
ImagePBM load_pbm(const std::string& ruta) {
  // Abrir el archivo
  std::ifstream archivo(ruta);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo '" << ruta << "'" << std::endl;
    return ImagePBM();
  }

  // Leer la cabecera
  std::string cabecera;
  std::getline(archivo, cabecera);
  
  
  // PBM = P1 y P4
  if ((cabecera != "P1") && (cabecera != "P4")) {
    std::cerr << "El archivo '" << ruta << "' no es un archivo PBM" << std::endl;
    return ImagePBM();
  }

  // Leer el ancho y alto de la imagen
  int ancho, alto;
  archivo >> ancho >> alto;

  // Leer los datos de la imagen
  std::vector<bool> datos;
  for (int i = 0; i < ancho * alto; i++) {
    bool pixel;
    archivo >> pixel;
    datos.push_back(pixel);
  }

  // Cerrar el archivo
  archivo.close();

  // Crear la imagen
  ImagePBM imagen;
  imagen.w = ancho;
  imagen.h = alto;
  imagen.data.resize(ancho*alto);

  // Relleno de datos al objeto ImagePBM
  for (int i = 0; i < ancho * alto; i++) {
    imagen.data[i] = datos[i];
  }

  return imagen;
}


// Lee un archivo JPG y devuelve una imagen RGB.
ImageRGB readJPG(const std::string& filename) {

    // Abre el archivo en modo binario.
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        // Error al abrir el archivo.
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
        return ImageRGB();
    }

    // Lee el encabezado.
    char header[2];
    file.read(header, sizeof(header));
    if (!file.good()) {
        // Error al leer el encabezado.
        std::cerr << "Error reading header from file " << filename << std::endl;
        return ImageRGB();
    }

    // Comprueba que el archivo es un JPG válido.
    // Los dos primeros bytes del encabezado de un archivo JPG deben ser 0xFF y 0xD8.
    if (static_cast<unsigned char>(header[0]) != 0xFF ||
        static_cast<unsigned char>(header[1]) != 0xD8) {
        // El archivo no es un JPG válido.
        std::cerr << "El archivo " << filename << " no es un JPG válido" << std::endl;
        return ImageRGB();
    }

    // Lee el tamaño del archivo.
    unsigned int fileSize;
    file.read(reinterpret_cast<char*>(&fileSize), sizeof(fileSize));

    // Lee el resto del archivo.
    char buffer[256];
    int width, height, channels;
    file.read(buffer, 2);
    width = buffer[0] << 8 | buffer[1];
    file.read(buffer, 2);
    height = buffer[0] << 8 | buffer[1];
    file.read(buffer, 1);
    channels = buffer[0];

    // Crea una imagen RGB con el tamaño leído.
    ImageRGB image;
    image.w = width;
    image.h = height;
    image.data.resize(width * height * channels);

    // Lee los datos de la imagen.
    for (int i = 0; i < image.data.size(); i++) {
        file.read(buffer, 3);
        image.data[i].r = buffer[0];
        image.data[i].g = buffer[1];
        image.data[i].b = buffer[2];
    }

    // Cierra el archivo.
    file.close();

    // Devuelve la imagen.
    return image;
}

// Guardado de imagenes
// Guardado PPM, Portable pixel map, permite guardar imagenes en color usando RGB
bool save_ppm(const ImageRGB& img, const std::string& name) {
    std::ofstream f(name, std::ios::binary);

    // Validador
    if (!f.is_open()) {
        std::cerr << "No se puede crear la imagen: " << name << std::endl;
        return false;
    }

    // Relleno de datos
    // Cabecera        
    f << "P6" << std::endl;                                                     // No. mágico
    f << img.w << " " << img.h << std::endl;                                    // Tamaño de la imagen
    f << "255" << std::endl;                                                    // Máximo valor de color

    // Conversión de datos a char antes de escribirlos
    for (const RGB& pixel : img.data) {
        f.put(static_cast<char>(pixel.r));
        f.put(static_cast<char>(pixel.g));
        f.put(static_cast<char>(pixel.b));
    }

    f.close();

    return true;
}
// Guardado PGM, Portable GrayMap, permite guardar imagenes en formato de escala de grises
bool save_pgm(const ImageGrayscale& img, const std::string& name) {
    std::ofstream f(name, std::ios::binary);

    // Validador
    if (!f.is_open()) {
        std::cerr << "No se puede crear la imagen: " << name << std::endl;
        return false;
    }

    // Cabecera
    f << "P5" << std::endl;
    f << img.w << " " << img.h << std::endl;
    f << "255" << std::endl;

    // Escritura de datos
    for (const Grayscale& pixel : img.data) {
        f.put(static_cast<char>(pixel.value));
    }

    f.close();

    return true;
}

// Utilidades
// Suma de 2 ppm, (imagenes a color RGB)
ImageRGB add_ppm(const ImageRGB& img1, const ImageRGB& img2) {
    // Verifica que las imágenes tengan el mismo tamaño
    if (img1.w != img2.w || img1.h != img2.h) {
        std::cerr << "Las imágenes deben tener el mismo tamaño" << std::endl;
        ImageRGB();
    }

    // Crea una nueva imagen para almacenar la suma
    ImageRGB sum;
    sum.w = img1.w;
    sum.h = img1.h;
    sum.data.resize(img1.w * img1.h);

    // Suma los píxeles de las dos imágenes
    for (int i = 0; i < img1.data.size(); i++) {
        RGB p1 = img1.data[i];
        RGB p2 = img2.data[i];

        sum.data[i].r = p1.r * p2.r;
        sum.data[i].g = p1.g * p2.g;
        sum.data[i].b = p1.b * p2.b;
    }
    
    return sum;
}

// Suma de 2 pgm (imagenes en escala de grises)
ImageGrayscale add_pgm(const ImageGrayscale& img1, const ImageGrayscale& img2) {
    // Check for size compatibility
    if (img1.w != img2.w || img1.h != img2.h) {
        std::cerr << "Images must have the same size" << std::endl;
        return ImageGrayscale();
    }

    // Create the result image
    ImageGrayscale sum;
    sum.w = img1.w;
    sum.h = img1.h;
    sum.data.resize(img1.w * img1.h);

    // Add pixel values
    for (int i = 0; i < img1.data.size(); i++) {
        sum.data[i].value = img1.data[i].value + img2.data[i].value;
    }

    return sum;
}

// Padding cuadrado
ImageRGB add_square_padding(const ImageRGB& img) {
    int max_size = std::max(img.w, img.h);
    int pad_x = (max_size - img.w) / 2;
    int pad_y = (max_size - img.h) / 2;

    ImageRGB img_padded;
    img_padded.w = max_size;
    img_padded.h = max_size;
    img_padded.data.resize(img_padded.w * img_padded.h);
    
    // Agrega padding a la imagen
    for (int i = 0; i < img_padded.h; i++) {  // Cambio en el límite del bucle
        for (int j = 0; j < img_padded.w; j++) {  // Cambio en el límite del bucle
            int x = j - pad_x;
            int y = i - pad_y;

            if (x >= 0 && x < img.w && y >= 0 && y < img.h) {
                img_padded.data[i*img_padded.w+j] = img.data[y*img.w+x];  // Corrección aquí
            } else {
                img_padded.data[i*img_padded.w+j].r = 0;
                img_padded.data[i*img_padded.w+j].g = 0;
                img_padded.data[i*img_padded.w+j].b = 0;
            }
        }
    }

    return img_padded;
}
// Función para agregar padding a una imagen
ImageRGB add_padding(const ImageRGB& img, int padding) {
    // Obtiene el tamaño de la imagen original
    int w = img.w;
    int h = img.h;

    // Calcula el tamaño de la imagen con padding
    int padded_w = w + 2 * padding;
    int padded_h = h + 2 * padding;

    // Crea una nueva imagen para almacenar la imagen con padding
    ImageRGB padded_img;
    padded_img.w = padded_w;
    padded_img.h = padded_h;
    padded_img.data.resize(padded_w * padded_h);

    // Agrega padding a la imagen
    for (int i = 0; i < padded_h; i++) {
        for (int j = 0; j < padded_w; j++) {
            // Obtiene la posición del píxel original
            int x = j - padding;
            int y = i - padding;

            // Si el píxel original está dentro de la imagen, copia su valor
            if (x >= 0 && x < w && y >= 0 && y < h) {
                padded_img.data[i * padded_w + j] = img.data[y * w + x];
            } else {
                // Si el píxel original está fuera de la imagen, lo establece en 0
                padded_img.data[i * padded_w + j].r = 0;
                padded_img.data[i * padded_w + j].g = 0;
                padded_img.data[i * padded_w + j].b = 0;
            }
        }
    }

    return padded_img;
}
// Conversión a escala de grises mediante promedio
ImageGrayscale to_grayscale_mean(const ImageRGB& img) {
    // Crea una nueva imagen en escala de grises
    ImageGrayscale img_grayscale;
    img_grayscale.w = img.w;
    img_grayscale.h = img.h;
    img_grayscale.data.resize(img.w * img.h);

    // Convierte cada píxel a escala de grises
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            // Promedio de los componentes RGB
            float gray = (img.data[i * img.w + j].r + img.data[i * img.w + j].g + img.data[i * img.w + j].b) / 3.0f;

            // Asigna el valor de escala de grises al píxel
            img_grayscale.data[i * img_grayscale.w + j].value = gray;
        }
    }

    return img_grayscale;
}
// Conversión a escala de grises mediante coeficientes
ImageGrayscale to_grayscale_coefficients(const ImageRGB& img) {
    // Crea una nueva imagen en escala de grises
    ImageGrayscale img_grayscale;
    img_grayscale.w = img.w;
    img_grayscale.h = img.h;
    img_grayscale.data.resize(img.w * img.h);

    // Coeficientes de conversión a escala de grises
    const float coefficients[3] = {0.2989, 0.5870, 0.1140};

    // Convierte cada píxel a escala de grises
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            // Calcula el valor de escala de grises
            float gray = coefficients[0] * img.data[i * img.w + j].r + coefficients[1] * img.data[i * img.w + j].g + coefficients[2] * img.data[i * img.w + j].b;

            // Asigna el valor de escala de grises al píxel
            img_grayscale.data[i * img.w + j].value = gray;
        }
    }

    return img_grayscale;
}

// Aplicación de kernel a imagen RGB
/*
ImageRGB apply_kernel(const ImageRGB& img, const float* kernel, int kernel_size) {
    // Crea una nueva imagen para almacenar el resultado
    ImageRGB result;
    result.w = img.w;
    result.h = img.h;
    result.data.resize(result.w * result.h);

    // Aplica el kernel a cada píxel de la imagen
    for (int i = 0; i < img.h; i++) {
        for (int j = 0; j < img.w; j++) {
            // Obtiene el valor del píxel actual
            float sum_r = 0.0f;
            float sum_g = 0.0f;
            float sum_b = 0.0f;
            // Iteracion de kernel, convolucion
            for (int k = 0; k < kernel_size; k++) {
                for (int l = 0; l < kernel_size; l++) {
                    // Centrado del kernel, calcula las coordenadas para centrar el kernel sobre el pixel actual
                    int x = j + l - (kernel_size / 2);
                    int y = i + k - (kernel_size / 2);

                    // Checa limites
                    if (x >= 0 && x < img.w && y >= 0 && y < img.h) {
                        // Accede a los componentes RGB del píxel y los multiplica por separado
                        // Multiplicación y acomulación de la convolución
                        sum_r += img.data[y * img.w + x].r * kernel[k * kernel_size + l];
                        sum_g += img.data[y * img.w + x].g * kernel[k * kernel_size + l];
                        sum_b += img.data[y * img.w + x].b * kernel[k * kernel_size + l];
                    }
                }
            }

            // Actualiza el valor del píxel resultante
            // Almacena la salida de la convolución
            result.data[i * result.w + j].r = sum_r;
            result.data[i * result.w + j].g = sum_g;
            result.data[i * result.w + j].b = sum_b;
        }
    }

    return result;
}
*/
template <typename T>
T apply_kernel(const T& img, const float* kernel, int kernel_size, float k = 1.0f, float offset = 0.0f) {
   // Crea una nueva imagen para almacenar el resultado
   T result;
   result.w = img.w;
   result.h = img.h;
   result.data.resize(result.w * result.h);

   // Aplica el kernel a cada píxel de la imagen
   for (int i = 0; i < img.h; i++) {
       for (int j = 0; j < img.w; j++) {
           // Obtiene el valor del píxel actual
           float sum = 0.0f;  // Acumulador para RGB o escala de grises

           // Iteración del kernel, convolución
           for (int ki = 0; ki < kernel_size; ki++) {
               for (int li = 0; li < kernel_size; li++) {
                   // Centrado del kernel
                   int x = j + li - (kernel_size / 2);
                   int y = i + ki - (kernel_size / 2);

                   // Checa límites
                   if (x >= 0 && x < img.w && y >= 0 && y < img.h) {
                       // Acceso y multiplicación según el tipo de imagen
                       if constexpr (std::is_same_v<T, ImageRGB>) {
                           // Accede a los componentes RGB y multiplica por separado
                           sum += img.data[y * img.w + x].r * kernel[ki * kernel_size + li] * k;
                           sum += img.data[y * img.w + x].g * kernel[ki * kernel_size + li] * k;
                           sum += img.data[y * img.w + x].b * kernel[ki * kernel_size + li] * k;
                       } else {  // ImageGrayscale
                           sum += img.data[y * img.w + x].value * kernel[ki * kernel_size + li] * k;
                       }
                   }
               }
           }

           // Aplica el factor k y el offset
           sum *= k;
           sum += offset;

           // Actualiza el valor del píxel resultante
           if constexpr (std::is_same_v<T, ImageRGB>) {
               // Almacena la salida RGB
               result.data[i * result.w + j].r = sum;
               result.data[i * result.w + j].g = sum;
               result.data[i * result.w + j].b = sum;
           } else {  // ImageGrayscale
               result.data[i * result.w + j].value = sum;  // Access 'value' member for Grayscale
           }
       }
   }

   return result;
}

// Conversion jpg a pbm
void convertJPGtoPBM(const std::string& folder, const std::string& outputFolder) {
    // Abre la carpeta.
    std::ifstream folderStream(folder);
    if (!folderStream.is_open()) {
        std::cerr << "Error al abrir la carpeta " << folder << std::endl;
        return;
    }

    // Itera sobre los archivos de la carpeta.
    std::string filename;
    while (folderStream >> filename) {
        // Lee la imagen JPG.
        ImageRGB image = readJPG(filename);

        std::cout << "\nImagen:\tWidth: " << image.w << std::endl;

        // Convierte la imagen JPG a PBM.
        std::vector<unsigned char> pbmData;
        for (int i = 0; i < image.data.size(); i++) {
            unsigned char gray = (image.data[i].r + image.data[i].g + image.data[i].b) / 3;
            pbmData.push_back(gray);
        }

        // Escribe la imagen PBM.
        std::string outputFilename = outputFolder + "/" + filename + ".pbm";
        std::ofstream pbmFile(outputFilename);
        pbmFile << "P5" << std::endl;
        pbmFile << image.w << " " << image.h << std::endl;
        pbmFile.write(reinterpret_cast<char*>(pbmData.data()), pbmData.size());
        pbmFile.close();
    }

    // Cierra la carpeta.
    folderStream.close();
}



// Display RGB info
void display_imageRGB_info(const ImageRGB& img, const std::string& title) {
    std::cout << title << std::endl;
    std::cout << "Width: " << img.w << " pixeles" << std::endl;
    std::cout << "Height: " << img.h << " pixeles" << std::endl;
    std::cout << "Data preview: ";

    // Display a few pixels for a data preview
    for (int i = 0; i < 5; i++) {
        std::cout << "(" << static_cast<int>(img.data[i].r) << ", "
                  << static_cast<int>(img.data[i].g) << ", "
                  << static_cast<int>(img.data[i].b) << ") ";
    }
    std::cout << "... (continua)" << std::endl;
}
// Display PBM info
void display_imagePBM_info(const ImagePBM& img, const std::string& title) {
    std::cout << title << std::endl;
    std::cout << "Width: " << img.w << " pixeles" << std::endl;
    std::cout << "Height: " << img.h << " pixeles" << std::endl;
    std::cout << "Data preview: ";

    // Display a few pixels for a data preview
    for (int i = 0; i < 5; i++) {
        std::cout << img.data[i] << " ";
    }
    std::cout << "... (continua)" << std::endl;
}



// Funciones de perceptrón
// Función de activación (devuelve 1 si la entrada es mayor o igual a 0, y 0 en caso contrario)
int activation(int z) {
  return z >= 0 ? 1 : 0;
}

// Implementación del perceptrón (SOLO PBM de momento)
class Perceptron {
 public:
  // Constructor: inicializa los pesos del perceptrón con valores aleatorios
  Perceptron(int n) {
    pesos_ = std::vector<double>(n);
    for (int i = 0; i < n; i++) {
        srand(time(0));         // Semilla para inicializar
        int rand_num = rand();
        // Inicializados entre 0 y 1
        pesos_[i] = static_cast<double>(rand_num) / RAND_MAX;
    }
  }

  // Calcular la salida del perceptrón para una imagen PBM
  int calcular_salida(const ImagePBM& imagen) {
    int z = 0; // Sumatoria ponderada de los píxeles

    // Recorrido por el vector de datos, por cada pixel
    for(int i = 0; i < imagen.data.size(); i++){
        // Ajuste de pesos mediante combinación lineal
        z += pesos_[i] * imagen.data[i];
    }
    // Aplica la función de activación a la suma ponderada para obtener la salida del perceptrón
    return activation(z);
  }

 public:
  // Pesos del perceptrón (vector de enteros)
  std::vector<double> pesos_;
};
