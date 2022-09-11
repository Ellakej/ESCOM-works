# Dependencias instalables usables
#install.packages('caTools')
#install.packages('caret')


# Se limpian todas las variables
rm(list=ls())

# Se abre el dataset
dataset <- read.csv("~/Documents/ESCOM/Aprendizaje Máquina/preprocesado/Data.csv")

### Imputacion de datos ###
dataset$Edad[is.na(dataset$Edad)] <- mean(dataset$Edad, na.rm = TRUE)
dataset$Salario[is.na(dataset$Salario)] <- mean(dataset$Salario, na.rm = TRUE)

# Separacion en variables 
X = dataset[,1:3]
Y = dataset[,4]


# Conversion de datos categoricos a numéricos 
# Variable X con onehotencoder y dummyvariable
library(caret)
# Define la funcion de onehotkeyencoder
dummy <- dummyVars(" ~ .", data = X)

# Acciona el onehotkeyencoder en el dataframe
X <- data.frame(predict(dummy, newdata=X))

# Variable Y por factores
factors <- factor(Y)              # Se crean los factores
Y = as.numeric(factors)           # Se parsean a numéricos


### Separación de datos en Test y Train ###
library(caTools)
set.seed(123)                     # Semilla para agregar aleatoriedad
split = sample.split(X, SplitRatio = 0.8)
training_set = subset(X, split == TRUE)
test_set = subset(X, split == FALSE)

# Estandarización
training_set[, 4:5] = scale(training_set[, 4:5])
test_set[, 4:5] = scale(test_set[, 4:5])
