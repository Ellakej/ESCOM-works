#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 15 05:20:10 2022

@author: brunorg
"""

# Importando librerias
import spacy # Se usa Spacy, para la tokenizacion y lematizacion 
import os # Se usa OS, para el manejo de ficheros
import nltk # Se usa NLTK para las stopwords
from nltk.corpus import stopwords
nltk.download('stopwords')

def Preprocessing_text(document_title:str):
    
    # Abrimos el archivo
    file = open('./transcriptions/'+str(document_title),mode='r')
    #Obtenemos el texto del archivo
    text = file.read()

    #Preprocesando texto
    
    #Eliminando los espacios en blanco
    text = text.strip()
    
    # Cargamos el lenguaje "Español" para el preprocesado
    nlp = spacy.load('es_core_news_sm')
    # Se crea una lista de las stopwords 
    spanish_stopwords = set(stopwords.words('spanish'))
    #Tokenizacion por palabra
    document = nlp(text)
    corpus = []
    for token in document:
        # Revisamos si la palabra es stopword o no
        if token.is_punct or token.is_stop or token.text.lower() in spanish_stopwords:
            continue
        # Si la palabra no es stopword, se lematiza, convierte a minusculas y se agrega a una lista
        else:
            corpus.append(token.lemma_.lower())
            
    #Ingresando lista a un documento de texto
    with open('./preprocessed/'+str(document_title), "w", encoding='utf-8') as text_file:
            text_file.write(str(corpus))
    
# Ejecutando el preprocesamiento en cada archivo de texto

content = os.listdir('./transcriptions')
for item in content:
    print('Preprocesando archivo con nombre:'+str(item))
    Preprocessing_text(str(item))
