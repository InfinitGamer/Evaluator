/** @file curso.hh
 *  @brief especificacion de la clase curso
*/
#ifndef CURSO_HH
#define CURSO_HH



#ifndef NO_DIAGRAM

#include<vector>
#include<iostream>
#include<set>
using namespace std;
#endif
#include "cjt_sesiones.hh"
/** @class curso
 *  @brief representa el contenido de un curso. Esta conformado por un identifcador y un vector de
 *  las sesiones que contiene.
 */


class curso
{
private:
    /** 
     * @brief contador de usuarios que han completado el curso.
    */
    int usuarios_actuales;
    /** 
     * @brief contador de usuarios que estan actualmente cursando el curso.
    */
    int usuarios_totales;
    /** 
     * @brief estructura que guarda el identificador de las sesiones del curso
     * en orden en el que fueron añadidos.
    */
    vector<string> sesiones;
    /** 
     * @brief estructura que guarda por cada problema del curso, 
     * la sesion a la que pertence.
    */
    map<string, string> problema_sesion;
public:

     /** @brief constructora de la clase curso.
     *  \pre <em>cierto</em>.
     *  \post crea un curso con cero usuarios actuales y cero usuarios que lo han completado.
    */
    curso();
//consultoras

    /** @brief devuelve el numero de sesiones que tiene el curso. 
     * \pre <em>cierto</em>.
     * \post devuelve un numero entero >= 0 correspondiente al numero de sesiones.
    */
    int numero_sesiones()const;
    
    /** @brief muestra la string de la sesion que esta en una cierta posicion.
     * \pre <b>i</b> debe de estar contenido entre [1, longitud del vector]
     * \post devuelve la string de la sesion correspondiente a la posicion <b>i</b>
    */
    string mostrar_sesion_curso(int i)const ;
    
    /** @brief muestra el numero de usuarios actualmente cursando el curso.
     *  \pre <em>cierto<em>.
     *  \post devuelve int correspondiente al numero de usuarios actuales en el objeto implicito.
     */
    int mostrar_usuarios_actuales()const;
    
    /** @brief muestra el numero de usuarios que han completado el curso.
     *  \pre <em>cierto<em>.
     *  \post devuelve int correspondiente al numero de usuarios que han cursado el objeto implicito.
     */
    int mostrar_usuarios_totales()const;

    /** @brief se lista el curso.
     *  \pre <em>cierto<em>.
     *  \post se lista el objeto implicito, dando información sobre el numero
     *  de sesiones que contiene y se listan las sesiones en orden en que fueron 
     *  introducidas.
     */
    void listar_curso();
    
    /** @brief accion de un usuario al completar el curso.
     *  \pre <em>cierto<em>.
     *  \post se transfiere un usuario que estaba cursando el objeto implicito a usuarios
     *  que lo han completado. 
     */
    void curso_completado();
    
    /** @brief se muestra la sesion a la que pertenece un determinado problema.
     *  \pre <em>cierto<em>.
     *  \post si problema <b>p</b> pertenece al curso, devolverá una string correspondiente
     *  al nombre de la sesion en la que esta. Si no existe en el curso el problema <b>p</b>
     *  se dará una string "-1" correspondiente a la no existencia de este en el curso.
     */
    string i_sesion_problema (string p);

// modificadoras

    /** @brief el objeto implicito pasa a tener <b>s</b> sesiones, pasadas por terminal .
     * \pre <b>s</b> >= 0. Los datos deben de estar preparados en la terminal.
     * \post el objeto pasa a tener los datos de la terminal en los atributos. También será true
     * si el objeto implicito no tiene interseccion de problemas. False en caso contrario.
    */
    bool leer_curso(int s, const cjt_sesiones& a);
   
    /** @brief se añade un usuario que esta cursando actualmente el curso.
     *  \pre <em>cierto<em>.
     *  \post el objeto implicito pasa a tener un usuario más que esta actualmente
     *  cursando el curso.
     */
    void anadir_usuario();
   
    /** @brief se elimina un usuario que actualmente esta cursando el curso.
     *  \pre <em>cierto<em>.
     *  \post el objeto implicito pasa a tener un usuario menos cursandolo .
     */
    void eliminar_usuario();
   
    
};



#endif