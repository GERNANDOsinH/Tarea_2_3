import matplotlib.pyplot as plt

def leer_archivo(archivo):
    """
    Función que lee un archivo de texto con una línea de texto seguida de líneas que contienen un número entero y un número decimal.
    
    Parámetros:
    - archivo (str): Nombre del archivo a leer.

    Retorna:
    - str: El string de la primera línea.
    - list of tuple: Lista de tuplas con un número entero y un número decimal de las líneas siguientes.
    """
    try:
        with open(archivo, 'r') as file:
            title = file.readline().strip()
            
            x = []
            y = []
            for line in file:
                partes = line.split()
                if len(partes) == 2:
                    entero = int(partes[0])
                    decimal = float(partes[1])
                    x.append(entero)
                    y.append(decimal)
            
            return title, x, y
    except FileNotFoundError:
        raise FileNotFoundError(f"El archivo '{archivo}' no se encontró.")
    except ValueError:
        raise ValueError("El archivo tiene un formato incorrecto.")
    except Exception as e:
        raise e

def graficar(L_pow_2, time, title):
    plt.figure(figsize=(6, 6))
    
    plt.scatter(L_pow_2, time, color='red')
    
    plt.axhline(0, color='black', linewidth=0.5)
    plt.axvline(0, color='black', linewidth=0.5)
    plt.grid(color='gray', linestyle='--', linewidth=0.5)
    plt.title(title)
    plt.xlabel('Tamano str1.size() * str2.size()')
    plt.ylabel('Tiempo de ejecucion [ns]')
    plt.show()

dir = input("Ingrese la direccion de los resultados: ")

title, x, y = leer_archivo(dir)

graficar(x, y, title)