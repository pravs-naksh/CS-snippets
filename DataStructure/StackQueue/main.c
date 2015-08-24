#include "postfix.h"

#define DEBUG 0

int main(int argc, char* argv[])
{
	char* input_string = argv[1];
  	//printf("input: %s\n",input_string);
	queue* newqueue = parseData(input_string);
#if DEBUG
	printf("new queue size: %d\n",queueSize(newqueue));
	queuePrint(newqueue);
#endif
	float res = preFix(newqueue);
  	printf("%f\n",res);
#if DEBUG
        printf("new queue size: %d\n",queueSize(newqueue));
        queuePrint(newqueue);
#endif
	res = postFix(newqueue);
        printf("%f\n",res);
	queueClean(newqueue);
	return 0;
}
