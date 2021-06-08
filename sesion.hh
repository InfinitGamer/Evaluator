/** @file sesion.hh
 *  @brief especificacion de la clase sesion
*/
#ifndef SESION_HH
#define SESION_HH

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include<iostream>
#include<list>
#include<vector>
#include <set>
#endif
#include"cjt_usuarios.hh"
using namespace std;

/** @class sesion
 *  @brief representa una sesion una sesion de problemas ordenados en función de sus prerequisitos.
 */


class sesion
{
private:
    /** 
     * @brief contador del numero de problemas presentes en una sesion.
    */
    int numero_problemas;
    /** 
     * @brief estructura de prerequisitos de los problemas presentes
     * en una sesion.
    */
    BinTree<string> problemas;
    /** 
     * @brief estructura que guarda el identificador de los problemas
     * presentes en una sesion
    */
    set<string> lista_problemas;
    /** 
     * @brief estructura auxiliar para guardar los siguientes problemas disponibles
     * por cada problma
    */
    struct hijos{
        string izquierdo;
        string derecho;
    };
    /** 
     * @brief estructura que guarda por cada problema presente en la sesion, 
     * los siguientes problemas disponibles
    */
    map<string,hijos> lista_adjacencias;

    /** @brief funcion inmersiva que rellena un arbol binario de problemas en postorden,
     *  a la vez que mete en un set los problemas que componen el bintree y en un map
     *  los hijos de cada nodo. Por ultimo también devuelve el numero de problemas que componen
     *  el arbol.
     *  \pre <b>nodo</b> debe de contener el primer nodo del arbol binario.
     *  Los datos deben estar preparados por terminal. <b>Nodos</b> debe de estar inicializado a 0
     *  \post el arbol binario <b>a</b> pasa a tener como sus atributos los datos pasados por terminal.
     *  A la vez, se introduce en el mapa <b>lista</b> los hijos de cada nodo. Por ultimo, el set <b>v</b> pasa contener
     *  los problemas que contiene el arbol <b>a</b> y <b>nodos</b> pasa a contener el numero de nodos que tiene el arbol.
     */
    static void leer_bintree(BinTree<string>& a, int& nodos, set<string>& v, map<string,hijos>& lista, string nodo);

    /** @brief funcion inmersiva que dado un usuario, se le añade los problemas correspondientes.
     *  \pre <b>u</b> debe de estar cursando un curso que contenga el objeto implicito. <b>Nodo</b> debe
     *  de contener el identificador del problema el cual el usuario aun no esta disponible para hacer un envío.
     *  \post el usuario <b>b</b> pasa a tener los problemas correspondientes a partir del parametro <b>nodo</b>.
     */
    static void problemas_enviables_usuario (const map<string,hijos> & a, string nodo, cjt_usuarios& b, string u);
    
    /** @brief funcion inmersiva que dado un usuario, se le añade los problemas correspondientes.
     *  \pre <b>u</b> debe de estar cursando un curso que contenga el objeto implicito. <b>Nodo</b> debe
     *  de contener el identificador del problema el cual el usuario aun no esta disponible para hacer un envío.
     *  \post el usuario <b>b</b> pasa a tener los problemas correspondientes a partir del parametro <b>nodo</b>.
     */
    static void i_listar_sesion(const BinTree<string>& a);
public:
     /** @brief constructora de la clase sesion.
     *  \pre <em>cierto</em>.
     *  \post crea una sesion vacia y con el numero de problemas a cero
    */
    sesion();

//consultoras

    /** @brief muestra el numero de problemas correspondiente al objeto. 
     *  \pre <em> cierto </em>.
     *  \post devuelve un entero >= 0 correspondiente al numero de problemas.
    */
    int numero_de_problemas()const;

    /** @brief expresa la existencia de una sesion en la sesion.
     *  \pre <em>cierto</em>.
     *  \post devuelve true si <b>p</b> esta presente en el objeto implicito.
     */
    bool existe_problema(string p);

    /** @brief muestra las estadisticas de la sesion.
     *  \pre <em>cierto</em>.
     *  \post se muestra por pantalla el numero de problemas que compone el objeto implicito
     *  junto a la estructura de prerequisitos en postorden.
     */
    void listar_sesion() const;
   
    /** @brief devuelve el conjunto de problemas que conforman la sesion.
     *  \pre <b>a</b> debe de esta vacío.
     *  \post devuelve por referencia el conjunto de problemas del objeto implicito.
     */
    void devolver_conjunto(set<string>& a);

//modificadoras

    /** @brief lee una sesion valida.
     *  \pre los datos tiene que estan cargados en terminal en preorden.
     *  \post el objeto pasa a tener como atributo los datos pasados
     *  por terminal.
    */
    void leer_sesion();
    
    /** @brief añade a un usuario concreto los primeros problemas que le debería de corresponder en la sesion.
     *  \pre <em>cierto</em>.
     *  \post usuario <b>a</b> pasa a tener los primeros problemas del objeto implicito.
     */
    void primer_problema(cjt_usuarios& a, string u);
    
    /** @brief recalcula los problemas enviables por un usuario.
     *  \pre el problema con identificador <b>p</b> debe pertenecer al objeto implicito.
     *  \post el usuario <b>a</b> pasa a tener actualizados los problemas enviables a partir del problema <b>p</b>.
     */
    void problemas_enviables(cjt_usuarios& a, string u, string p);
    
    
};

#endif  