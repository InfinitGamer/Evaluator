/** @file sesion.cc
 *  @brief implementacion de la clase sesion
*/

#include"sesion.hh"
sesion::sesion(){
    numero_problemas = 0;
    }
void sesion::leer_bintree(BinTree<string>& a, int& nodos, set<string>& v, map<string,hijos>& lista,string nodo){
    
    if (nodo != "0"){
        v.insert(nodo);

        ++nodos;
        hijos adjacencia;
        cin >> adjacencia.izquierdo;
        
        BinTree<string> izquierdo,derecho;
        leer_bintree(izquierdo, nodos,v,lista, adjacencia.izquierdo);
        cin >>adjacencia.derecho;
        leer_bintree(derecho,nodos,v, lista, adjacencia.derecho);
        lista[nodo] = adjacencia;
        
        a = BinTree<string> (nodo,izquierdo,derecho);
        
    }
}

 
 void sesion::problemas_enviables_usuario (const map<string,hijos>& a, string nodo, cjt_usuarios& b, string u){
   if(nodo != "0"){
    if(not b.i_existe_en_completados(u, nodo)){
        b.i_anadir_enviable(u,nodo);
    }
    else if (b.i_existe_en_completados(u,nodo)){
        map<string,hijos>::const_iterator it = a.find(nodo);
        string izquierdo, derecho;
        izquierdo = it->second.izquierdo;
        derecho = it->second.derecho;
        problemas_enviables_usuario(a,izquierdo, b,u);
        problemas_enviables_usuario(a,derecho,b,u);
    }
   }
}
 void sesion::i_listar_sesion(const BinTree<string>&a){
    if(not a.empty()){
        cout <<'(';
        i_listar_sesion(a.left());
        i_listar_sesion(a.right());
        cout << a.value() << ')';
    }
}
void sesion::leer_sesion(){
    numero_problemas = 0;
    string primer_nodo;
    cin >> primer_nodo;
    leer_bintree(problemas, numero_problemas, lista_problemas,lista_adjacencias, primer_nodo);
    
}
void sesion::primer_problema(cjt_usuarios& a, string u) {
    problemas_enviables_usuario(lista_adjacencias,problemas.value(),a,u);
}
bool sesion::existe_problema(string p){
    return lista_adjacencias.find(p) != lista_adjacencias.end();
}

void sesion::problemas_enviables(cjt_usuarios& a, string u, string p){
    map<string,hijos>::const_iterator it = lista_adjacencias.find(p);
    problemas_enviables_usuario(lista_adjacencias,it->second.izquierdo,a, u);
    problemas_enviables_usuario(lista_adjacencias,it->second.derecho,a, u);
    
}
void sesion::listar_sesion() const {
    i_listar_sesion(problemas);
    cout<< endl;
}
int sesion::numero_de_problemas() const{
    return numero_problemas;
}
void sesion::devolver_conjunto(set<string>& a){
    a = lista_problemas;
}