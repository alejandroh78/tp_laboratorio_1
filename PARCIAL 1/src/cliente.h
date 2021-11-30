

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define OCUPADO 1
#define VACIO 0
#define TAMCLI 100
#define TAMLOC 5

typedef struct
{
    int id;
    char nombre[51];
    char cuit[12];
    char direccion[100];
    int idlocalidad;
    int isEmpty;
}eCliente;


typedef struct
{
    int id;
    char nombre[51];
    int isEmpty;
}eLocalidad;

/// @fn int initCliente(eCliente[], int)
/// @brief Funcion que blanquea todas las posiciones del array clientes
///        colocando la bandera isEmpty en TRUE.
///
/// @param listCliente array de clientes
/// @param lenCliente longitud del array clientes
/// @return
int initCliente(eCliente listCliente[],int lenCliente);

/// @fn int getNuevoClienteId()
/// @brief genera un nuevo ID de Cliente.
///
/// @return el id de cliente generado
int getNuevoClienteId();

/// @fn int altaCliente(eCliente[], int, int, char[], char[], char[], char[])
/// @brief Agregar un cliente con los valores cargados como parametros
///        en el primer lugar vacio de la lista ingresada.
///
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @param id el ID de Cliente
/// @param nombre del cliente
/// @param cuit del cliente
/// @param direccion del cliente
/// @param localidad del cliente
/// @return
int altaCliente(eCliente listCliente[], int lenCliente, int id, char nombre[],  char cuit[], char direccion[], int idLocalidad);

/// @fn int bajaCliente(eCliente[], int, int)
/// @brief Dar de baja un cliente de la lista de array mediante su ID
///      informando el campo isEmpty como vacio.
///
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @param id ID Cliente
/// @return   [-1] Si hubo un error para borrar el Cliente de la lista.
///           [0] Si Cleinte se borro.
int bajaCliente(eCliente listCliente[],int lenCliente, int id);

/// @fn int buscarClienteId(eCliente[], int, int)
/// @brief Obtiene el indice del array de Cliente el ID ingresado como parametro.
///
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @param id ID del cliente
/// @return  [-1] Si no encuentra el ID del cliente ingresado.
///          Encuentra el indice del cliente buscado.
int buscarClienteId(eCliente listCliente[], int lenCliente, int id);

/// @fn int mostrarClientes(eCliente[], int)
/// @brief muestra el listado de clientes
///
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @return   [-1] Si no hay clientes.
///           [0] muestra la lista.
int mostrarClientes(eCliente listCliente[], int lenCliente, eLocalidad listLocalidad[], int lenLocalidad);

/// @fn void mostrarCliente(eCliente)
/// @brief muesta un cliente
///
/// @param listCliente dato del cliente
void mostrarCliente(eCliente listCliente, eLocalidad listLocalidad[], int lenLocalidad);

/// @fn int checkClienteExiste(eCliente[], int)
/// @brief valida si existen clientes
///
/// @param listCliente array del cliente
/// @param lenCliente longitud del array cliente
/// @return    [1] Si existe.
///            [0] si no existe.
int checkClienteExiste(eCliente listCliente[], int lenCliente);

/// @fn int buscarNombreClienteId(char*, eCliente[], int, int)
/// @brief
///
/// @param nombreCliente retorna el nombre del cliente
/// @param listCliente array del cliente
/// @param lenCliente longitud del array cliente
/// @param idCliente ID del cliente
/// @return   [-1] Si no existe elclientes.
///            [0] existe el cliente.
int buscarNombreClienteId(char* nombreCliente, eCliente listCliente[], int lenCliente, int idCliente);

/// @fn void clientesHardcode(eCliente[], int, int)
/// @brief datos precargados de clientes
///
/// @param listCliente array del cliente
/// @param lenCliente longitud del array cliente
/// @param quantity cantidad de clientes
void clientesHardcode(eCliente listCliente[], int lenCliente, int quantity);
void localidadesHardcode(eLocalidad listLocalidad[], int length, int quantity);
int mostrarLocalidades(eLocalidad listLocalidad[], int lenLocalidad);
int buscarLocalidadId(eLocalidad listLocalidad[], int lenlocalidad, int idLocalidad, char* localidadNombre[]);
#endif /* CLIENTE_H_ */
