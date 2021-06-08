/** @file usuario.cc
 *  @brief implementacion de la clase usuario
*/

#include"usuario.hh"

usuario::usuario(){
    envios_totales = 0;
    envios_correctos = 0;
}
bool usuario::curso_completado() const{
    return  problemas_enviables.empty();
}
void usuario::anadir_curso(int c) {
    cursos_cursados.insert(cursos_cursados.end(), c);
}

int usuario:: curso_actual() const {
    if(not problemas_enviables.empty()){
        list<int>::const_iterator it = cursos_cursados.end();
        --it;
        return *it;
    }
    else return 0;
}

void usuario::anadir_enviable(string a){
    problemas_enviables[a] = 0;
}
bool usuario::existe_en_enviables(string a) const{
    return problemas_enviables.find(a) != problemas_enviables.end();
}
bool usuario::existe_en_completados(string a) const{
    return problemas_completados.find(a) != problemas_completados.end();
}
void usuario::listar_enviables(){
    map<string,int> :: const_iterator it;
    for(it = problemas_enviables.begin(); it != problemas_enviables.end(); ++it){
        cout << it ->first << '(' << it->second <<')' << endl;
    }
}
void usuario::listar_completados(){
    map<string,int> :: const_iterator it;
    for(it = problemas_completados.begin(); it != problemas_completados.end(); ++it){
        cout << it ->first << '(' << it->second << ')'<< endl;
    }
}
int usuario::numero_problemas_completados() const{
    return problemas_completados.size();

}
int usuario::numero_problemas_envio()const{
    int num = 0;
    num += problemas_completados.size();
    for(map<string,int>::const_iterator it = problemas_enviables.begin(); it !=problemas_enviables.end();++it){
        if(it->second != 0) num += 1;
    }
    return num;
}
int usuario:: envios_total()const{
    return envios_totales;
}
int usuario:: envios_correct()const{
    return envios_correctos;
}

void usuario::anadir_envio(string p){
    ++problemas_enviables[p];
    ++envios_totales;
}
void usuario::modificar_stat(int envios, int envios_correctos){
   this->envios_correctos+=envios_correctos;
   envios_totales += envios;
}
void usuario::envio_correcto(string p){
    ++envios_correctos;
    ++envios_totales;
    map<string,int>:: iterator it = problemas_enviables.find(p);
    ++it->second;
    problemas_completados.insert(*it);
    problemas_enviables.erase(it);
}