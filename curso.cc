/** @file curso.cc
 *  @brief implementacion de la clase curso
*/

#include "curso.hh"
curso::curso(){
    usuarios_actuales= 0;
    usuarios_totales = 0;
}

string curso::mostrar_sesion_curso(int i) const{
    return sesiones[i-1];
}
int curso::numero_sesiones() const{
    return sesiones.size();
}
bool curso::leer_curso(int s, const cjt_sesiones& a){
    for(int i = 0; i < s; ++i){
        string a;
        cin >> a;
        sesiones.push_back(a);
    }
   for(int i = 1; i <= s; ++i){
       string sesion_i = mostrar_sesion_curso(i);
       sesion sesion1;
       a.mostrar_sesion(sesion_i, sesion1);
       set<string> problemas;
       sesion1.devolver_conjunto(problemas);
       set<string>::const_iterator it;
       for(it = problemas.begin(); it != problemas.end(); ++it){
           if(problema_sesion.find(*it) != problema_sesion.end()) return false;
           else problema_sesion[*it] = sesion_i;
       }
   }
   return true;
}
int curso::mostrar_usuarios_actuales()const {
    return usuarios_actuales;
}
int curso::mostrar_usuarios_totales() const{
    return usuarios_totales;
}
void curso::anadir_usuario() {
    usuarios_actuales +=  1;
}
void curso::eliminar_usuario() {
    if(usuarios_actuales > 0)
    usuarios_actuales -= 1;
}
void curso::listar_curso(){
    int tam = sesiones.size();
    cout << '(';
    for (int i = 0; i < tam; ++i){
        if(i == 0)cout << sesiones[i];
        else cout <<' '<< sesiones[i];
    }
    cout << ')'<< endl;
}

void curso::curso_completado(){
    --usuarios_actuales;
    ++usuarios_totales;
}
string curso::i_sesion_problema(string p){
    map<string,string>::const_iterator it = problema_sesion.find(p);
    if(it != problema_sesion.end()) return it->second;
    else return "-1";
}