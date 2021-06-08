/** @file cjt_usuarios.hh
 *  @brief especificacion de la clase conjunto de usuarios
*/

#ifndef CJT_USUARIO_HH
#define CJT_USUARIO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
#include "usuario.hh"
using namespace std;


/** @class cjt_usuarios
 *  @brief Representa un conjunto de usuarios que estan ordenados por su identificador.
 */

class cjt_usuarios
{
private:
/**
 * @brief estructura que guarda un conjunto de usuarios
 * ordenados alfabeticamente por su identificador.
*/
    map<string, usuario> conjunto_usuario;
public:

    /** @brief constructora de la clase conjunto de usuarios.
     *  \pre <em>cierto</em>.
     *  \post crea un conjunto de usuarios vacío.
    */
    cjt_usuarios();
    
//consultoras

    /** @brief muestra si existe un usuario en especifico en el conjunto.
     *  \pre <em>cierto</em>.
     *  \post devuelve true si existe un usuario con identificador <b>u</b>. False
     *  en caso contrario.
     */
    bool existe_usuario(string u)const;
    
    /** @brief muestra un usuario en especifico. 
     *  \pre el usuario con identificador <b>u</b> tiene que existir en el objeto.
     *  \post muestra el usuario que tiene como identificador <b>u</b>.
     */
    void mostrar_usuario(string u, usuario& a);

    /** @brief muestra el numero de usuarios que hay en el conjunto.
     *  \pre <em>cierto</em>.
     *  \post devuelve un int correspondiente al numero de usuarios
     *  del objeto implicito.
     */
    int numero_usuario() const;

    /** @brief se listan los usuarios del conjunto.
     *  \pre <em>cierto</em>.
     *  \post se muestra en orden creciente los usuarios del objeto implicito
     *  mostrando por cada usuarioel numero de envios totales, numero de problemas completados,
     *  numero de problemas con un envío y el curso actual (se muestra 0 si no esta inscrito en ningun curso).
     */
    void listar_usuarios();

    /** @brief muestra si un usuario pertenece un curso (haber completado su ultimo curso).
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post se devuelve true si el usuario <b>u</b> conforme pertenece a un curso, false en
     *  caso contrario.
     */
    bool i_curso_completado(string u);

    /** @brief muestra si un usuario concreto del conjunto tiene un problema concreto completado.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post devuelve true si el problema <b>p</b> es un problema completado por el usuario <b>u</b>.
     */
    bool i_existe_en_completados(string u, string p) const;

    /** @brief devuelve el curso actual de un usuario en especifico.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post de vuelve un numero > 0 si el usuario esta inscrito a un curso. En caso de que 
     *  no este inscrito a un curso, se devuelve 0.
     */
    int i_curso_actual(string u);

    /** @brief lista los problemas enviables de un usuario.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post se listan por orden creciente de identificador
     *  los problemas enviables del usuario <b>u</b> mostrando el numero de envios
     *  a cada problema.
     *  
     */
    void i_listar_enviables(string u);
   
     /** @brief lista los problemas completados de un usuario.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post se listan por orden creciente de identificador
     *  los problemas completados por el usuario <b>u</b> mostrando el numero de envios
     *  a cada problema.
     *  
     */
    void i_listar_completados(string u);
 
    /** @brief se muestran por pantalla las estadisticas de un usuario.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto.
     *  \post se muestra el identificador del usuario junto al numero de envios que ha realizado,
     *  el numero de problemas completados, el numero de problemas que ha hecho un envío y por ultimo
     *  el curso actual. Si no esta cursando ningun curso, se mostrará 0.
     *  
     */
    void i_escribir_usuario(string u);

//modificadoras

    /** @brief añade un usuario al objeto.
     * \pre no debe de existir un usuario con identificador <b>u</b> en el objeto implicito. 
     * \post el parametro implicito <b>u</b> pasa a estar en el objeto.
     * 
    */
    void anadir_usuario(string u);
   
    /** @brief  elimina un usuario del objeto.
     *  \pre el usuario con identificador <b>u</b> tiene que existir en el objeto.
     * \post el usuario <b>u</b> ya no pertence en el objeto.
    */
    void eliminar_usuario(string u);
  
    /** @brief se modifica una sesion en especifico.
     *  \pre debe de existir en el objeto un usuario con identificador <b>a</b>.
     *  \post el usuario <b>a</b> es modificado con los atributos del parametro <b>b</b>.
     */
    void modificar_usuario(string a, usuario& b);
  
    /** @brief se anade un envio al usuario correspondiente.
     *  \pre el usuario <b>u</b> debe de existir en el conjunto. El problema <b>p</b>
     *  debe pertenecer a los problemas enviables por el usuario.
     *  <b>r</b> debe ser un numero comprendido entre [0,1].
     *  \post Si r = 0, se le añadira un intento al problema <b>p</b> y devolverá un int nulo (0). 
     *  En caso de r = 1, se añadira un intento, pasara a formar parte de problemas completados
     *  y devolverá un int correspondiente al curso que formaba parte el usuario antes de haber
     *  completado el problema.
     */
    int anadir_envio_usuario(string u, string p, int r);
  
    /** @brief añade un curso en especifico a un usuario concreto.
     *  \pre el identificador del usuario<b>u</b> debe de existir en conjunto
     *  y el identificador de curso <b>c</b> no debe de formar parte de los cursos
     *  que el usuario <b>u</b> ha completado.
     *  \post usuario <b>u</b> pasa a tener añadido el identificador del curso <b>c</b>.
     */
    void i_anadir_curso(string u, int c);
   
    /** @brief añade un problema en especifico a un usuario concreto.
     *  \pre el identificador del usuario <b>u</b> debe de existir en conjunto. El usuario con identificador <b>u</b>
     *  no debe de haber completado el problema con identificador <b>p</b> anteriormente.
     *  \post el usuario con identificador <b>u</b> contiene un nuevo problema enviable con 
     *  identificador <b>p</b>.
     */
    void i_anadir_enviable(string u, string p);
  
    
  
    
};



#endif 