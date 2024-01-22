#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 10 18:55:54 2022

@author: ricardoneftalygarciaking
"""

# Librerias
import pandas as pd
import numpy as np

# Importación del dataset
dataset = pd.read_csv('/Users/ricardoneftalygarciaking/Documents/ESCOM/Aprendizaje Máquina/actividad1/Mall_Customers.csv')
# Separación de variables
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, -1].values

# Imputación de datos por estrategia mean
from sklearn.impute import SimpleImputer
imputador = SimpleImputer(missing_values=np.nan, strategy='mean')
X[:, 2:] = imputador.fit_transform(X[:, 2:])

# Conversion a datos categoricos
# Uso de LabelEncoder debido a que únicamente es un etiquetado binario del género
from sklearn.preprocessing import LabelEncoder
X[:, 1] = LabelEncoder().fit_transform(X[:, 1])

# Separacion de datos en datos de entrenamiento y datos de tests
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=30)

# Estandarización
from sklearn.preprocessing import StandardScaler
X_train[:, 2:] = StandardScaler().fit_transform(X_train[:, 2:])
X_test[:, 2:] = StandardScaler().fit_transform(X_test[:, 2:])