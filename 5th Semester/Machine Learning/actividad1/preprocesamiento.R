# Se limpian las variables
rm(list=ls())

# Se abre el dataset
dataset <- read.csv("~/Documents/ESCOM/Aprendizaje Máquina/actividad1/Mall_Customers.csv")
# Se separan en variables
X = dataset[, 1:4]
y = dataset[, 5]

### Imputación de datos ###
X$Age[is.na(X$Age)] <- mean(X$Age, na.rm = TRUE)
X$Annual.Income..k..[is.na(X$Annual.Income..k..)] <- mean(X$Annual.Income..k.., na.rm = TRUE)

### Codificado de datos categoricos a numéricos ###
# Es binario, así que por factores se puede sacar
factors <- factor(X$Genre)            # Se crean los factores
X$Genre = as.numeric(factors)

### Segmentado de datos en tests y train ###
library(caTools)
set.seed(123)                     # Semilla para agregar aleatoriedad
split = sample.split(X, SplitRatio = 0.8)
training_set = subset(X, split == TRUE)
test_set = subset(X, split == FALSE)


# Estandarización
training_set[, 3:4] = scale(training_set[, 3:4])
test_set[, 3:4] = scale(test_set[, 3:4])