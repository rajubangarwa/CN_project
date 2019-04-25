#include "rpc.h"
#include <stdio.h>


float
compute_6(char *host,float a,float b,char op)
{
	CLIENT *clnt;
	float  *result_1;
	values  add_6_arg;
	float  *result_2;
	values  sub_6_arg;
	float  *result_3;
	values  mul_6_arg;
	float  *result_4;
	values  div_6_arg;

if(op=='+'){

 	add_6_arg.num1=a;
	add_6_arg.num2=b;
	add_6_arg.operation=op;

 	clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

 	result_1 = add_6(&add_6_arg, clnt);
	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}

 	clnt_destroy (clnt);

 	return (*result_1);	
}

else if(op=='-'){
	sub_6_arg.num1=a;
	sub_6_arg.num2=b;
	sub_6_arg.operation=op;
	
	clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

 	result_2 = sub_6(&sub_6_arg, clnt);
	if (result_2 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}

 	clnt_destroy (clnt);

 	return (*result_2);	
}

else if(op=='*'){
	mul_6_arg.num1=a;
	mul_6_arg.num2=b;
	mul_6_arg.operation=op;

 	clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

 	result_3 = mul_6(&mul_6_arg, clnt);
	if (result_3 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}

 	clnt_destroy (clnt);

 	return (*result_3);	
}

else if(op=='/'){
	if(b==0){
		printf("You are trying to divide by zero. Please insert a valid number.\n");
	exit(0);
	}
	else{
		div_6_arg.num1=a;
		div_6_arg.num2=b;
		div_6_arg.operation=op;

 		clnt = clnt_create (host, COMPUTE, COMPUTE_VERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}

 		result_4 = div_6(&div_6_arg, clnt);
		if (result_4 == (float *) NULL) {
			clnt_perror (clnt, "call failed");
		}

 		clnt_destroy (clnt);

 		return (*result_4);
		}	
	}

}


int
main (int argc, char *argv[])
{
	char *host;

 	float number1,number2;
	char oper;
    	printf("Enter the 2 numbers followed by the operation to perform:\n");
    	scanf("%f",&number1);
    	scanf("%f",&number2);
	scanf("%s",&oper);

 	host = argv[1];
	printf("Answer= %f\n",compute_6 (host,number1,number2,oper));
        exit(0);

}