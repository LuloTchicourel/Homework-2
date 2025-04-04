Ejercicio 1:
g++ -std=c++14 time.cpp timefuncs.cpp -o time_program

./time

Ejercicio 2:
g++ -std=c++14 students.cpp studentsfunc.cpp coursefunctions.cpp -o stud

./stud

c. 
Es una relacion de asociasion, ya que se mantienen ambos pero no dependen de ellos.
El curso puede no tener estudiantes o un estudiante no tener cursos y ambos pueden existir.

Justificacion del copy:
La copia realizada es una shallow copy ya que no se crea una duplicacion del elemento, sino se
agrega la referencia mediante punteros.
Esto nos sirve en el contexto de mi codigo ya que queremos que el mismo alumno coexista en diferentes cursos, y que este pueda ser modificado globalmente. Si se desincribe de una clase, luego cuando vemos las clases que tenga (accediendo de otro curso) podemos ver que efectivamente se perdio ese vinculo, lo cual es lo que buscamos.

Ejercicio 3:
g++ -std=c++17 -Wall numbers.cpp intfuncs.cpp realfuncs.cpp complexfuncs.cpp -o nums

./nums