OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: BinTree.hh program.o plataforma.o cjt_problemas.o cjt_sesiones.o cjt_cursos.o cjt_usuarios.o problema.o sesion.o curso.o usuario.o
	g++ -o program.exe BinTree.hh program.o plataforma.o cjt_problemas.o cjt_sesiones.o cjt_cursos.o cjt_usuarios.o problema.o sesion.o curso.o usuario.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

plataforma.o: plataforma.cc
	g++ -c plataforma.cc $(OPCIONS)

cjt_problemas.o: cjt_problemas.cc
	g++ -c cjt_problemas.cc $(OPCIONS)

cjt_sesiones.o: cjt_sesiones.cc
	g++ -c cjt_sesiones.cc $(OPCIONS)

cjt_cursos.o: cjt_cursos.cc
	g++ -c cjt_cursos.cc $(OPCIONS)

cjt_usuarios.o: cjt_usuarios.cc
	g++ -c cjt_usuarios.cc $(OPCIONS)

problema.o: problema.cc
	g++ -c problema.cc $(OPCIONS)

sesion.o: sesion.cc
	g++ -c sesion.cc $(OPCIONS)

curso.o: curso.cc
	g++ -c curso.cc $(OPCIONS)

usuario.o: usuario.cc
	g++ -c usuario.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
tar:
	tar -cvf practica.tar makefile program.cc BinTree.hh problema.hh problema.cc sesion.hh sesion.cc curso.hh curso.cc usuario.hh usuario.cc cjt_usuarios.hh cjt_usuarios.cc cjt_sesiones.cc cjt_sesiones.hh cjt_cursos.cc cjt_cursos.hh cjt_problemas.cc cjt_problemas.hh plataforma.cc plataforma.hh html.zip competencia_transversal.zip