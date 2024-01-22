#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 22 00:16:53 2022

@author: brunorg
"""

import os # Para el manejo de ficheros
import numpy as np # Para el manejo de arreglos, funciones matematicas etc 
import pandas as pd # Para la creacion de dataframes
import matplotlib.pyplot as plt # Para la graficacion
from sklearn.decomposition import PCA # Analisis de Componentes Principales
from sklearn.cluster import KMeans # KMeans
from sklearn.cluster import AgglomerativeClustering # Jerarquico    
from sklearn.mixture import GaussianMixture # Modelo de Mezclas Gaussianas
from sklearn.metrics import davies_bouldin_score # Indice de Davies-Boulding
from sklearn.feature_extraction.text import CountVectorizer # Bolsa de palabras
from sklearn.feature_extraction.text import TfidfTransformer # TF-IDF
import scikit_posthocs as sp # Indice de Dunn

# Definiendo el corpus a partir de los archivos tokenizados
docs = []
def extract_docs(content):
    items = []
    for item in content:
        file = open('./preprocessed/'+str(item), 'r')
        # Se hace una pequeña limpieza extra
        items.append(file.read().replace('[','').replace(']','').replace('\'','').replace(' ','').replace('\\n','').replace('\\xa0','').replace(',,',',').replace(',',' '))
        # Recolectamos los nombres de los documentos
        docs.append(item)
    return items

content = os.listdir('./preprocessed/')

# Convertimos ambas listas a listas de numpy
normalize_corpus = np.array(extract_docs(content))
docs_np = np.array(docs)

#Obtener la bolsa de palabras
cv = CountVectorizer(min_df=0., max_df=1.)
cv_matrix = cv.fit_transform(normalize_corpus)
cv_matrix = cv_matrix.toarray()

# Obtener las palabras unicas en el corpus
vocabulary = cv.get_feature_names_out()

# Integrando la bolsa de palabras a un DataFrame, para su visualizacion
df_BoW = pd.DataFrame(cv_matrix, columns = vocabulary, index=docs_np)


#Implementando TF-IDF
tt = TfidfTransformer(norm='l2', use_idf=True)
tt_matrix = tt.fit_transform(cv_matrix)
tt_matrix = tt_matrix.toarray()
# Integrando el TF-IDF a un DataFrame, para su visualizacion
df_tf_idf = pd.DataFrame(data = np.round(tt_matrix,10), columns=vocabulary, index=docs_np)

# Realizamos analisis de componentes principales 
pca = PCA(n_components=2)
pca_mananeras = pca.fit_transform(df_tf_idf)


"""

#  Metodo del codo
wcss = []
for i in range(1,20):
    print('Realizando kMeans con '+str(i)+' kluster\'s')
    kmeans = KMeans(n_clusters=i, max_iter=300)
    kmeans.fit(pca_mananeras)
    wcss.append(kmeans.inertia_)

    
plt.plot(range(1,20), wcss,'o-')
plt.title("Codo de Jambú")
plt.xlabel('N - Clusters')
plt.ylabel('WCSS')
plt.grid()
plt.show()


# Dendrograma
from scipy.cluster.hierarchy import dendrogram, linkage

Z = linkage(pca_mananeras, metric='cosine', method='average')
plt.title('Dendograma')
plt.xlabel('Individuos')
plt.ylabel('Distancia')
dendrogram(Z, truncate_mode='lastp',p=12,leaf_rotation=90.,leaf_font_size=12.,show_contracted=True)
plt.show() 

 # Metodo de la silueta
def MetodoSilueta():
    S=[]

    K=range(2,20)

    for k in K:
        GMM = GaussianMixture(n_components=k, n_init=20, init_params='kmeans')
        # Fit the model 
        labels = GMM.fit_predict(pca_mananeras)
        # Calculate Silhoutte Score and append to a list
        S.append(metrics.silhouette_score(pca_mananeras, labels, metric='euclidean'))
    
    # Plot the resulting Silhouette scores on a graph
    plt.figure(figsize=(16,8), dpi=300)
    plt.plot(K, S, 'bo-', color='black')
    plt.xlabel('k')
    plt.ylabel('Silhouette Score')
    plt.title('Identify the number of clusters using Silhouette Score')
    plt.show()
