# Se limpian las variables
rm(list=ls())

# Se abre el dataset
dataset <- read.csv("~/Documents/ESCOM/Aprendizaje Máquina/actividad1/exams.csv")
# Se separan en variables
X = dataset[, 1:5]
y = dataset[, 6]

# No hay nada que imputar, la tabla está completa

### Codificado de datos categoricos a numéricos ###
# La columna de genero (1), la de lunch (4) y test_prep_course (5) son binarias
# basta con usar factores
factor1 = factor(X$gender)
factor2 = factor(X$lunch)
factor3 = factor(X$test_prep_course)
X$gender = as.numeric(factor1)
X$lunch = as.numeric(factor2)
X$test_prep_course = as.numeric(factor3)

# Para la columna race/ethnicity (2) y parent_education_level (3) se usará onehotkeyencoder y dummyvariable
library(caret)
dummy <- dummyVars(" ~ .", data = X)
X <- data.frame(predict(dummy, newdata=X))

### Segmentado de datos en tests y train ###
library(caTools)
set.seed(123)                     # Semilla para agregar aleatoriedad
split = sample.split(X, SplitRatio = 0.8)
training_set = subset(X, split == TRUE)
test_set = subset(X, split == FALSE)
