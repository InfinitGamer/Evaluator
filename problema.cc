/** @file problema.cc
 *  @brief implementacion de la clase problema
*/

#include "problema.hh"
problema::problema(){
    envios = 0;
    envios_correctos = 0;
}
int problema::mostrar_envios()const{
    return envios;
}
int problema::mostrar_envios_correctos() const{
    return envios_correctos;
}
void problema::incrementar_stat_problema(int envios, int envios_correctos){
    this->envios += envios;
    this->envios_correctos += envios_correctos;
}