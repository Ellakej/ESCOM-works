#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 10 18:55:54 2022

@author: ricardoneftalygarciaking
"""

# Librerias
import numpy as np
import pandas as pd

# Importación del dataset
dataset = pd.read_csv('/Users/ricardoneftalygarciaking/Documents/ESCOM/Aprendizaje Máquina/actividad1/exams.csv')
# Separacion de variables
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, -1].values

# No es necesario imputar datos porque esta completa la información

# Conversión de variables
# La columna de genero (0), la de lunch (3) y test_prep_course (4) son binarias
# basta con convertir con LabelEncoder
from sklearn.preprocessing import LabelEncoder
label_encoder = LabelEncoder()
X[:, 0] = label_encoder.fit_transform(X[:, 0])          # Género
X[:, 3] = label_encoder.fit_transform(X[:, 3])          # Lunch
X[:, 4] = label_encoder.fit_transform(X[:, 4])          # test_prep_course

# Para la columna race/ethnicity (1) y parent_education_level (2) se usará onehotkeyencoder
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder

ct = ColumnTransformer([('encoder_hot', OneHotEncoder(), [1, 2])], remainder="passthrough")
X = np.array(ct.fit_transform(X))

# Separación de datos de test y training
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=30)