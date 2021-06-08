/** @file cjt_usuarios.cc
 *  @brief implementacion de la clase conjunto de usuarios
*/

#include"cjt_usuarios.hh"
 cjt_usuarios::cjt_usuarios(){}
 bool cjt_usuarios::existe_usuario(string u) const {
     return conjunto_usuario.find(u) != conjunto_usuario.end();
 }
 void cjt_usuarios :: anadir_usuario(string u){
     conjunto_usuario[u];
 }
 int cjt_usuarios :: numero_usuario() const{
     return conjunto_usuario.size();
 }
 void cjt_usuarios::eliminar_usuario(string u){
     conjunto_usuario.erase(u);
 }
 void cjt_usuarios::mostrar_usuario(string u, usuario& a) {
     a = conjunto_usuario[u];
 }
 void cjt_usuarios::listar_usuarios(){
     map<string,usuario>::const_iterator it;
     for(it = conjunto_usuario.begin(); it != conjunto_usuario.end(); ++it){
     cout<<it->first << '(' << it -> second.envios_total()
     <<',' << it->second.numero_problemas_completados() << ',' << it->second.numero_problemas_envio()
     << ',' << it->second.curso_actual() << ')' << endl;
     }
 }
 void cjt_usuarios::modificar_usuario(string a, usuario& b){
     conjunto_usuario[a] = b;
 }
 int cjt_usuarios::anadir_envio_usuario(string u, string p, int r) {
     if (r == 0){
         conjunto_usuario[u].anadir_envio(p);
         return 0;
     }
     else{
         int c = conjunto_usuario[u].curso_actual();
         conjunto_usuario[u].envio_correcto(p);
         return c;
     }
 }
 bool cjt_usuarios::i_curso_completado(string u) {
     return conjunto_usuario[u].curso_completado();
 }
 void cjt_usuarios:: i_anadir_curso(string u, int c){
     conjunto_usuario[u].anadir_curso(c);
 }
 bool cjt_usuarios::i_existe_en_completados(string u, string p) const{
     map<string,usuario>::const_iterator it = conjunto_usuario.find(u);
     return it ->second.existe_en_completados(p);
 }
 void cjt_usuarios::i_anadir_enviable(string u, string p){
     conjunto_usuario[u].anadir_enviable(p);
 }
 int cjt_usuarios::i_curso_actual(string u){
     return conjunto_usuario[u].curso_actual();
 }
 void cjt_usuarios::i_listar_enviables(string u){
     conjunto_usuario[u].listar_enviables();
 }
 void cjt_usuarios::i_listar_completados(string u){
     conjunto_usuario[u].listar_completados();
 }
 void cjt_usuarios::i_escribir_usuario(string u){
     cout << u << '(' << conjunto_usuario[u].envios_total()
        << ',' << conjunto_usuario[u].numero_problemas_completados() <<','<< 
        conjunto_usuario[u].numero_problemas_envio() << ','
        << conjunto_usuario[u].curso_actual() << ')' << endl; 
 }