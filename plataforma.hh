/** @file plataforma.hh
 *  @brief especificacion de la clase plataforma
 */

#ifndef PLATAFORMA_HH
#define PLATAFORMA_HH


#ifndef NO_DIAGRAM
#include<iostream>
#include<vector>
#include<set>
#include<map>
#endif
#include"cjt_cursos.hh"
#include"cjt_problemas.hh"
using namespace std;

/** @class plataforma
 *  @brief representa la plataforma evaluator y todas sus funcionalidades.
 */
class plataforma
{
private:
    /** 
     * @brief estructura que guarda el conjunto de cursos de la plataforma.
    */
  cjt_cursos curso_data_base;
   /** 
     * @brief estructura que guarda el conjunto de problemas de la plataforma.
    */
  cjt_problemas problema_data_base;
   /** 
     * @brief estructura que guarda el conjunto de sesiones de la plataforma.
    */
  cjt_sesiones sesion_data_base;
   /** 
     * @brief estructura que guarda el conjunto de usuarios de la plataforma.
    */
  cjt_usuarios usuarios_data_base;
public:
    
    /** @brief constructora de la clase plataforma.
     *  \pre <em>cierto</em>.
     *  \post crea una plataforma vacía.
    */
    plataforma();
    
    /** @brief hace una lectura inicial de un conjunto de problemas, sesiones, cursos y usuarios
     *  \pre enteros P > 0, Q > 0, N > 0 y M > 0 haciendo referencia al numero de problemas, sesiones, cursos y usuarios que hay registrados inicialmente.
     *  Los datos deben de estar preparados en terminal.
     *  \post los atributos pasan a tener los datos recibidos por terminal.
    */
    void lectura_inicial();

    /** @brief añade un nuevo problema con identificador <b>p</b>.
     *  \pre <em>cierto</em>.
     *  \post  añade un problema nuevo con identificador p.  Si ya existía un problema en la plataforma con el
     *   mismo identificador se imprime un mensaje de error. En caso contrario se imprime el numero de problemas en la colección.
     * 
    */
    void nuevo_problema(string p);

    /** @brief añade una sesión nueva con identificador <b>s</b>.
     *  \pre los datos de la estructura de los problemas de la sesion
     *  deben de estar cargados en la terminal .
     *  \post si ya existía una sesión en la plataforma con el mismo identificador se imprime un mensaje de error. En caso contrario
        se imprime el número de sesiones Q en el repositorio después de añadirla.
    */
    void nueva_sesion(string s);

    /** @brief añade un nuevo curso con identificador N + 1.
     *  \pre se lee un numero de sesiones <b>S</b> y luego una secuencia de identificadores de sesiones validos.
     *  \post si no hay interseccion entre sesiones se añade el curso y se muestra en pantalla su identificador
     *  en caso contrario se muestra un mensaje de error.
    */
    void nuevo_curso();

    /** @brief registra un usuario nuevo con identificador <b>u</b>.
     *  \pre <em>cierto</em>.
     *  \post si ya existía un usuario en la plataforma con el mismo identificador se imprime un mensaje de error. En caso contrario se imprime el
        número de usuarios registrados.

    */
    void alta_usuario(string u);

    /** @brief da de baja un usuario con identificador <b>u</b>.
     *  \pre <em>cierto</em>.
     *  \post Si no existe un usuario en la plataforma con identificador.
     *  se imprime un mensaje de error. En caso contrario, se imprime el numero de usuarios registrados.
    */
    void baja_usuario(string u);

    /** @brief inscribe un usuario <b>u</b> en el curso con identificador <b>c</b>.
     *  \pre <em>cierto</em>.
     *  \post  si el usuario u o el curso <b>c</b> no existen.
     *  en la plataforma o <b>u</b> ya está inscrito en otro curso que no ha sido completado, se
     *  imprime un mensaje de error. En caso contrario se imprime el numero de usuarios inscritos en el curso.
    */
    void inscribir_curso(string u, int c);

    /** @brief consulta el curso en el que está inscrito un usuario <b>u</b>.
     *  \pre <em>cierto</em>.
     *  \post  si el usuario <b>u</b> no existe en la plataforma.
     *  se imprime un mensaje de error. En caso contrario, se imprime el identificador del
     *  curso o un cero si no está inscrito en ningún curso.

    */
    void curso_usuario(string u);

