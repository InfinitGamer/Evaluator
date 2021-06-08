/** @file problema.hh
 *  @brief especificacion de la clase problema
*/
#ifndef PROBLEMA_HH
#define PROBLEMA_HH
#ifndef NO_DIAGRAM
#include<iostream>
#endif

/** @class problema
 *  @brief representa las estadisticas de un problema, 
 *  envios que se han hecho y los correctos.
 */

class problema
{
private:
    /** 
     * @brief contador de los envios que hacen los usuarios al problema.
    */
    int envios;
    /** 
     * @brief contador de los envios correctos que hacen los usuarios al problema.
    */
    int envios_correctos;
    
public:
     /** @brief constructora de la clase problema.
     *  \pre <em>cierto</em>.
     *  \post crea un problema con los envios y envios correctos a cero.
    */
    problema();

 //consultoras

    /** @brief muestra el numero de envios hechos a este problema. 
     *  \pre <em>cierto</em>.
     *  \post devuelve un entero >= 0 correspondiente al numero de envios.
    */
    int mostrar_envios()const;
    
    /** @brief muestra el numero de envios correctos hechos por todos los usuarios.
     *  \pre <em>cierto</em>.
     *  \post devuelve un int correspondiente al numero de envios correctos al problema.
     */
    int mostrar_envios_correctos()const;

//modificadoras

    /** @brief suma un envio al problema.
     *  \pre <b>envios</b> y <b>envios_correctos</b> tienen que ser numeros entre [0,1].
     *  Si <b>envios</b> = 0, <b>envios_correctos</b> tambien tiene que ser 0.
     *  \post se incrementa el numero de envios y envios correctos segun los parametros implicitos.
     */
    void incrementar_stat_problema(int envios, int envios_correctos);
};


#endif