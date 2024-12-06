# Uso de los programas:
1) Compilar los códigos evaluadores:
    - Código evaluador de DP: ``` g++ ./testDP.cpp -o testDP.exe ```.
    - Código evaluador de BT: ``` g++ ./testBT.cpp -o testBT.exe ```.
2) Al iniciar a los programas génerados tras la compilación debe ingresar la dirección donde estan las muestras, la dirección donde se guardara los resultados(si ya existe información esta será destruida) ambas deben ser en formato .txt y un título descriptivo para las muestras sin espacios, este titulo tambien será el nombre de la imagen con el gráfico:
    - Entrada estandar: ``` <nombre_archivo_muestras> <nombre_resultados_mediciones> <titulo_descriptivo> ```.
3) Una vez ejecutado los programas debe ingresar a graficar.py y ejecutar.
4) Ingrese la dirección de las muestras de salida, esta es la misma que dio en el paso 2:
    - Entrada Código Python: ``` <nombre_resultados_mediciones> ```.

# Muestras:
1) Formato: Las muestras deben ir en archivos .txt en la que cada linea cuenta con dos strings separados por un espacio, estos strings seran las entradas para las funciones.
2) Ubicación: Todos los archivos con muestas deben estar en la carpeta de ``` muestras/ ```.

# Figuras:
1) Ubicación: Todas las figuras generadas con graficar.py se encuentran en la carpeta ``` figuras/ ```.