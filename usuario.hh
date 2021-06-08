/** @file usuario.hh
 *  @brief especificacion de la clase usuario
*/

#ifndef USUARIO_HH
#define USUARIO_HH
#ifndef NO_DIAGRAM
#include<list>
#include<iostream>
#include<map>
#endif
using namespace std;


/** @class usuario
 *  @brief Representa la información de un usuario, una lista de los cursos que ha cursado, 
 *  un conjunto de problemas que ha completado y un conjunto de problemas a los que puede realizar
 *  envios.
 */

class usuario
{
private:
    /** 
     * @brief contador que guarda los envios hechos por un usuario.
    */
    int envios_totales;
    
    /** 
     * @brief contador que guarda los envios correctos hechos por un usuario.
    */
    int envios_correctos;

    /** 
     * @brief estructura que guarda el identificador de los cursos que ha cursado el usuario.
    */
    list<int> cursos_cursados;

    /** 
     * @brief estructura que guarda por cada los problemas completados por el usuario
     * y sus correspondientes envios. Todo esto ordenado alfabeticamente por identificador.
    */
    map<string,int>problemas_completados;

    /** 
     * @brief estructura que guarda por cada los problemas a que no ha completador pero estan disponibles
     * por el usuario y sus correspondientes envios. Todo esto ordenado alfabeticamente por identificador.
    */
    map<string,int> problemas_enviables;
public:
     /** @brief constructora de la clase usuario.
     *  \pre <em>cierto</em>.
     *  \post crea un usuario con los envios y envios_correctos a cero.
    */
    usuario();
    
//consultoras

    /** @brief muestra si el curso actual esta completado o no. 
     *  \pre <em>cierto</em>.
     *  \post devuelve <b>true</b> si el curso actual esta completado o 
     * si no esta adscrito a ningun curso, <b>false</b> en caso contrario.
    */
    bool curso_completado() const;

    /** @brief muestra el curso actual del usuario.
     * \pre <em>cierto</em>.
     * \post devuelve el curso actual del objeto, si no esta inscrito en ninguno se devuelve 0.
    */
    int curso_actual() const;

    /** @brief muestra si existe un problema en especifico en el 
     *  conjunto de problemas enviables por el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve true si el problema con identificador <b>a</b> forma parte
     * de la lista de problemas enviables del usuario. False en caso contrario.
    */
    bool existe_en_enviables(string a) const;

    /** @brief muestra si existe un problema en especifico en el 
     *  conjunto de problemas completados por el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve true si el problema con identificador <b>a</b> forma parte
     * de la lista de problemas completados del usuario. False en caso contrario.
    */
    bool existe_en_completados(string a) const;

    /** @brief se listan los problemas enviables del usuario.
     * \pre <em>cierto</em>.
     * \post se lista por orden creciente de string los problemas enviables
     * dando informacion tambien de los envios que el objeto implicito ha hecho a estos.
    */
    void listar_enviables();
    
    /** @brief se listan los problemas completados del usuario.
     * \pre <em>cierto</em>.
     * \post se lista por orden creciente de string los problemas completados
     * dando informacion tambien de los envios que el objeto implicito ha hecho a estos.
    */
    void listar_completados();
    
    /** @brief devuelve el numero de problemas completados por el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve un numero >= 0 correspondiente al numero de problemas 
     * completados por el objeto implicito.
    */
    int numero_problemas_completados()const ;
    
    /** @brief devuelve el numero de problemas que ha hecho un envio por el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve un numero >= 0 correspondiente al numero de problemas a los que ha 
     * hecho un envio el objeto implicito.
    */
    int numero_problemas_envio()const ;
    
    /** @brief devuelve el numero de envios que ha hecho el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve un numero >= 0 correspondiente al numero de envios hechos por
     * el objeto implicito.
    */
    int envios_total() const;
    
    /** @brief devuelve el numero de envios correctos que ha hecho el usuario.
     * \pre <em>cierto</em>.
     * \post devuelve un numero >= 0 correspondiente al numero de envios correctos hechos por
     * el objeto implicito.
    */
    int envios_correct()const;

//modificadoras

    /** @brief añade un curso el cual el usuario va a cursar.
     *  \pre el parametro implicito <b>c</b> no debe de estar en el conjunto de cursos, cursados por el usuario.
     *  alumno debe de haber completado el curso que anteriormente estaba cursando
     *  \post añade el curso <b>c</b> a la lista de cursos del usuario.
     */
    void anadir_curso(int c);
    
    /** @brief se añade un problema al usuario.
     * \pre problema con identificador <b>a</b> no debe de haber sido completado anteriormente .
     * \post el objeto implicito pasa a tener añadido el problema con string <b>a</b> a lista de problemas
     * enviables del usuario.
     * 
    */
    void anadir_enviable(string a);
    
    /** @brief añade un envio a un problema enviable en especifico.
     * \pre debe de exisitir en el conjunto de problemas enviables por el objeto implicito
     * un problema con identificador <b>p</b>.
     * \post el problema con identificador <b>p</b> pasa a tener un envio más. 
    */
    void anadir_envio(string p);
  
    /** @brief se añaden envios al usuario.
     * \pre <b>envios</b> y <b>envios_correctos</b> deben de ser numeros entre [0,1]
     *  Si envios = 0, envios_correctos, tiene que ser tambien 0.
     * \post Si envios = 0, el objeto implicito no habrá hecho ningun envios. Si envios = 1
     * significa que el objeto implicito ha hecho un envio y por lo tanto se le ha actualizado
     * el numero de envio totales hechos por el objeto implicito. De forma simetrica pasa con envios correctos.
    */
    void modificar_stat(int envios, int envios_correctos);
    
    /** @brief añade un envio correcto a un problema enviable en especifico.
     * \pre debe de exisitir en el conjunto de problemas enviables por el objeto implicito
     * un problema con identificador <b>p</b>.
     * \post el problema con identificador <b>p</b> pasa a tener un envio más y al ser correcto
     * se mueve al conjunto de problemas completados. 
    */
    void envio_correcto(string p);
};


#endif