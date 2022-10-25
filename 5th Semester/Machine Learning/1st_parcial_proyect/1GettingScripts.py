"""
Created on Fri Oct 14 17:02:51 2022

@author: brunorg
"""
from bs4 import BeautifulSoup
import requests
import re, string

data = []
#281
counter = 1
while counter < 282:    
    website = 'https://lopezobrador.org.mx/transcripciones/page/'+str(counter)
    response = requests.get(website)
    content = response.text

    soup = BeautifulSoup(content, 'lxml')

    container = soup.find('div',class_='isotope-container')

    validarConferencia = 'Versión estenográfica de la conferencia de prensa matutina del presidente Andrés Manuel López Obrador'

    #Obtenemos todos los articulos
    articles = container.find_all('article')

    for article in articles:
        if article.find_all('a', title=True)[0]['title'] == validarConferencia:
            link = article.find_all('a', href=True)[0]['href']
            title = article.find_all('a', title=True)[0]['title']
            data.append({'title':title, 'url':link})
    print('Paso: '+str(counter))
    counter = counter + 1

def normalize(s):
    replacements = (
        ("á", "a"),
        ("é", "e"),
        ("í", "i"),
        ("ó", "o"),
        ("ú", "u"),
    )
    for a, b in replacements:
        s = s.replace(a, b).replace(a.upper(), b.upper()).replace('’','').replace('?','').replace('¿','').replace('‘','').replace('—','')
    return s.lower()
#% 
def remove_punctuation ( text ):
  return re.sub('[%s]' % re.escape(string.punctuation) , '', text)

def remove_numbers(text):
    return re.sub('[0-9]' , '', text)

for video in data:
#En data se tiene una lista de diccionarios con todas las urls de las diferentes conferencias
    website = video['url']
    response = requests.get(website)
    content = response.text
    soup = BeautifulSoup(content, 'lxml')
    container = soup.find('article',class_='post')
    fecha = container.find('span', class_='entry-date').find('a').text.replace(' ','-').replace(',','')
    listP1 = container.find_all('p')
    
    text = []
    for p in listP1:
        if p.b:
            p.b.string =''
        temp = normalize(p.text)
        temp = remove_punctuation(temp)
        temp = remove_numbers(temp)
        text.append(temp)

    with open('./transcriptions/'+str(fecha)+'.txt', "w", encoding='utf-8') as text_file:
        for p in text:
            text_file.write(p+'\n')
    print(str(fecha))

print('Ya quedo!')



