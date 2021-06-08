/** @file cjt_cursos.cc
 *  @brief implementacion de la clase conjunto de cursos
*/


#include "cjt_cursos.hh"
cjt_cursos::cjt_cursos(){}

bool cjt_cursos::existe_curso(int i) const {
    return i-1 >= 0 and i-1 < cursos.size();
}
void cjt_cursos::mostrar_curso(int i, curso& a) const {
    a = cursos[i-1];
}

void cjt_cursos::listar_cursos() {
  int tam = cursos.size();
  for(int i = 0; i < tam; ++i){
      cout << i+1 <<' '<<cursos[i].mostrar_usuarios_totales() << ' '
      << cursos[i].mostrar_usuarios_actuales() << ' ' << cursos[i].numero_sesiones() << ' ';
      cursos[i].listar_curso();
  }
}
void cjt_cursos::anadir_curso(curso& a) {
    cursos.push_back(a);
}
void cjt_cursos::modificar_curso(int c, curso& a) {
    cursos[c-1] = a;
}
int cjt_cursos::numero_cursos() const {
    return cursos.size();
}
string cjt_cursos::sesion_problema(int c, string p)  {
    return cursos[c-1].i_sesion_problema(p);
}
void cjt_cursos::i_completar_curso(int c) {
    cursos[c-1].curso_completado();
}
void cjt_cursos::i_anadir_usuario(int c) {
    cursos[c-1].anadir_usuario();
}
int cjt_cursos::i_mostrar_usuarios_actuales(int c) const {
    return cursos[c-1].mostrar_usuarios_actuales();
}
void cjt_cursos::i_anadir_enviables_curso(cjt_usuarios& a, cjt_sesiones& b,string u, int c) {
    int num_sesiones = cursos[c-1].numero_sesiones();
    for(int i = 1; i <= num_sesiones; i++){
        string sesion_i = cursos[c-1].mostrar_sesion_curso(i);
        b.i_primer_problema(a,sesion_i,u);
    }
}
void cjt_cursos::i_eliminar_usuario(int c){
    cursos[c-1].eliminar_usuario();
}
void cjt_cursos::i_escribir_curso(int c){
    cout << c << ' ' << cursos[c-1].mostrar_usuarios_totales()
    << ' ' << cursos[c-1].mostrar_usuarios_actuales() <<
    ' ' << cursos[c-1].numero_sesiones()<< ' ';
    cursos[c-1].listar_curso();
}
