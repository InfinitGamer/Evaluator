/** @file cjt_cursos.hh
 *  @brief especificacion de la clase conjunto de cursos
*/
#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

#include "curso.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include<vector>
using namespace std;
#endif

/** @class cjt_cursos
 *  @brief representa un conjunto de cursos ordenados en funcion de 
 * cuando son añadidos los cursos  
 */
class cjt_cursos
{
private:
/**
 * @brief estructura para guardar cursos en función
 * del momento en que han sido añadidos.
*/
   vector<curso> cursos;
public:
    /** @brief constructora de la clase conjunto de cursos.
     *  \pre <em>cierto</em>.
     *  \post crea un conjunto de cursos vacío.
    */
    cjt_cursos();
// consultoras

    /** @brief muestra si existe en el conjunto de cursos un curso en especifico.
     *  \pre <em>cierto</em>.
     *  \post devuelve true si existe curso con identificador <b>i</b>. False en caso contrario.  
    */
    bool existe_curso(int i)const;
    
    /** @brief muestra el curso correspondiente al identificador <b>i</b>.
     *  \pre el parametro implicito <b>a</b> debe de aparecer en el objeto.
     *  \post se devuelve curso correspondiente al identificador <b>i</b>.
    */
    void mostrar_curso(int i, curso& a)const;

    /** @brief muestra el numero de cursos que tiene el objeto implicito.
     *  \pre <em>cierto</em>.
     *  \post devuelve un int correspondiente al numero de cursos del objeto implicito.
    */
    int numero_cursos() const;

    /** @brief lista en pantalla el objeto implicito.
     *  \pre <em>cierto</em>.
     *  \post se lista por pantalla el objeto implicito en funcíon de la antiguedad del curso
     *  a este se muestra el numero de usuarios que han completado el curso, usuarios cursando el curso,
     *  numero de sesiones que conforman cada curso y el listado de sesiones de este.
    */
    void listar_cursos();

    /** @brief muestra la sesion correspondiente a un curso y un problema concreto.
     *  \pre <em>cierto</em>.
     *  \post se devuelve una string correspondiente a la sesion que contiene el problema
     *  con identificador <b>p</b>, en caso que no exista se devuelve <em>-1</em> en formato string.
    */
    string sesion_problema(int c, string p);

    /** @brief muestra los usuarios que estan cursando un curso determinado.
     *  \pre <b>c</b> debe de pertenecer al objeto implicito.
     *  \post devuelve un int correspondiente al numero de usuarios actuales de curso <b>c</b>.
    */
    int i_mostrar_usuarios_actuales(int c) const;

    /** @brief muestra las estadisticas de un curso determinado.
     *  \pre <b>c</b> debe de pertenecer al objeto implicito.
     *  \post se muestra el identificador del curso, junto al numero de usuarios que 
     *  completaron el curso, el numero de usuarios actualmente inscrito en curso, el 
     *  numero de sesiones que lo componen y por ultimo se lista este.
    */
    void i_escribir_curso(int c);

// modificadoras

    /** @brief añade un curso al conjunto de cursos.
     *  \pre el parametro implicito <b>a</b> no debe de aparecer en el objeto.
     *  \post el objeto pasa a tener un nuevo elemento con identificador <b>a</b> en el objeto implicito.
    */
    void anadir_curso(curso& a);
    
    /**  @brief actualiza un curso con su nueva información.
     *   \pre el curso con identificador<b>c</b> debe de estar incluido en el objeto implicito.
     *   \post el objeto implicito pasa a tener el parametro <b>a</b> como atributo de <b>c</b>.
    */
    void modificar_curso(int c, curso& a);
    
    /** @brief se añade un usuario mas al numero de personas que han completado el curso <b>c</b> .
     *  \pre curso <b>c</b> debe de existir en el objeto implicito.
     *  \post curso <b>c</b> se modifica con un usuario mas que lo ha completado.
    */
    void i_completar_curso(int c);
    
    /** @brief se añade un usuario mas que va a cursar un curso determinado.
     *  \pre <b>c</b> debe de pertenecer al objeto implicito.
     *  \post se añade al curso <b>c</b> un usuario que va estar cursando el curso.
    */
    void i_anadir_usuario(int c);
    
    /** @brief añade a un usuario determinado, los primeros problemas 
     *  disponibles de un curso en el que esta inscrito.
     *  \pre el conjunto de usuarios <b>a</b> debe de contener el usuario <b>u</b>. A su vez, 
     *  <b>c</b> debe de estar presente en el objeto implicito. Por ultimo
     *  <b>b</b> debe de contener todas las sesiones que contiene el curso <b>c</b>.
     *  \post usuario <b>u</b> pasa a tener modificado los problemas enviables con los correspondientes
     *  al curso <b>c</b>.
    */
    void i_anadir_enviables_curso(cjt_usuarios& a, cjt_sesiones& b,string u, int c);
    
    /** @brief elimina de un curso en especifico un usuario que estaba cursando un curso.
     *  \pre <b>c</b> debe de pertenecer al objeto implicito.
     *  \post curso <b>c</b> pasa a tener un usuario menos cursando el curso <b>c</b>.
    */
    void i_eliminar_usuario(int c);
    
    

};




#endif