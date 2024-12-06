#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>


int main (){

	int sd ;
	char msg [255];
	struct sockaddr_in adresse ;
	socklen_t addr_len = sizeof(adresse) ;

	sd = socket(AF_INET, SOCK_DGRAM , 0);
	if (sd < 0)
		printf("Error Of Create . /n");
	

	adresse.sin_family = AF_INET ;
	adresse.sin_port = 1250;
	adresse.sin_addr.s_addr = INADDR_ANY ; 


	while(1){
		


		printf("Enter Your Message : ");
		fgets(msg , sizeof(msg) , stdin);
		sendto( sd , msg , sizeof(msg) , 0 , (struct sockaddr*)&adresse ,sizeof(adresse) ); 

	 msg[strcspn(msg ,"\n")]=0;
        		 if (strcmp(msg , "thala")==0){
        			 printf("Fin comminucation .\n");
        			 break;

		 }

	recvfrom(  sd , msg , sizeof(msg) , 0 , (struct sockaddr*)&adresse , &addr_len  ); 
	printf("MEssage Recieved is : %s/n" , msg );



}
} 
	


	



