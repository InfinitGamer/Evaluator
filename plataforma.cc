/** @file plataforma.cc
 *  @brief implementacion de la clase plataforma
*/

#include"plataforma.hh"

plataforma::plataforma(){}

void plataforma::lectura_inicial() {
    int n;
    cin>> n;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        problema_data_base.anadir_problema(a);
    }
    cin >> n;
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        sesion a;
        a.leer_sesion();
        sesion_data_base.anadir_sesion(s, a);
    }

    cin >> n;
    for (int i = 0; i < n; ++i){
        int num_sesiones;
        cin >> num_sesiones;
        curso a;
        a.leer_curso(num_sesiones, sesion_data_base);
        curso_data_base.anadir_curso(a);
    }
    cin >> n;
    for (int i = 0; i < n; ++i){
        string u;
        cin >> u;
        usuarios_data_base.anadir_usuario(u);
    }
}

void plataforma :: nuevo_problema(string p){
    
    if(not problema_data_base.existe_problema(p)){
        problema_data_base.anadir_problema(p);
        cout <<  problema_data_base.numero_problemas() << endl;
    }
    else cout << "error: el problema ya existe" << endl;
}

void plataforma::nuevo_curso(){
    curso a;
    int sesiones;
    cin >> sesiones;
    if(a.leer_curso(sesiones,sesion_data_base)){
        curso_data_base.anadir_curso(a);
       cout << curso_data_base.numero_cursos() << endl;
    }
    else cout <<"error: curso mal formado"<< endl;

}

void plataforma::nueva_sesion(string s){
    sesion a;
    a.leer_sesion();
    if(not sesion_data_base.existe_sesion(s)){
        sesion_data_base.anadir_sesion(s, a);
        cout << sesion_data_base.numero_sesiones() << endl;
    }
    else cout << "error: la sesion ya existe" << endl;
}

void plataforma :: alta_usuario (string u){
    
    if(not usuarios_data_base.existe_usuario(u)){
        usuarios_data_base.anadir_usuario(u);
        cout << usuarios_data_base.numero_usuario()<< endl;
    }
    else cout << "error: el usuario ya existe" << endl;
}

void plataforma :: baja_usuario(string u) {
    if(usuarios_data_base.existe_usuario(u)){
        usuario us;
        usuarios_data_base.mostrar_usuario(u, us);
        if(not usuarios_data_base.i_curso_completado(u)){
            int curso_i = usuarios_data_base.i_curso_actual(u);
            curso_data_base.i_eliminar_usuario(curso_i);
        }
        usuarios_data_base.eliminar_usuario(u);
       cout << usuarios_data_base.numero_usuario() << endl;
    }
    else cout<< "error: el usuario no existe" << endl;
}

void plataforma::inscribir_curso(string u, int c){

    if(usuarios_data_base.existe_usuario(u)){
        if(curso_data_base.existe_curso(c)){
        if(usuarios_data_base.i_curso_completado(u)){
            usuarios_data_base.i_anadir_curso(u,c);
            curso_data_base.i_anadir_usuario(c);
            cout << curso_data_base.i_mostrar_usuarios_actuales(c) << endl;
            curso_data_base.i_anadir_enviables_curso(usuarios_data_base,sesion_data_base,u,c);
         }
            else {
                cout <<"error: usuario inscrito en otro curso" << endl;
            }
        }
        else cout << "error: el curso no existe" << endl;
    }
    else cout << "error: el usuario no existe" << endl;
}

void plataforma::curso_usuario(string u){
    if(usuarios_data_base.existe_usuario(u)){
        
        cout << usuarios_data_base.i_curso_actual(u) << endl;
    }
    else cout<< "error: el usuario no existe" << endl;
}

void plataforma::sesion_problema(int c, string p){
    if(curso_data_base.existe_curso(c)){
        if(problema_data_base.existe_problema(p)){
            
            string sesion = curso_data_base.sesion_problema(c, p);
            if(sesion == "-1") cout << "error: el problema no pertenece al curso" << endl;
            else cout << sesion << endl;
        }
        else cout << "error: el problema no existe" << endl; 
    }
    else cout << "error: el curso no existe" << endl;
}

void plataforma:: problemas_resueltos(string u){
    if(usuarios_data_base.existe_usuario(u)){
        usuarios_data_base.i_listar_completados(u);   
    }
    else cout << "error: el usuario no existe" << endl;
}

void plataforma::problemas_enviables(string u){
    if(usuarios_data_base.existe_usuario(u)){
        
        if(not usuarios_data_base.i_curso_completado(u)){
            usuarios_data_base.i_listar_enviables(u);
        }
        else cout << "error: usuario no inscrito en ningun curso" << endl;
    }
    else cout<< "error: el usuario no existe" << endl;
}

 void plataforma::envio(string u, string p, int r){
     if(r == 0){
         usuarios_data_base.anadir_envio_usuario(u,p,r);
         problema_data_base.i_incrementar_problema(p, r);
     }
     else if (r == 1){
         
         int c = usuarios_data_base.anadir_envio_usuario(u,p,r);
         
         string ses = curso_data_base.sesion_problema(c,p);
         sesion_data_base.i_anadir_enviables(usuarios_data_base,ses,u,p);
         problema_data_base.i_incrementar_problema(p,r);
         if(usuarios_data_base.i_curso_completado(u)){
             curso_data_base.i_completar_curso(c);
         }

     }
 }

void plataforma::listar_problemas() {
    problema_data_base.listar_problemas();
}

void plataforma ::escribir_problema(string p){
    if(problema_data_base.existe_problema(p)){
        problema_data_base.i_escribir_problema(p);
    }
    else cout << "error: el problema no existe" <<endl;
}

void plataforma::listar_sesiones(){
    sesion_data_base.listar_sesiones();
}

void plataforma::escribir_sesion(string s){
    if(sesion_data_base.existe_sesion(s)){
        sesion_data_base.i_escribir_sesion(s);
    }
    else cout << "error: la sesion no existe" << endl;
}

void plataforma::listar_cursos(){
    curso_data_base.listar_cursos();
}

void plataforma::escribir_curso(int c){
    if(curso_data_base.existe_curso(c)){
       curso_data_base.i_escribir_curso(c);

    }
    else cout<< "error: el curso no existe" << endl;
}
void plataforma::listar_usuarios(){
    usuarios_data_base.listar_usuarios();
}

void plataforma::escribir_usuario(string u){
    if(usuarios_data_base.existe_usuario(u)){
        usuarios_data_base.i_escribir_usuario(u);
        }
    else cout << "error: el usuario no existe" << endl;
}