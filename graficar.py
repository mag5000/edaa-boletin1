import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos desde un archivo CSV (o cualquier otro formato de datos)
data = pd.read_csv("output/results.csv")

# Obtener valores únicos de "position"
unique_positions = data['position'].unique()

# Calcular la cantidad de filas y columnas necesarias para organizar los gráficos en 2 columnas
num_rows = (len(unique_positions) + 1) // 2
num_cols = 2

# Crear una sola figura para todos los gráficos
fig, axes = plt.subplots(num_rows, num_cols, figsize=(12, 6*num_rows))

# Iterar a través de las posiciones y crear un gráfico en cada subfigura
for i, position in enumerate(unique_positions):
    position_data = data[data['position'] == position]
    row = i // num_cols
    col = i % num_cols
    ax = axes[row, col]
    ax.set_title(f'\n\n\nGráfico para Position {position}')
    
    # Iterar a través de los algoritmos únicos y crear una línea para cada uno
    unique_algorithms = position_data['algorithm'].unique()
    for algorithm in unique_algorithms:
        algorithm_data = position_data[position_data['algorithm'] == algorithm]
        ax.plot(algorithm_data['size'], algorithm_data['time'], label=algorithm)

    # Personalizar el gráfico
    ax.set_xlabel('Size')
    ax.set_ylabel('Time (log scale)')  # Cambio del etiquetado en el eje y
    ax.set_yscale('log')  # Cambio de escala logarítmica en el eje y
    ax.legend()

# Ajustar los espacios entre los gráficos y las etiquetas de los ejes
plt.tight_layout()

# Mostrar la figura con todos los gráficos
plt.show()