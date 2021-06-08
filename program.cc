/** @file program.cc
 *  @brief implementacion del main del programa
*/
#include"plataforma.hh"

int main(){
plataforma evaluator;
evaluator.lectura_inicial();
string comando;
cin >> comando;
while(comando != "fin"){
    if(comando =="nuevo_problema" or comando =="np"){
        string p;
        cin >>p;
        cout <<'#' << comando<<' '<< p << endl;
        evaluator.nuevo_problema(p);
    }
    else if(comando =="nueva_sesion" or comando == "ns"){
        string sesion;
        cin >> sesion;
        cout<<'#'<< comando <<' '<< sesion << endl;
        evaluator.nueva_sesion(sesion);

    }
    else if(comando =="nuevo_curso" or comando == "nc"){
        cout <<'#'<< comando << endl;
        evaluator.nuevo_curso();
    }
    else if(comando == "alta_usuario" or comando =="a"){
        string usuario;
        cin >> usuario;
        cout <<'#'<< comando <<' '<< usuario << endl;
        evaluator.alta_usuario(usuario);

    }
    else if(comando =="baja_usuario" or comando =="b"){
        string usuario;
        cin >>usuario;
        cout <<'#' << comando<<' '<< usuario << endl;
        evaluator.baja_usuario(usuario);

    }
    else if(comando =="inscribir_curso" or comando =="i"){
        string usuario;
        cin >> usuario;
        int curso;
        cin >> curso;
        cout <<'#' << comando<<' '<< usuario << ' ' << curso << endl;
        evaluator.inscribir_curso(usuario,curso);
    }
    else if(comando == "curso_usuario" or comando == "cu"){
        string usuario;
        cin >> usuario;
        cout <<'#' << comando<<' '<< usuario << endl;
        evaluator.curso_usuario(usuario);

    }
    else if(comando == "sesion_problema" or comando == "sp"){
        int curso;
        string problema;
        cin >> curso >> problema;
        cout <<'#' << comando<<' '<< curso <<' '<<problema << endl;
        evaluator.sesion_problema(curso, problema);
    }
    else if(comando == "problemas_resueltos" or comando =="pr"){
        string usuario;
        cin >> usuario;
        cout <<'#' << comando<<' '<< usuario << endl;
        evaluator.problemas_resueltos(usuario);
    }
    else if(comando =="problemas_enviables" or comando == "pe"){
        string u;
        cin >> u;
        cout <<'#' << comando<<' '<< u << endl;
        evaluator.problemas_enviables(u);
    }
    else if(comando == "envio" or comando == "e"){
        string usuario, problema;
        int nota;
        cin >> usuario >> problema >> nota;
        cout << '#'<< comando <<' '<<usuario << ' ' << problema << ' ' << nota << endl;
        evaluator.envio(usuario, problema, nota);
    }
    else if(comando == "listar_problemas" or comando =="lp"){
        cout <<'#' << comando << endl;
        evaluator.listar_problemas();
    }
    else if(comando == "escribir_problema" or comando == "ep"){
        string p;
        cin >> p;
        cout <<'#' << comando<<' '<< p << endl;
        evaluator.escribir_problema(p);
    }
    else if(comando == "listar_sesiones" or comando == "ls"){
        cout <<'#' << comando<< endl;
        evaluator.listar_sesiones();
    }
    else if(comando == "escribir_sesion" or comando == "es"){
        string s;
        cin >> s;
        cout <<'#' << comando<<' '<< s << endl;
        evaluator.escribir_sesion(s);
    }
    else if(comando == "listar_cursos" or comando == "lc"){
        cout <<'#' << comando<< endl;
        evaluator.listar_cursos();

    }
    else if(comando == "escribir_curso" or comando =="ec"){
        int c;
        cin >> c;
        cout <<'#' << comando<<' '<< c << endl;
        evaluator.escribir_curso(c);
    }
    else if(comando == "listar_usuarios" or comando =="lu"){
        cout <<'#' << comando<< endl;
        evaluator.listar_usuarios();
    }
    else if(comando == "escribir_usuario" or comando =="eu"){
        string u;
        cin >> u;
        cout <<'#' << comando<<' '<< u << endl;
        evaluator.escribir_usuario(u);
    }
    cin >> comando;
}
}