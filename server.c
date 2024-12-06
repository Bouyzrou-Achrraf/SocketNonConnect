#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>


int main (){

	int sd  ;
	char msg [255];
	struct sockaddr_in adresse ;
	socklen_t addr_len = sizeof(adresse) ;

	sd = (socket (AF_INET , SOCK_DGRAM , 0));
	if (sd<0)
		printf("Error Of Create . \n");
		

	adresse.sin_family = AF_INET;
	adresse.sin_port = 1250;
	adresse.sin_addr.s_addr = INADDR_ANY; 


	bind (sd , ( struct sockaddr*)&adresse , sizeof(adresse));


	while(1){

		fork() ;

		recvfrom( sd , msg , sizeof(msg) , 0 , (struct sockaddr*)&adresse , &addr_len ); 
		printf("Message Recieved is : %s" , msg );

	 msg[strcspn(msg ,"\n")]=0;
        		 if (strcmp(msg , "thala")==0){
        			 printf("Fin comminucation damnded by client .\n");
        			 break;

		 }

	 printf( "Enter Your Message : ");
	 fgets(msg , sizeof(msg) , stdin);
	 sendto( sd , msg , sizeof(msg) , 0 , (struct sockaddr *)&adresse , sizeof(adresse) ); 

}

}
	

	
	

