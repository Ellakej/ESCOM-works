#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 10 15:04:35 2022

@author: ricardoneftalygarciaking
"""

# Importacion de librerias
import numpy as np
import pandas as pd

# Abrir el dataset
dataset = pd.read_csv('/Users/ricardoneftalygarciaking/Documents/ESCOM/Aprendizaje Máquina/preprocesado/Data.csv')
# Extraccion de variables
X = dataset.iloc[:, :-1].values
Y = dataset.iloc[:, -1].values

# Imputacion de datos
from sklearn.impute import SimpleImputer
imputador = SimpleImputer(missing_values=np.nan, strategy="mean")
X[:, 1:] = imputador.fit_transform(X[:, 1:])

# Conversion de datos categoricos a numericos

# Conversion de variable X con estrategia de hot-encoder
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
ct = ColumnTransformer([('country_encoder', OneHotEncoder(), [0])], remainder="passthrough")
X = np.array(ct.fit_transform(X))

# Conversion de variable Y con estrategia de Label Encoder
from sklearn.preprocessing import LabelEncoder
Y = LabelEncoder().fit_transform(Y)

# Segmentacion de datos de entrenamientoy  test
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=5)

# Estandarización de datos
from sklearn.preprocessing import StandardScaler
st = StandardScaler();
X_train[:, 3:]  = st.fit_transform(X_train[:, 3:])
X_test[:, 3:] = st.fit_transform(X_test[:, 3:])