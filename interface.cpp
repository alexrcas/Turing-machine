#include "interface.hpp"

void Interface::display_menu()
{
	cout<<"\n===== MENU PRINCIPAL ====="<<endl;
	cout<<"1. Ver fichero (maquina)"<<endl;
	cout<<"2. Mostrar estados"<<endl;
	cout<<"3. Mostrar cinta"<<endl;
	cout<<"4. Escribir en la cinta"<<endl;
	cout<<"5. Reiniciar cinta"<<endl;
	cout<<"6. Iniciar simulacion"<<endl;
	cout<<"7. Abrir un nuevo fichero"<<endl;
	cout<<"8. Salir"<<endl;
}

void Interface::select_option(char op, turing_machine& M, ifstream* file)
{
	char string[256];
	switch(op)
	{
		case '1':
			M.print_file();
			break;
		case '2':
			M.print();
			break;
		case '3':
			M.show_tape();
			break;
		case '4':
			cout<<"Introducir cadena: ";
			cin>>string;
			M.put_string(string);
			break;
		case '5':
			M.clear_tape();
			break;
		case '6':
			if (M.run())
				cout<<"CADENA ACEPTADA"<<endl;
			else
				cout<<"CADENA RECHAZADA"<<endl;
			break;
		case '7':
			file->close();
			break;
		case '8':
			file->close();
			exit(0);
			break;
		default:
		cout<<"Opcion no valida!"<<endl;
	}
}