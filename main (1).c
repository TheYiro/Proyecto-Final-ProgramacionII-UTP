//CODIGO REALIZADO POR JERONIMO MAPE SOTO - 1088826255 - PROGRAMACIÓN II.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Matriz global de productos.
int productos[4][3] = {
    {123, 1500, 10},
    {456, 2500, 13},
    {789, 1000, 18},
    {234, 4200, 9}
};


// Variables globales de efectivo y tarjeta.
double efectivo = 20000;
double tarjeta = 10000;


// Prototipos de funciones.
int login();
void mostrarMenu();
int leerOpcion();
void listarProductos();
void venderProducto();
void comprarProducto();
void mostrarVentasDelDia();


// ---------------- MENÚ/SWITCH CASE PRINCIPAL CON ENCABEZADO ----------------
int main() {
    // Encabezado del login.
    printf(" ╔════════════════════════════════════════════╗\n");
    printf(" ■     LOGIN ALMACEN LAS MECHAS by Jero       ■\n");
    printf(" ╚════════════════════════════════════════════╝\n");
    int loggedIn = 0;
    while (!loggedIn) {
        loggedIn = login();
    }
    // Encabezado Menú.
    printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(" |     Welcome to ALMACEN LAS MECHAS        |\n");
    printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    int continuar = 1;
    while (continuar) {
        mostrarMenu();
        int opcion = leerOpcion();

        switch (opcion) {
            case 1:
                listarProductos();
                break;
            case 2:
                venderProducto();
                break;
            case 3:
                comprarProducto();
                break;
            case 4:
                mostrarVentasDelDia();
                break;
            case 5:
                continuar = 0;
                break;
            default:
                printf("Opción inválida. Inténtelo de nuevo.\n");
                break;
        }
    }
    // Mensaje de salida.
    printf("¡Gracias por utilizar la aplicacion de ALMACEN LAS MECHAS by Jeró\n");
    return 0;
}


// ---------------- LOGIN ----------------
int login() {
    char usuario[20];
    char contraseña[20];
    char usuarioGuardado[20];
    char contraseñaGuardada[20];
   
    printf("Ingrese su usuario: ");
    scanf("%s", usuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", contraseña);
    
    // Apertura del Archivo.
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo users.txt.\n");
        exit(1);
    }
    
    // Verificación de Credenciales.
    while (fscanf(file, "%s %s", usuarioGuardado, contraseñaGuardada) != EOF) {
        if (strcmp(usuario, usuarioGuardado) == 0 && strcmp(contraseña, contraseñaGuardada) == 0) {
            printf("¡Inicio de sesión exitoso!\n");
            fclose(file);
            return 1;
        }
    }
    
    // Manejo de error y re intento.
    fclose(file);
    printf("Error: Usuario o contraseña incorrectos.\n");
    printf("¿Desea intentarlo de nuevo? (s/n): ");
    char respuesta;
    scanf(" %c", &respuesta);
    if (respuesta != 's') {
        exit(0);
    } else {
        return login();
    }
}


// ---------------- MENU OPCIONES (NO SWITCH CASE) ----------------
void mostrarMenu() {
    printf("\n=== Menú de opciones ===\n");
    printf("1. Listar Productos\n");
    printf("2. Vender Producto\n");
    printf("3. Comprar Producto\n");
    printf("4. Ventas del Día\n");
    printf("5. Salir\n");
}

int leerOpcion() {
    int opcion;
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    return opcion;
}


