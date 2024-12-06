# Uso de los programas:
1) Compilar los códigos evaluadores:
    - Código evaluador de DP: ``` g++ ./testDP.cpp -o testDP.exe ```.
    - Código evaluador de BT: ``` g++ ./testBT.cpp -o testBT.exe ```.
2) Al iniciar a los programas génerados tras la compilación debe ingresar la dirección donde estan las muestras, la dirección donde se guardara los resultados(si ya existe información esta será destruida) ambas deben ser en formato .txt y un título descriptivo para las muestras sin espacios, este titulo tambien será el nombre de la imagen con el gráfico:
    - Entrada estandar: ``` <dirección_muestras> <dirección_resultados_mediciones> <titulo_descriptivo> ```.
3) Una vez ejecutado los programas debe ingresar a graficar.py y ejecutar.
4) Ingrese la dirección de las muestras de salida, esta es la misma que dio en el paso 2:
    - Entrada Código Python: ``` <dirección_resultados_mediciones> ```.

# Formato muestras:
En cada archivo donde se encuentran las muestras deben lineas que contienen pares de muestras que seran comparadas con las dos funciones.