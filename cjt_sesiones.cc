/** @file cjt_sesiones.cc
 *  @brief implementacion de la clase conjunto de sesiones
*/

#include"cjt_sesiones.hh"

cjt_sesiones::cjt_sesiones(){};

bool cjt_sesiones::existe_sesion(string s) const{
    return sesiones.find(s) != sesiones.end();
}
void cjt_sesiones::anadir_sesion(string s, sesion& a){
    sesiones[s] = a;
}
int cjt_sesiones::numero_sesiones() const{
    return sesiones.size();
}
void cjt_sesiones::listar_sesiones(){
    map<string,sesion>::const_iterator it;
    for(it = sesiones.begin(); it != sesiones.end(); ++it){
        cout << it->first << ' ' << it->second.numero_de_problemas() << ' ';
        it->second.listar_sesion();
    }
}
void cjt_sesiones::mostrar_sesion(string s, sesion& a)const {
    map<string,sesion>::const_iterator it;
    it = sesiones.find(s);
    a = it -> second;
}
void cjt_sesiones::modificar_sesion(string a, sesion& b){
    sesiones[a] = b;
}
void cjt_sesiones::i_anadir_enviables(cjt_usuarios& a, string s, string u, string p){
   sesiones[s].problemas_enviables(a,u,p);
}
void cjt_sesiones::i_primer_problema(cjt_usuarios& a, string s, string u){
    sesiones[s].primer_problema(a,u);
}
void cjt_sesiones::i_escribir_sesion(string s){
    cout << s << ' ' << sesiones[s].numero_de_problemas() << ' ';
    sesiones[s].listar_sesion();
}