"""


# Aplicando KMeans ------------------------------
def ClusteringKMeans(clusters_kmeans:int):

    # Se crea el modelo
    clustering = KMeans(n_clusters = clusters_kmeans, max_iter = 300 , init='k-means++')
    # Se entrena el modelo
    clustering.fit(pca_mananeras)
    # Se obtienen los centroides
    centroids = clustering.cluster_centers_
    # Se obtienen las etiquetas del grupo asignado a cada individuo
    labels = clustering.labels_
    
    # Creamos una paleta de colores para graficar
    color_theme=np.array(['#9314f7','#eb6813','#f9f108','#c4f908','#7af418','#23de1c','#f815ed','#16fc98','#14f7e3','#1498f7','#1421f7','#a81ac9'])

    # Graficamos todos los individuos, pintandolos segun el grupo asignado
    plt.scatter(x=pca_mananeras[:,0],y=pca_mananeras[:,1],c=color_theme[labels],s=5)
    # En el mismo grafico, agregamos los centroides denotandolos con una "X" de color negro
    plt.scatter(x=centroids[:,0],y=centroids[:,1],marker='x', s=50,c='black')

    # Agregamos informacion descriptiva a la grafica
    plt.title('KMeans N='+str(clusters_kmeans))
    plt.xlabel('Componente 1')
    plt.ylabel('Componente 2')

    # Calculamos y agregamos el indice de DB. 
    plt.text(0.25,0.5,'Indice DB:'+str(davies_bouldin_score(pca_mananeras, clustering.labels_))[0:6],style='italic')
    # Mostramos la grafica
    plt.show() 
    

    #Para calcular el indice de Dunn
    # Convertimos nuestros datos a un solo componente, es necesario para este calculo
    pca_one_comp = PCA(n_components=1)
    pca_dunn = pca_one_comp.fit_transform(df_tf_idf)

    # Ajustamos el formato 
    a = pca_dunn[:,0].reshape(1, -1)
    b = labels.reshape(1, -1)
    
    dunn = []
    # Creamos un arreglo bidimensional con los valores de pca_dunn y los grupos asignados
    for i in range(0,797):
        dunn.append([a[0,i],b[0,i]])
      
    # Creamos un dataframe en base al numero de indices
    df_dunn = pd.DataFrame(np.array(dunn))

    # Agregamos nombres a las columnas del dataframe
    df_dunn.columns = ['valores','grupos']  
    
    # Calculamos el indice de dunn
    indice_dunn = sp.posthoc_dunn(df_dunn,val_col='valores',group_col='grupos', p_adjust='bonferroni')

    #Guardamos el indice de Dunn en archivos excel 
    indice_dunn.to_excel('./Indices/'+str(clusters_kmeans)+'KMeans.xlsx')

#  -------------------------------------------------------------------------------------
# Clustering Jerarquico
def ClusteringJerarquico(clusters_jerarquico:int):
    
    # Se crea el modelo : importante, usamos la distancia coseno porque da mejores resultados con textos , junto con el metodo de enlace "average o promedio"
    hc = AgglomerativeClustering(n_clusters=clusters_jerarquico, affinity='cosine',linkage='average')
    # Se entrena el modelo
    hc.fit(pca_mananeras)
    
    #Para calcular los centroides linea de codigo 160-179
    labels = np.array(hc.labels_)
    unique_labels = list(set(labels))
    temp_centroids = []
    for unique_label in unique_labels:
        coord = [0,0,0]
        
        for i in range(0,len(pca_mananeras)):
            if labels[i] == unique_label:
                coord[0] += pca_mananeras[i][0]
                coord[1] += pca_mananeras[i][1]
                coord[2] = coord[2]+1
        temp_centroids.append(coord)
    
    xcentroids = []
    ycentroids = []
    
    for i in range(0,len(temp_centroids)):
        xcentroids.append(temp_centroids[i][0]/temp_centroids[i][2])
        ycentroids.append(temp_centroids[i][1]/temp_centroids[i][2])
    
    # Creamos una paleta de colores para graficar
    color_theme=np.array(['#9314f7','#eb6813','#f9f108','#c4f908','#7af418','#23de1c','#f815ed','#16fc98','#14f7e3','#1498f7','#1421f7','#a81ac9'])

    # Graficamos todos los individuos, pintandolos segun el grupo asignado
    plt.scatter(x=pca_mananeras[:,0],y=pca_mananeras[:,1],c=color_theme[hc.labels_], s=5)
    # En el mismo grafico, agregamos los centroides denotandolos con una "X" de color negro
    plt.scatter(x=xcentroids,y=ycentroids,marker='x', s=50,c='black')
     # Agregamos informacion descriptiva a la grafica
    plt.title('Jerarquico N='+str(clusters_jerarquico))
    plt.xlabel('Componente 1')
    plt.ylabel('Componente 2')
    # Calculamos y agregamos el indice de DB. 
    plt.text(0.25,0.5,'Indice DB:'+str(davies_bouldin_score(pca_mananeras, hc.labels_))[0:6],style='italic')
    # Mostramos el grafico
    plt.show()
    
    #Para calcular el indice de Dunn
    # Convertimos nuestros datos a un solo componente, es necesario para este calculo
    pca_one_comp = PCA(n_components=1)
    pca_dunn = pca_one_comp.fit_transform(df_tf_idf)

    # Ajustamos el formato 
    a = pca_dunn[:,0].reshape(1, -1)
    b = labels.reshape(1, -1)
    
    dunn = []
    # Creamos un arreglo bidimensional con los valores de pca_dunn y los grupos asignados
    for i in range(0,797):
        dunn.append([a[0,i],b[0,i]])
      
    # Creamos un dataframe en base al numero de indices
    df_dunn = pd.DataFrame(np.array(dunn))

    # Agregamos nombres a las columnas del dataframe
    df_dunn.columns = ['valores','grupos']  
    
    # Calculamos el indice de dunn
    indice_dunn = sp.posthoc_dunn(df_dunn,val_col='valores',group_col='grupos', p_adjust='bonferroni')

    #Guardamos el indice de Dunn en archivos excel 
    indice_dunn.to_excel('./Indices/'+str(clusters_jerarquico)+'Jerarquico.xlsx')

# Gaussian Mixture Models (GMM)

def GMM(clusters_gmm:int):

    # Set the model and its parameters 
    gmm_model = GaussianMixture(n_components=clusters_gmm, # this is the number of clusters
                         covariance_type='full', # {‘full’, ‘tied’, ‘diag’, ‘spherical’}, default=’full’
                         max_iter=100, # the number of EM iterations to perform. default=100
                         n_init=1, # the number of initializations to perform. default = 1
                         init_params='kmeans', # the method used to initialize the weights, the means and the precisions. {'random' or default='k-means'}
                         verbose=0, # default 0, {0,1,2}
                         random_state=1 # for reproducibility
                        )
    
    # Fit the model and predict labels
    gmm_clust = gmm_model.fit(pca_mananeras)
    gmm_labels = gmm_model.predict(pca_mananeras)
    
    # Print model summary
    print('*************** Cluster Model ***************')
    print('Means: ', gmm_clust.means_)
    print('Converged: ', gmm_clust.converged_)
    print(' No. of Iterations: ', gmm_clust.n_iter_)
    
    
    # Attach cluster labels to the main dataframe
    
    # Create a figure
    color_theme=np.array(['#9314f7','#eb6813','#f9f108','#c4f908','#7af418','#23de1c','#f815ed','#16fc98','#14f7e3','#1498f7','#1421f7','#a81ac9'])
    plt.scatter(x=pca_mananeras[:,0],y=pca_mananeras[:,1],c=color_theme[gmm_labels], s=5)
    plt.title('Modelo de Mezcla Gaussiano N='+str(clusters_gmm))
    plt.xlabel('Componente 1')
    plt.ylabel('Componente 2')
    plt.text(0.25,0.5,'Indice DB:'+str(davies_bouldin_score(pca_mananeras, gmm_labels))[0:6],style='italic')
    plt.show()

    pca_one_comp = PCA(n_components=1)
    pca_dunn = pca_one_comp.fit_transform(df_tf_idf)
    
    a = pca_dunn[:,0].reshape(1, -1)
    b = gmm_labels.reshape(1, -1)
    
    dunn = []
    
    for i in range(0,797):
        dunn.append([a[0,i],b[0,i]])
      
    df_dunn = pd.DataFrame(np.array(dunn))
    df_dunn.columns = ['valores','grupos']  
    
    indice_dunn = sp.posthoc_dunn(df_dunn,val_col='valores',group_col='grupos', p_adjust='bonferroni')
    indice_dunn.to_excel('./Indices/'+str(clusters_gmm)+'GMM.xlsx')
    