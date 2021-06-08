/** @file cjt_problemas.hh
 *  @brief especificacion de la clase conjunto de problemas
*/
#ifndef CJT_PROBLEMAS_HH
#define CJT_PROBLEMAS_HH
#include "problema.hh"

#ifndef NO_DIAGRAM
#include<iostream>
#include<map>
#endif
using namespace std;

/** @class cjt_problemas
 *  @brief representa un conjunto de problemas 
 * donde esta ordenado segun su identificador.
 */
class cjt_problemas
{
private:
/**
 * @brief estructura que guarda un conjunto de
 * problemas en orden alfabetico por su identificador.
*/
    map<string,problema> problemas;
public:
     /** @brief constructora de la clase conjunto de problemas.
     *  \pre <em>cierto</em>.
     *  \post crea un conjunto de problemas vacío.
    */
    cjt_problemas();

//consultoras

    /** @brief muestra si existe en el conjunto de problemas un problema con un identificador en especifico.
     *  \pre <em>cierto</em>.
     *  \post devuelve true si existe un problema con identificador <b>p</b>. False en caso contrario.  
    */
    bool existe_problema(string p)const;

    /** @brief muestra el problema que tiene con un identificador en especifico.
     *  \pre el problema con identificador <b>id</b> debe de existir en el objeto.
     *  \post devuelve el problema corrrespondiente al parametro implicito <b>id</b>.
     */
    void mostrar_problema (string id, problema& a)const;

    /** @brief muestra el numero de problemas que hay en el conjunto.
     *  \pre <em>cierto</em>.
     *  \post devuelve un int correspondiente al numero de problemas
     *  del objeto implicito.
     */
    int numero_problemas() const;

    /** @brief se listan los problemas del objeto implicito.
     *  \pre <em>cierto</em>.
     *  \post se muestra por pantalla el listado de problemas ordenado por
     *  ratio (<b>envios totales</b> + 1)/(<b>envios correctos</b> + 1) y en caso de empate por orden 
     *  creciente de identificador los problemas del objeto implicito. También muestra el numero de envios totales que se
     *  han hecho al problema y el numero de envios correctos.
     */
    void listar_problemas();

    /** @brief se muestra por pantalla las estadisticas de un problema en especifico.
     *  \pre <b>p</b> debe de pertenecer al objeto implicito.
     *  \post se muestra el identificador del problema junto el numero de envios totales al problemas,
     *  numero de envios correctos a este y por ultimo se muestra un ratio
     *  (<b>envios totales</b> + 1)/(<b>envios correctos</b> + 1).
    */
    void i_escribir_problema(string p);

//modificadoras

    /** @brief añade un problema al conjunto de problemas.
     *  \pre el problema con identificador <b>p</b> no debe de aparecer en el objeto.
     *  \post el objeto pasa a tener dentro un problema con identificador <b>p</b>. 
    */
    void anadir_problema(string p);
   
    /** @brief se modifica un problema en especifico.
     *  \pre debe de existir en el objeto un problema con identificador <b>a</b>.
     *  \post el problema <b>a</b> es modificado con los atributos del parametro <b>b</b>.
     */
    void modificar_problema(string a, problema& b);
    
    /** @brief se incrementa los intentos correspondientes a problema en especifico.
     *  \pre el problema con identificador <b>p</b> debe de existir en el conjunto, <b>r</b> debe estar comprendido entre
     *  [0,1].
     *  \post Si r = 0, <b>p</b> tiene un intento añadido. En caso de r = 1, <b>p</b> pasa a
     *  tener un intento y intento_correcto añadido. 
     */
    void i_incrementar_problema(string p, int r);
    
    
};



#endif 