//---------------- LISTAR PRODUCTOS (OPCIÓN 1) ----------------
void listarProductos() {
    printf("-------Lista de productos------\n");
    printf("Productos disponibles:\n");
    for (int i = 0; i < 4; i++) {
        printf("Cod Producto: %d - ", productos[i][0]);
        switch(productos[i][0]) {
            case 123:
                printf("Camisa - ");
                break;
            case 456:
                printf("Pantalon - ");
                break;
            case 789:
                printf("Medias - ");
                break;
            case 234:
                printf("Chaqueta - ");
                break;
            default:
                printf("Desconocido - ");
        }
        printf("Precio x Und: %d - Unidades: %d\n", productos[i][1], productos[i][2]);
    }
    printf("->Deseas realizar otra operacion? (s/n) :");
    char respuesta;
    scanf(" %c", &respuesta);
    if (respuesta != 's') {
        exit(0);
    } else {
        return mostrarMenu();
    }
}

   
//---------------- VENDER PRODUCTOS (OPCIÓN 2) ----------------
void venderProducto() {
    int codProducto, unidades, medioPago;
    int productoEncontrado = 0;

    // Mostrar lista de productos
    printf("-------Lista de productos------\n");
    printf("Productos disponibles:\n");
    for (int i = 0; i < 4; i++) {
        printf("Cod Producto: %d - ", productos[i][0]);
        switch(productos[i][0]) {
            case 123:
                printf("Camisa - ");
                break;
            case 456:
                printf("Pantalon - ");
                break;
            case 789:
                printf("Medias - ");
                break;
            case 234:
                printf("Chaqueta - ");
                break;
            default:
                printf("Desconocido - ");
        }
        printf("Precio x Und: %d - Unidades: %d\n", productos[i][1], productos[i][2]);
    }

    // Solicitar información de venta
    printf("-›Ingrese cod de producto: ");
    scanf("%d", &codProducto);

    // Buscar el producto en la lista
    for (int i = 0; i < 4; i++) {
        if (productos[i][0] == codProducto) {
            productoEncontrado = 1;
            printf("-›Unidades: ");
            scanf("%d", &unidades);
            printf("-›Medio de pago 1 (Efectivo) - 2 (Tarjeta): ");
            scanf("%d", &medioPago);

            // Validar si las unidades a vender están disponibles.
            if (unidades <= productos[i][2] && unidades > 0) {
                int valorTotal = unidades * productos[i][1];
                
                // Actualizar dinero disponible y unidades disponibles.
                if (medioPago == 1) {
                    efectivo += valorTotal;
                } else if (medioPago == 2) {
                    tarjeta += valorTotal;
                } else {
                    printf("Medio de pago inválido.\n");
                    return;
                }
                productos[i][2] -= unidades;

                // Mostrar resumen de venta.
                printf("\n- Resumen --\n");
                printf("Accion: Venta\n");
                printf("Cod Producto: %d\n", productos[i][0]);
                switch(productos[i][0]) {
                    case 123:
                        printf("Producto: Camisa\n");
                        break;
                    case 456:
                        printf("Producto: Pantalon\n");
                        break;
                    case 789:
                        printf("Producto: Medias\n");
                        break;
                    case 234:
                        printf("Producto: Chaqueta\n");
                        break;
                    default:
                        printf("Producto: Desconocido\n");
                }
                printf("Unidades: %d\n", unidades);
                printf("Valor Unidad: %d\n", productos[i][1]);
                printf("Medio de pago: %d\n", medioPago);
                printf("Total Venta: %d\n", valorTotal);
                printf("Unidades anteriores: %d\n", unidades + productos[i][2]);
                printf("Unidades disponibles: %d\n", productos[i][2]);

                // Guardar información de la venta en ventas.txt.
                FILE *ventasFile = fopen("ventas.txt", "a");
                if (ventasFile != NULL) {
                    fprintf(ventasFile, "Accion: Venta\n");
                    fprintf(ventasFile, "Cod Producto: %d\n", productos[i][0]);
                    fprintf(ventasFile, "Producto: ");
                    switch(productos[i][0]) {
                        case 123:
                            fprintf(ventasFile, "Camisa\n");
                            break;
                        case 456:
                            fprintf(ventasFile, "Pantalon\n");
                            break;
                        case 789:
                            fprintf(ventasFile, "Medias\n");
                            break;
                        case 234:
                            fprintf(ventasFile, "Chaqueta\n");
                            break;
                        default:
                            fprintf(ventasFile, "Desconocido\n");
                    }
                    fprintf(ventasFile, "Unidades: %d\n", unidades);
                    fprintf(ventasFile, "Valor Unidad: %d\n", productos[i][1]);
                    fprintf(ventasFile, "Medio de pago: %d\n", medioPago);
                    fprintf(ventasFile, "Total Venta: %d\n", valorTotal);
                    fprintf(ventasFile, "--------------------------------\n");
                    fclose(ventasFile);
                } else {
                    printf("Error al guardar la información de la venta en ventas.txt.\n");
                }

                // Guardar información de la venta en ventasdia.txt.
                FILE *ventasDiaFile = fopen("ventasdia.txt", "a");
                if (ventasDiaFile != NULL) {
                    fprintf(ventasDiaFile, "medio pago: %d - valor venta: %d\n", medioPago, valorTotal);
                    fclose(ventasDiaFile);
                } else {
                    printf("Error al guardar la información de la venta en ventasdia.txt.\n");
                }
                break;
            } else {
                printf("Unidades no disponibles para este producto.\n");
                return;
            }
        }
    }

    // Si el producto no se encuentra.
    if (!productoEncontrado) {
        printf("Código de producto no válido.\n");
    }

     printf("->Deseas realizar otra operacion? (s/n) :");
    char respuesta;
    scanf(" %c", &respuesta);
    if (respuesta != 's') {
        exit(0);
    } else {
        return mostrarMenu();
    }
}


