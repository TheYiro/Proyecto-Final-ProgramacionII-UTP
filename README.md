# ALMACEN LAS MECHAS 🛍️

![image](https://github.com/TheYiro/Proyecto-Final-ProgramacionII-UTP/assets/71678926/b4cc3de6-d083-4232-9c6d-03034f4c8ba3)

<h1 align="center">
  
**Lenguaje:** ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
  
</h1>

---

## Índice

- [Descripción](#descripción)
- [Instalación](#instalación)
- [Uso](#uso)
- [Funciones Principales](#funciones-principales)
  - [Login](#login)
  - [Mostrar Menú](#mostrar-menú)
  - [Listar Productos](#listar-productos)
  - [Vender Producto](#vender-producto)
  - [Comprar Producto](#comprar-producto)
  - [Mostrar Ventas del Día](#mostrar-ventas-del-día)
- [Ejemplo de Ejecución](#ejemplo-de-ejecución)
- [Créditos](#créditos)
- [Imágenes](#imágenes)
- [Estructura](#estructura)

---

## Descripción

Este proyecto es una aplicación para la gestión de un almacén, desarrollado en C por Jerónimo Mape Soto para la asignatura de Programación II. La aplicación permite listar productos, vender, comprar, y mostrar ventas del día, todo ello a través de un sistema de menús interactivos.

---

## Instalación

Para compilar y ejecutar el proyecto, siga estos pasos:

1. Clonar el repositorio:
    ```bash
    git clone https://github.com/tuusuario/almacen-las-mechas.git
    cd almacen-las-mechas
    ```
2. Compilar el código:
    ```bash
    gcc main.c -o almacen-las-mechas
    ```
3. Ejecutar la aplicación:
    ```bash
    ./almacen-las-mechas
    ```
---

## Uso

Al iniciar la aplicación, se mostrará un menú con las siguientes opciones:

1. Listar Productos
2. Vender Producto
3. Comprar Producto
4. Ventas del Día
5. Salir

Seleccione la opción deseada ingresando el número correspondiente y siga las instrucciones en pantalla.

---

## Funciones Principales

### Login

Solicita al usuario ingresar su nombre de usuario y contraseña. Verifica las credenciales contra un archivo `users.txt`.

### Mostrar Menú

Muestra el menú principal con las opciones disponibles para el usuario.

### Listar Productos

Muestra una lista de los productos disponibles en el almacén con su código, nombre, precio y unidades disponibles.

### Vender Producto

Permite al usuario vender un producto, actualizando el inventario y los registros de ventas.

### Comprar Producto

Permite al usuario comprar un producto, actualizando el inventario y los registros de compras.

### Mostrar Ventas del Día

Muestra un resumen de las ventas realizadas durante el día, incluyendo el total de ventas en efectivo y tarjeta.

---

## Ejemplo de Ejecución

```plaintext
 ╔════════════════════════════════════════════╗
 ■     LOGIN ALMACEN LAS MECHAS by Jero       ■
 ╚════════════════════════════════════════════╝
Ingrese su usuario: admin
Ingrese su contraseña: ****
¡Inicio de sesión exitoso!

 ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 |     Welcome to ALMACEN LAS MECHAS      |
 ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

=== Menú de opciones ===
1. Listar Productos
2. Vender Producto
3. Comprar Producto
4. Ventas del Día
5. Salir
Seleccione una opción:
```

---

## Estructura

```plaintext
almacen-las-mechas/
│   ├── main.c
│   ├── users.txt
│   ├── ventas.txt
│   ├── ventasdia.txt
└── ├── compras.txt
```
---

## Créditos

Código realizado por Jerónimo Mape Soto - 1088826255 - Programación II. - Universidad Tecnologica de Pereira (UTP).

---

## Imágenes
![image](https://github.com/TheYiro/Proyecto-Final-ProgramacionII-UTP/assets/71678926/fdb36892-6308-49fc-bd56-97e1ae7524c3)
<br> *users.txt - Información de validación de credenciales.* </br>

![image](https://github.com/TheYiro/Proyecto-Final-ProgramacionII-UTP/assets/71678926/294e3f67-8f00-4550-b87c-aaa34c631db7)
<br>*ventas.txt - Ventas realizadas desde el codigo alamacenadas con su template.* </br>

![image](https://github.com/TheYiro/Proyecto-Final-ProgramacionII-UTP/assets/71678926/72c0801f-41ea-4ca7-84f8-e87ba0668163)
<br>*ventasdia.txt - Ventas realizadas desde otra opción del menú del codigo, se llena con su debia template.* </br>

![image](https://github.com/TheYiro/Proyecto-Final-ProgramacionII-UTP/assets/71678926/4fd2f572-61e6-4fa4-a4dc-ecd937fe7efa)
<br>*compras.txt - Informe de compras realizadas y almacenadas con su debida template.* </br>

<h3 align="center"> By: 𝒥𝑜𝒶𝒸𝑜✨ </h3>

