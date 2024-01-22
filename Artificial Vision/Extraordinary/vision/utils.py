import cv2
import _osx_support
import os 

def convert_jpg_to_pbm(image_path):
  image = cv2.imread(image_path)
  image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
  image_pbm = cv2.imencode('.pbm', image_gray)[1]
  with open(image_path.replace('.jpg', '.pbm'), 'wb') as f:
    f.write(image_pbm)

def renombrar_archivos(carpeta):
  """Renombra archivos en .pbm dentro de una carpeta, de manera ascendente desde 0 hasta la cantidad total de elementos que haya.

  Args:
    carpeta: La ruta a la carpeta donde se encuentran los archivos.
  """

  # Obtenemos una lista de todos los archivos en la carpeta.
  listado = os.listdir(carpeta)

  # Filtramos los archivos que tienen la extensión .pbm.
  listado_pbm = [archivo for archivo in listado if archivo.endswith(".pbm")]

  # Inicializamos un contador.
  contador = 0

  # Recorremos la lista de archivos.
  for archivo in listado_pbm:
    # Renombramos el archivo con el nuevo nombre.
    nuevo_nombre = str(contador) + ".pbm"
    os.rename(os.path.join(carpeta, archivo), os.path.join(carpeta, nuevo_nombre))

    # Incrementamos el contador.
    contador += 1


def main():
  #input_dir = '/Users/ricardoneftalygarciaking/Documents/ESCOM/vision/number_dataset/train'
  #output_dir = '/Users/ricardoneftalygarciaking/Documents/ESCOM/vision/number_dataset/train_pbm'

  #if not os.path.exists(output_dir):
  #  os.mkdir(output_dir)

  #for image_path in os.listdir(input_dir):
  #  if image_path.endswith('.jpg'):
  #    convert_jpg_to_pbm(os.path.join(input_dir, image_path))


  # Indicamos la ruta a la carpeta.
  carpeta = "/Users/ricardoneftalygarciaking/Documents/ESCOM/vision/number_dataset/train"

  # Renombramos los archivos.
  renombrar_archivos(carpeta)
  


if __name__ == '__main__':
  main()