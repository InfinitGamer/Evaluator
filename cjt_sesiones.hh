/** @file cjt_sesiones.hh
 *  @brief especificacion de la clase conjunto de sesiones
*/

#ifndef CJT_SESIONES_HH 
#define CJT_SESIONES_HH
#include "sesion.hh"
#ifndef NO_DIAGRAM
#include<map>
#include<iostream>
#endif
using namespace std;



/** @class cjt_sesiones
 *  @brief Representa un conjunto de sesiones que estan ordenados por su identificador.
 */

class cjt_sesiones
{
private:
/**
 * @brief estructura que guarda un conjunto de sesiones
 * ordenados alfabeticamente por su identificador.
*/
    map<string,sesion> sesiones;
public:
    /** @brief constructora de la clase conjunto de sesiones.
     *  \pre <em>cierto</em>.
     *  \post crea un conjunto de sesiones vacío.
    */
    cjt_sesiones();

//consultoras

    /** @brief funcion booleana que muestra si el parametro implicito existe. 
     *  \pre <em>cierto</em>.
     *  \post devuelve <b>true</b> si el parametro implicito <b>s</b> existe en el vector,
     *  <b>false</b> en caso contrario.
    */
    bool existe_sesion(string s)const;

    /** @brief muestra la sesion que tiene como identificador el parametro implicito <b>s</b>.
     *  \pre el parametro implicito <b>s</b> debe de existir en el objeto.
     *  \post devuelve la sesion que tiene el parametro implicito <b>s</b> como identificador.
     */
    void mostrar_sesion(string s, sesion& a) const;

    /** @brief muestra el numero de sesiones que hay en el conjunto.
     *  \pre <em>cierto</em>.
     *  \post devuelve un int correspondiente al numero de sesiones
     *  del objeto implicito.
     */
    int numero_sesiones() const;

    /** @brief se listan las sesiones del objeto implicito.
     *  \pre <em>cierto</em>.
     *  \post se muestra por orden creciente de string las sesiones
     *  del objeto implicito, junto al numero de problemas correspondiente a la sesion 
     *  y esquema de la sesion en postorden.
     */
    void listar_sesiones();

    /** @brief se muestra por pantalla las estadisticas de una sesion.
     *  \pre debe de existir una sesion con identificador <b>s</b>.
     *  \post se muestra le identificador <b>s</b>, junto al numero de problemas que tiene la sesion correspondiente.
     *  Y por ultimo se muestra la estructura de prerequisitos de los problemas en post orden.
     */
    void i_escribir_sesion(string s);

//modificadoras

    /** @brief añade una sesion del conjunto de sesiones.
     *  \pre no debe de existir un sesion con identificador <b>s</b>.
     *  \post el parametro implicito <b>s</b> forma parte del objeto.
     */
    void anadir_sesion(string s, sesion& a);
    
    /** @brief se modifica una sesion en especifico.
     *  \pre debe de existir en el objeto un problema con id <b>a</b>.
     *  \post la sesion <b>a</b> es modificado con los atributos del parametro <b>b</b>.
     */
    void modificar_sesion(string a, sesion& b);
  
    /** @brief se añaden los problemas disponibles correspondientes a un usuario en especifico a partir de un problema en concreto.
     *  \pre <b>a</b> debe de contener el usuario <b>u</b>. En el conjunto de sesiones
     *  debe existir sesion con identificador <b>s</b> y debe de contener el problema con string.
     *  <b>p</b>.
     *  \post el usuario <b>u</b> se pasa tener los problemas disponibles correspondientes a la sesion <b>s</b>.
     */
    void i_anadir_enviables(cjt_usuarios& a, string s, string u, string p);
  
    /** @brief se añaden los primeros problemas disponibles correspondientes al usuario <b>u</b>. 
     *  \pre <b>a</b> debe de contener el usuario <b>u</b>. En el conjunto de sesiones
     *  debe existir sesion con identificador <b>s</b>.
     *  \post el usuario <b>u</b> se pasa tener los primeros problemas disponibles correspondientes a la sesion <b>s</b>.
     */
    void i_primer_problema (cjt_usuarios& a, string s, string u);
   
    
};


#endif