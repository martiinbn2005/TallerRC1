void ingresarDatos(char nombres[5][30], float *tiempos, int *recursos, int *demandas);
float calcularTiempoTotal(float *tiempos, int *demandas);
int calcularRecursosTotales(int *recursos, int *demandas);
void verificarFactibilidad(float *tiempos, int *recursos, int *demandas, float tiempoDisponible, int recursosDisponibles);
void editarProducto(char nombres[5][30], float *tiempos, int *recursos, int *demandas);
void eliminarProducto(char nombres[5][30], float *tiempos, int *recursos, int *demandas);