    /** @brief consulta la sesión del problema <b>p</b> en el curso con identificador <b>c</b>.
     *  \pre <em>cierto</em>.
     *  \post si el curso <b>c</b> no existe o si el problema <b>p</b> no existe o no pertenece al curso,
     *  se imprime un mensaje de error. En caso contrario, se imprime el identificador de la sesión donde
     *  se realiza el problema <b>p</b> en el curso <b>c</b>.

    */
    void sesion_problema(int c, string p);

    /** @brief se listan en orden creciente por identificador los 
     *  problemas solucionados con éxito por el usuario <b>u</b> junto a los envíos hechos.
     *  \pre <em>cierto</em>.
     *  \post si el usuario u no existe en la plataforma, se imprime un mensaje de error.
    */
    void problemas_resueltos(string u);

    /** @brief se listan orden creciente los problemas no completados del usuario y que cumple los prerequisitos del problema.
     *  \pre <em>cierto</em>.
     *  \post se imprime el identificador de los problema, como sus envios.Si el
     *  usuario u no existe en la plataforma, se imprime un mensaje de error.
    */
   void problemas_enviables(string u);

    /** @brief se hace un envio de un usuario <b>u</b> a un problema <b>p</b> y con solucion <b>r</b>.
     *  \pre se garantiza que el usuario existe y puede hacer envíos al problema <b>p</b>.
     *  \post tras un envío se actualiza las estadisticas del usuario y del problema. Si es r = 1,
     *  tambien se actualiza los problemas resueltos y enviables y se comprueba si el curso esta completado
     *  y deja de formar parte del curso actual si lo ha completado.
    */
    void envio(string u, string p, int r);

    /** @brief se listan los problemas de la coleccion.
     *  \pre <em>cierto</em>.
     *  \post se indica para cada problema, el numero de envios totales <b>t</b>
     *  y envíos correctos <b>e</b>. Y se lista crecientemente en funcion de
     *  (<b>t</b> + 1)/(<b>e</b> + 1) de cada problema. En caso de empate se hara 
     *  por orden creciente del identificador. Tambien se mostrara los envios totales y correctos
     *  a cada problema.
    */
    void listar_problemas();

    /** @brief se muestra las estadisticas de un solo problema <b>p</b>.
     *  \pre <em>cierto</em>.
     *  \post si <b>p</b> no existe muestra un mensaje de error.
    */
    void escribir_problema(string p);

    /** @brief se listan las sesiones actuales de la plataforma.
     *  \pre <em>cierto</em>.
     *  \post se listan sesiones en orden creciente de identificador y mostrando el numero de problemas
     *  de cada sesion y el listado de problemas en postorden de requisitos.
    */
    void listar_sesiones();

    /** @brief se muestra las estadisticas de una sesion.
     *  \pre <em>cierto</em>.
     *  \post si <b>s</b> no existe se muestra un mensaje de error. En caso contrario se muestra el numero
     *  de problemas de la sesion y la lista de problemas en postorden de prerequisitos.
    */
    void escribir_sesion(string s);

    /** @brief se listan los cursos actuales de la plataforma.
     *  \pre <em>cierto</em>.
     *  \post se listan los cursos en orden creciente de identificador a la vez de el número de usuarios pasados que lo han completado,
     *  el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas
        sesiones, en el mismo orden en el que se leyeron cuando se creó el curso.
    */
    void listar_cursos();

    /** @brief se muestra la estadistica de un curso.
     *  \pre <em>cierto</em>.
     *  \post se muestra el número de usuarios pasados que lo han completado, el número de usuarios inscritos 
     *  actualmente, el número de sesiones que lo forman y los identificadores de dichas 
     *  sesiones, en el mismo orden en el que se leyeron cuando se creó el curso. Si no existe el curso <b>c</c> se muestra un mensaje de error.
    */
    void escribir_curso(int c);

    /** @brief se listan los usuarios registrados actualmente en la plataforma.
     *  \pre <em>cierto</em>.
     *  \post se listan en orden creciente de identificador y mostrando el numero total de envios
     *  realizados. Tambien el numero de problemas resueltos y el numero de problemas
     *  que ha hecho un envío y el identificador del curso que esta actualmente (0 si no esta inscrito en uno).
    */
    void listar_usuarios();

    /** @brief se muestra las estadisticas de un usuario.
     *  \pre <em>cierto</em>.
     *  \post se muestra el numero total de envios realizados y envios correctos. Tambien el numero de problemas resueltos y el numero de problemas
     *  que ha hecho un envío y el identificador del curso que esta actualmente (0 si no esta inscrito en uno).
     *  Si <b>u</b> no existe en el conjunto de usuarios, se muestra un mensaje de error.
    */
    void escribir_usuario(string u);
};
#endif