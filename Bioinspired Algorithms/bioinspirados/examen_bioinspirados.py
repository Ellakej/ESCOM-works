# -*- coding: utf-8 -*-
"""examen_bioinspirados.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1zkpK2DZgaSpxb2J9HJoZ2lBUllRouxny
"""

import random

# Datos de entrada

# Lista de productos con precios aleatorios
productos_precios = {
    "Arroz": 10.0,
    "Frijoles": 20.0,
    "Aceite vegetal": 15.0,
    "Sal": 5.0,
    "Azúcar": 8.0,
    "Harina de trigo": 12.0,
    "Lentejas": 18.0,
    "Pasta": 7.0,
    "Sopa enlatada": 25.0,
    "Leche evaporada": 30.0,
    "Cereal": 40.0,
    "Galletas": 12.0,
    "Jabón de baño": 10.0,
    "Detergente": 15.0,
    "Papel higiénico": 22.0
}

# Vector de descuentos al azar en el rango de 0% a 30%
descuentos = [random.uniform(0, 30) for _ in range(15)]

# Calcular el vector de precios finales
precios_finales = [precio * (1 - descuento/100) for precio, descuento in zip(productos_precios.values(), descuentos)]

# Imprimir el vector de precios finales
print("Vector de precios finales con descuentos aplicados:")
print(precios_finales)

# Parámetros del algoritmo genético
tamano_poblacion = 10
num_generaciones = 50
probabilidad_crossover = 0.85
probabilidad_mutacion = 0.1
precio_maximo = 200  # Precio máximo que el propietario está dispuesto a aceptar

# Función de aptitud (fitness)
def calcular_perdida(cromosoma):
    # Calcular la pérdida asociada a la combinación de productos
    precios_finales = [precio * (1 - descuento/100) for precio, descuento in zip(productos_precios.values(), cromosoma)]
    perdida = sum(precios_finales) - precio_maximo
    return perdida if perdida > 0 else 0

# Inicialización de la población
poblacion = [[random.choice([0, 1]) for _ in range(len(productos_precios))] for _ in range(tamano_poblacion)]

# Algoritmo genético
for generacion in range(num_generaciones):
    # Evaluación de la aptitud de cada cromosoma
    aptitudes = [calcular_perdida(cromosoma) for cromosoma in poblacion]

    # Selección de padres mediante la ruleta (Roulette Wheel)
    padres = []
    total_aptitud = sum(aptitudes)
    for _ in range(tamano_poblacion):
        seleccion = random.uniform(0, total_aptitud)
        acumulado = 0
        for i, aptitud in enumerate(aptitudes):
            acumulado += aptitud
            if acumulado >= seleccion:
                padres.append(poblacion[i])
                break

    # Crossover (Uniform Crossover)
    hijos = []
    for i in range(0, tamano_poblacion, 2):
        if random.random() < probabilidad_crossover:
            punto_crossover = random.randint(1, len(productos_precios) - 1)
            hijo1 = padres[i][:punto_crossover] + padres[i + 1][punto_crossover:]
            hijo2 = padres[i + 1][:punto_crossover] + padres[i][punto_crossover:]
            hijos.extend([hijo1, hijo2])
        else:
            hijos.extend([padres[i].copy(), padres[i + 1].copy()])

    # Mutación
    for i in range(tamano_poblacion):
        for j in range(len(productos_precios)):
            if random.random() < probabilidad_mutacion:
                hijos[i][j] = 1 - hijos[i][j]

    # Actualización de la población (Generational Update con waker parent replacement)
    poblacion = hijos

# Obtener el mejor cromosoma (la combinación de productos que minimiza la pérdida)
mejor_cromosoma = min(poblacion, key=calcular_perdida)

# Datos adicionales
productos_seleccionados = [
    list(productos_precios.keys())[i] for i, v in enumerate(mejor_cromosoma) if v == 1
]
precio_total = sum([precio * (1 - descuento/100) for precio, descuento in zip(productos_precios.values(), mejor_cromosoma)])

print("Mejor cromosoma: ", mejor_cromosoma)
print("Mejor combinación de productos:", productos_seleccionados)
print("Pérdida mínima:", calcular_perdida(mejor_cromosoma))
print("Precio total:", precio_total)

