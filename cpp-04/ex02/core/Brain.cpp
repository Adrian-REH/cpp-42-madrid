
#include "../interface/Brain.hpp"
#include <iostream>
Brain::Brain(){
	std::cout << "[Created] Brain"<< std::endl;
	_ideas[0] = "La inyección de dependencias es un patrón de diseño que permite que los objetos reciban\n \
		sus dependencias desde el exterior, en lugar de crearlas internamente. Esto promueve un\n \
		código más flexible y modular, ya que permite cambiar las dependencias sin modificar el\n \
		objeto en sí. Además, facilita la prueba de las clases mediante el uso de mocks o stubs. Este\n \
		patrón también fomenta la separación de responsabilidades, lo que resulta en una\n \
		arquitectura más clara y mantenible. En el caso de un Dog, inyectar un Brain permite\n \
		reutilizar esa lógica sin acoplar el cerebro directamente al animal";
}
Brain::~Brain(){
	std::cout << "[Destroyed] Brain"<< std::endl;
}
void Brain::display(){
	std::cout << _ideas[0] << std::endl;
}