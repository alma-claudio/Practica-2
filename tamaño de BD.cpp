/* ----------Alma Yaneli Claudio Garcia--------
          Administracion de Base de Datos 
            Calcular el tamaño de la base de
            Datos de un Hospital. 
           -> Con 35 registros por pagina.
           -> Se desean guardar 50,627,392 reguistros  
*/

#include <stdlib.h>
#include <stdio.h>

double serial=4, text=1, boolean=1, iint=4, numeric=2, real=8, varchar=1, date=3;
double num_filas=35;	//Declaramos la variable num_filas que son los registros que contiene cada hoja
double registros=50627392;//Declaramos la variable regisros que son los que se desean guardar en la BD

 double calcular_una_fila();
 double calcular_una_pagina();
  double calcular_tamano_BD ();

 main()
{
	
	printf("----Calcular el tamaño de la base de Datos de un Hospital. --- \n\t Con 35 registros por pagina. \n\t Se desean guardar 50,627,392 reguistros. \n ");
	
	printf("\n Una fila tiene:%lf bytes",calcular_una_fila());

	printf("\n Una pagina: %lf bytes",calcular_una_pagina());
		
    printf("\n tamaño de la Base de Datos en Bytes es: %lf",calcular_tamano_BD ());
    
    printf("\n tamaño de la Base de Datos en Megabytes es: %lf",(calcular_tamano_BD ()/1000000));
    
    printf("\n tamaño de la Base de Datos en Gigabytes es: %lf",(calcular_tamano_BD ()/1000000000));
}


 double calcular_una_fila()
{
// Asigamos el tamaño en bytes a cada atrivuto de la tabla
	double ID=serial, Nom_del_Hospital=30+text, Direccion=30+text, Tipo_de_servicio=boolean, Num_de_trabajadores=iint;
	double Especialidad=20+text, Horario=2+numeric, pacientes=iint, Camas=iint, Salas=iint, Elevadores=iint, Edificios=iint;
	double Extension=real, Telefono=10+varchar, Correo=25+text, Pagina_web=60+text,Nom_de_director=30+text, Ranking= iint, Fecha_de_apertura=date;
// creamos la variable que tiene el peso de una fila
    double peso_x_fila=0;
    // Calculamos el tamaño de la fila
    peso_x_fila=ID+Nom_del_Hospital+Direccion+Tipo_de_servicio+Num_de_trabajadores+Especialidad+Horario+pacientes+
	Camas+Salas+Elevadores+Edificios+Extension+Telefono+Correo+Pagina_web+Nom_de_director+Ranking+Fecha_de_apertura;
	return(peso_x_fila);
	 
}

 double calcular_una_pagina()
{
	
double num_filas=35;	//Declaramos la variable num_filas que son los registros que contiene cada hoja
//calculamos el tamaño de la pagina que es tamaño de una fila por el numero de registros que contiene la hoja

double peso_de_la_fila;//la variable que guardara el peso de una fila
peso_de_la_fila = calcular_una_fila();

 double peso_de_la_pagina;
peso_de_la_pagina= (num_filas * peso_de_la_fila);
return(peso_de_la_pagina);


}

 double calcular_tamano_BD ()
{
	// se necesitan guardar aproximadamente 50,627,392 reguistros
	
	double can_de_hojas;
	can_de_hojas=registros/num_filas;
	
	double tam_de_BD;// Declaramos la variable que guarda el tamaño de la BD
	
	//Calculamos el tamaño como las hojas que se requieren para 50,627,392 registros por 
	//el tamaño de una pagina

	return(tam_de_BD= (can_de_hojas * calcular_una_pagina() ));
	
}

