/**
@mainpage
@brief Simulación de una máquina de Turing
@author Alexis Rodríguez Casañas (L10)
@date 16/10/2015
*/
#include "turing.hpp"
#include "interface.hpp"

int main(int argc, char** argv)
{
	turing_machine* M;
	ifstream* file;
	ifstream* tapefile;
	Interface I;
	char filename[256];
	char op;
	
	do {
		if(argc >= 2)
		{
			strcpy(filename, argv[1]);
			if(argc == 2)
				argc = 0;
		}
		else
		{
			cout<<"Nombre del fichero (0 para salir): ";
			cin>>filename;
		}
		file = new ifstream(filename);
		if(file->is_open())
		{
			M = new turing_machine(file);
			if(argc == 3)
			{
				tapefile = new ifstream(argv[2]);
				if(tapefile->is_open())
				{
					char aux[256];
					tapefile->getline(aux, 256);
					M->put_string(aux);
				}
				else
					cerr<<"ERROR. No se encuentra la cinta"<<endl;
				argc = 0;
			}
			do
			{
				I.display_menu();
				cin>>op;
				I.select_option(op, *M, file);
			}while(op!='7');
		}
		else
			cerr<<"ERROR. No se encuentra el fichero"<<endl;
	}while(strcmp(filename, "0"));
	return 0;
}