/** @file cjt_problemas.cc
 *  @brief implementacion de la clase conjunto de problemas
*/

#include "cjt_problemas.hh"
cjt_problemas::cjt_problemas(){};

void cjt_problemas::mostrar_problema(string id, problema& a ) const {
    map<string,problema>::const_iterator it;
    it = problemas.find(id);
    a = it -> second;
}
bool cjt_problemas::existe_problema(string p) const{
   return problemas.find(p) != problemas.end();
}

void cjt_problemas::anadir_problema(string p){
    
    problemas[p];
}
int cjt_problemas::numero_problemas() const{
    return problemas.size();
}
void cjt_problemas::listar_problemas(){
    struct aux{
        double ratio;
        string id;
        bool  operator< (const aux& a) const{
            if(ratio == a.ratio) return id < a.id;
            return ratio < a.ratio;
        }
    };
    map<string,problema>::const_iterator it;
    map<aux, problema> map_aux;
    for(it = problemas.begin(); it != problemas.end(); ++it){
        aux a;
        a.ratio = double(it ->second.mostrar_envios() +1) / double(it ->second.mostrar_envios_correctos() +1);
        a.id = it ->first;
        map_aux[a] = it ->second;
    }

    map<aux,problema>::const_iterator it2;
    for(it2 = map_aux.begin(); it2 != map_aux.end(); ++it2){
      cout<< it2->first.id <<'(' <<it2 ->second.mostrar_envios() << ',' << 
      it2->second.mostrar_envios_correctos() << ',' << it2->first.ratio << ')' << endl;
    }
}
void cjt_problemas::modificar_problema(string a, problema& b){
    problemas[a] = b;
}
void cjt_problemas::i_incrementar_problema(string p, int r) {
    if(r == 0) problemas[p].incrementar_stat_problema(1,0);
    else problemas[p].incrementar_stat_problema(1,1);
}
void cjt_problemas::i_escribir_problema(string p){
    int envios_correctos, envios_totales;
        envios_totales = problemas[p].mostrar_envios();
        envios_correctos = problemas[p].mostrar_envios_correctos();
        double ratio = double (envios_totales+1) / double (envios_correctos + 1);
        cout << p << '(' << envios_totales << ',' << envios_correctos << ',' << ratio << ')' << endl;
}