//---------------- COMPRAR PRODUCTOS (OPCIÓN 3) ----------------
void comprarProducto() {
    int codProducto, unidades, valorUnidad, medioPago;
    int productoEncontrado = 0;

    // Mostrar lista de productos
    printf("---comprar producto---\n");
    printf("Productos disponibles:\n");
    for (int i = 0; i < 4; i++) {
        printf("  Cod Producto: %d - ", productos[i][0]);
        switch(productos[i][0]) {
            case 123:
                printf("Camisa - ");
                break;
            case 456:
                printf("Pantalon - ");
                break;
            case 789:
                printf("Medias - ");
                break;
            case 234:
                printf("Chaqueta - ");
                break;
            default:
                printf("Desconocido - ");
        }
        printf("Precio x Und: %d - Unidades: %d\n", productos[i][1], productos[i][2]);
    }

    // Mostrar total en efectivo y tarjeta
    printf("\nTotal en efectivo: %.2lf - Total en tarjeta: %.2lf\n", efectivo, tarjeta);

    // Solicitar información de compra
    printf("\n-›Ingrese cod de producto: ");
    scanf("%d", &codProducto);

    // Buscar el producto en la lista
    for (int i = 0; i < 4; i++) {
        if (productos[i][0] == codProducto) {
            productoEncontrado = 1;
            printf("-›Unidades: ");
            scanf("%d", &unidades);
            printf("->Valor unidad: ");
            scanf("%d", &valorUnidad);
            printf("-›Medio de pago 1 (Efectivo) - 2 (Tarjeta): ");
            scanf("%d", &medioPago);

            // Validar datos de compra
            if (unidades > 0 && valorUnidad < productos[i][1]) {
                int valorTotal = unidades * valorUnidad;
                if ((medioPago == 1 && valorTotal <= efectivo) || (medioPago == 2 && valorTotal <= tarjeta)) {
                    // Actualizar dinero disponible y unidades disponibles
                    if (medioPago == 1) {
                        efectivo -= valorTotal;
                    } else {
                        tarjeta -= valorTotal;
                    }
                    productos[i][2] += unidades;

                    // Mostrar resumen de compra
                    printf("\n-- Resumen --\n");
                    printf("Accion: Compra producto\n");
                    printf("cod Producto: %d\n", productos[i][0]);
                    switch(productos[i][0]) {
                        case 123:
                            printf("Producto: Camisa\n");
                            break;
                        case 456:
                            printf("Producto: Pantalon\n");
                            break;
                        case 789:
                            printf("Producto: Medias\n");
                            break;
                        case 234:
                            printf("Producto: Chaqueta\n");
                            break;
                        default:
                            printf("Producto: Desconocido\n");
                    }
                    printf("Unidades: %d\n", unidades);
                    printf("Valor Unidad: %d\n", valorUnidad);
                    printf("Medio de pago: %d\n", medioPago);
                    printf("Total Compra: %d\n", valorTotal);
                    printf("Unidades anteriores: %d\n", productos[i][2] - unidades);
                    printf("Unidades disponibles: %d\n", productos[i][2]);
                    printf("Total en efectivo: %.2lf - Total en tarjeta: %.2lf\n", efectivo, tarjeta);

                    // Guardar información de la compra en compras.txt
                    FILE *comprasFile = fopen("compras.txt", "a");
                    if (comprasFile != NULL) {
                        fprintf(comprasFile, "-- Resumen --\n");
                        fprintf(comprasFile, "Accion: Compra producto\n");
                        fprintf(comprasFile, "cod Producto: %d\n", productos[i][0]);
                        fprintf(comprasFile, "Producto: ");
                        switch(productos[i][0]) {
                            case 123:
                                fprintf(comprasFile, "Camisa\n");
                                break;
                            case 456:
                                fprintf(comprasFile, "Pantalon\n");
                                break;
                            case 789:
                                fprintf(comprasFile, "Medias\n");
                                break;
                            case 234:
                                fprintf(comprasFile, "Chaqueta\n");
                                break;
                            default:
                                fprintf(comprasFile, "Desconocido\n");
                        }
                        fprintf(comprasFile, "Unidades: %d\n", unidades);
                        fprintf(comprasFile, "Valor Unidad: %d\n", valorUnidad);
                        fprintf(comprasFile, "Medio de pago: %d\n", medioPago);
                        fprintf(comprasFile, "Total Compra: %d\n", valorTotal);
                        fprintf(comprasFile, "--------------------------------\n");
                        fclose(comprasFile);
                    } else {
                        printf("Error al guardar la información de la compra en compras.txt.\n");
                    }
                    break;
                } else {
                    printf("Dinero insuficiente en el medio de pago seleccionado.\n");
                    return;
                }
            } else {
                printf("Unidades o valor de unidad inválidos.\n");
                return;
            }
        }
    }

    // Si el producto no se encuentra
    if (!productoEncontrado) {
        printf("Código de producto no válido.\n");
    }

      printf("->Deseas realizar otra operacion? (s/n) :");
    char respuesta;
    scanf(" %c", &respuesta);
    if (respuesta != 's') {
        exit(0);
    } else {
        return mostrarMenu();
    }
}


