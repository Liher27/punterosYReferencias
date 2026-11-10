## Para qué se usa el namespace? ##

Un namespace es un término mediante el cual el usuario puede definir diferentes funciones con el mismo nombre, en diferente sitios del codigo. Imagina que tienes dos
archivos .cpp, con un una funcion que se llama add() en cada uno. si desde main, quisiesemos llamar al add() de uno de los dos .cpp, como sabria el compilador a cual
nos referimos? para ello, se creó el termino "namespace". 

Con esta nueva tecnica, podemos darle un diferenciador a funciones o variables que se llamen de la misma forma en diferentes archivos. Así, el compilador sabrá a qué
parte del codigo en especifico nos estamos refiriendo. 

Un ejemplo muy común de namespace es la libreria estandar, std. Como ya sabemos como acceder a funciones y variables de std, se hace mediante el operador logico ::, 
que se puede traducir como: coge la funcion/variable (lado derecho) del namespace (lado izquierdo).

Asímismo, se pueden definir namespaces dentro de namespaces, como por ejemplo namespace foo, viviese dentro de goo. teniendo en cuenta que queremos acceder a un metodo
en foo, se haria de la siguiente forma: goo::foo::funcion().

También es interesante saber que si no se especifica un namespace por adelantado, y se hace uso del operador logico ::, significara que se está buscando un metodo en
el namespace global. La mayoria de veces no será necesario usarlo, pero mira este ejemplo que proporciona learncpp para representacion visual:

#include <iostream>

void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}

namespace Foo
{
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print();   // calls print() in Foo namespace
		::print(); // calls print() in global namespace
	}
}

int main()
{
	Foo::printHelloThere();

	return 0;
}

Además de todo esto, está bien saber que un namespace puede tener un alias, como se podria hacer con el valor de una variable: 
namespace Active = Foo::Goo;

esto es util en caso de que, mas adelante, en el ciclo de vida de la aplicacion, se decida cambiar la funcionalidad de foo:goo a otro namespace. si tenemos muchas
referencias a foo:goo, cambiarlas una a una seria una tarea complicada y propensa a fallar. en cambio, si lo definimos asi, es mucho mas facil de escalar.
Además, tambien cabe destacar que se puede utilizar el mismo namespace en diferentes archivos, y que convivan entre ellos como si fuesen uno solo (asi funciona std!).

Todo lo que se defina en un namespace de ambito global, podrá entenderse como una variable o funcion global, significando esto que su ambito durará lo mismo que el 
tiempo de ejecucion del programa.

