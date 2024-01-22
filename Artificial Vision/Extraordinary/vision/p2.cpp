// Programa 2. Reconocedor de números mediante perceptrones
// Hecho por García King Ricardo Neftaly García King - 5BV1
// El perceptrón es una red neuronal simple


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "libprocesadoimagenes.h"

int main(){
    // Parametros
    std::string input_path = "/Users/ricardoneftalygarciaking/Documents/ESCOM/vision/number_dataset/train/";
    int n_train_images = 5760;          // Esto deberia ser dinamico para tomar el total de archivos
    int no_perceptrones = 10;
    int ciclos_entrenamiento = 10000;

    // Convertir dataset a pbm
    //convertJPGtoPBM("number_dataset/train/", "number_dataset/train_output/");

    // Cargar el conjunto de datos de entrenamiento
    std::vector<ImagePBM> entrenamiento;
    for (int i = 0; i < n_train_images; i++) {
        entrenamiento.push_back(load_pbm(input_path + std::to_string(i) + ".pbm"));
        system("clear");
        std::cout << "Cargando imagen no. " << i << "\nPor favor espere..." << std::endl;
    }
    std::cout << "\nImagenes cargadas correctamente." << std::endl;

    // Obtensión de dimensiones
    int w = entrenamiento[0].w;
    int h = entrenamiento[0].h;

    // Inicializar los pesos de los perceptrones
    //std::vector<Perceptron> perceptrones(10);
    //for (int i = 0; i < no_perceptrones; i++) {
    //    perceptrones[i] = Perceptron(w * h);
    //}
    // Inicializado por constructor
    std::vector<Perceptron> perceptrones(10, Perceptron(w*h));


    // Entrenar el reconocedor
    for (int i = 0; i < ciclos_entrenamiento; i++) {
        for (int j = 0; j < entrenamiento.size(); j++) {
            for (int k = 0; k < entrenamiento[j].w * entrenamiento[j].h; k++) {
                int binario = entrenamiento[j].data[k];
                perceptrones[binario].calcular_salida(entrenamiento[j]);
                system("clear");
                std::cout << "Entrenamiento en progreso...\nCiclo: " << i << "\t" << std::endl;
            }
            
        }
    }
    std::cout << "\nEntrenamiento finalizado" << std::endl;
    


    return 0;
}