//---------------- MOSTRAR VENTAS DEL DIA (OPCIÓN 4) ----------------
void mostrarVentasDelDia() {
    FILE *archivoVentasDia = fopen("ventasdia.txt", "r");
    if (archivoVentasDia == NULL) {
        printf("No hay ventas registradas en el día.\n");
        return;
    }

    char linea[100]; // Suponemos que cada línea tiene como máximo 100 caracteres
    while (fgets(linea, sizeof(linea), archivoVentasDia) != NULL) {
        printf("%s", linea);
    }

    fclose(archivoVentasDia);

    // Mostrar total en efectivo y en tarjeta
    double totalEfectivo = 20000.0; // Total en efectivo 
    double totalTarjeta = 10000.0; // Total en tarjeta 
    printf("Total en efectivo: %.2lf - Total en tarjeta: %.2lf\n", totalEfectivo, totalTarjeta);

    // Preguntar al usuario si desea realizar otra operación
    char opcion;
    printf("-›Deseas realizar otra operacion? (S/N): ");
    scanf(" %c", &opcion);
    if (opcion == 'S' || opcion == 's') {
        return;
    } else {
        exit(0);
    }
}

//CODIGO REALIZADO POR JERONIMO MAPE SOTO - 1088826255 - PROGRAMACIÓN II