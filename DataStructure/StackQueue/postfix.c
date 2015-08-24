#include "postfix.h"

queue* parseData(char *eq){
	queue* new_queue = createQueue();
	const char *input_char = eq;

	while (input_char != NULL && *input_char != '\0')
    	{
//        	printf("%c", *input_char);
		data* new_data = createData(*input_char);
		queuePush(new_queue,new_data);
        	++input_char;
    	}
	return new_queue;
}

float preFix(queue* q){
	queue* tempqueue = createQueue();
	data* tempdata = queuePop(q);
	stack* calcStack = createStack();
	int operator_required = 0;
	char* operator_mode = "";
	char first_char;
	while(tempdata != NULL){
		char input_char = tempdata->val;
		int stack_size = stackSize(calcStack);
#if DEBUG
		printf("current stack size: %d\n",stack_size);		
#endif
		if(stack_size == 0){
//			printf("input char is : %c\n",input_char);
			stackPush(calcStack,tempdata);
//			printf("stack size: %d\n",stackSize(calcStack));
			operator_required = 1;
			first_char = tempdata->val;
			queuePush(tempqueue,tempdata);
                	tempdata = queuePop(q);
			continue;
		} else if(operator_required == 1){
#if DEBUG
			printf("input char is : %c\n",input_char);
#endif
			if('+' == input_char)
				operator_mode = "ADD";
			if('-' == input_char)
                                operator_mode = "SUB";
                        if('/' == input_char)
                                operator_mode = "DIV";
			if('*' == input_char){
                                operator_mode = "MUL";
			}
			operator_required = 0;
			queuePush(tempqueue,tempdata);
                	tempdata = queuePop(q);
			continue;
		} else if(stack_size > 0){
			data* src1_data = stackPop(calcStack);
			int src1 = src1_data->val - '0';
			int src2 = tempdata->val - '0';
			int i = 0;
			if(strcmp(operator_mode,"MUL") == 0){
				i = src1 * src2;
			} else if(strcmp(operator_mode,"DIV") == 0){
				i = src1 / src2;
			} else if(strcmp(operator_mode,"SUB") == 0){
                        	i = src1 - src2;
                        } else if(strcmp(operator_mode,"ADD") == 0){
                        	i = src1 + src2;
                        }
#if DEBUG  
			printf("my ans is of %d %s %d : %d\n",src1,operator_mode,src2,i);
#endif
                        char char_int = (char)(((int)'0')+i);
                        src1_data->val = char_int;
			stackPush(calcStack,src1_data);
			operator_mode = "";
			operator_required = 1;
			//check queue size and dont break if nonempty
			if(queueSize(q)>0){
				queuePush(tempqueue,tempdata);
	          		tempdata = queuePop(q);
				continue;
			}
		}
		queuePush(tempqueue,tempdata);
#if DEBUG
		printf("new queue size: %d\n",queueSize(tempqueue));
#endif
		tempdata = queuePop(q);
	}

	data* result_data = stackPop(calcStack);
	float result = result_data->val - '0';
//	free(result_data);
//	stackClean(calcStack);
	tempqueue->ll->tail->d->val = first_char;
	*q = *tempqueue;
	return result;
}

float postFix(queue* q){
	stack* tempstack = createStack();
	data* dataStack = queuePop(q);
//	printf("sd");
//	exit(-1);
//	printf("size: %d\n",queueSize(q));
	while(dataStack != NULL){
		stackPush(tempstack,dataStack);
		dataStack = queuePop(q);		
	}

	//queue q - tempstack
	queue* tempqueue = createQueue();
        data* tempdata = stackPop(tempstack);
        stack* calcStack = createStack();
        int operator_required = 0;
        char* operator_mode = "";
        char first_char;
        while(tempdata != NULL){
                char input_char = tempdata->val;
                int stack_size = stackSize(calcStack);
#if DEBUG
                printf("current stack size: %d\n",stack_size);          
#endif
                if(stack_size == 0){
//                      printf("input char is : %c\n",input_char);
                        stackPush(calcStack,tempdata);
//                      printf("stack size: %d\n",stackSize(calcStack));
                        operator_required = 1;
                        first_char = tempdata->val;
                        queuePush(tempqueue,tempdata);
                        tempdata = stackPop(tempstack);
                        continue;
                } else if(operator_required == 1){
#if DEBUG
                        printf("input char is : %c\n",input_char);
#endif
                        if('+' == input_char)
                                operator_mode = "ADD";
                        if('-' == input_char)
                                operator_mode = "SUB";
                        if('/' == input_char)
                                operator_mode = "DIV";
                        if('*' == input_char){
                                operator_mode = "MUL";	
			}
                        operator_required = 0;
                        queuePush(tempqueue,tempdata);
                        tempdata = stackPop(tempstack);
                        continue;
                } else if(stack_size > 0){
                        data* src1_data = stackPop(calcStack);
                        int src1 = src1_data->val - '0';
                        int src2 = tempdata->val - '0';
                        int i = 0;
                        if(strcmp(operator_mode,"MUL") == 0){
                                i = src1 * src2;
                        } else if(strcmp(operator_mode,"DIV") == 0){
                                i = src1 / src2;
                        } else if(strcmp(operator_mode,"SUB") == 0){
                                i = src1 - src2;
                        } else if(strcmp(operator_mode,"ADD") == 0){
                                i = src1 + src2;
                        }
#if DEBUG  
                        printf("my ans is of %d %s %d : %d\n",src1,operator_mode,src2,i);
#endif
                        char char_int = (char)(((int)'0')+i);
                        src1_data->val = char_int;
                        stackPush(calcStack,src1_data);
                        operator_mode = "";
                        operator_required = 1;
                        //check queue size and dont break if nonempty
                        if(queueSize(q)>0){
                                queuePush(tempqueue,tempdata);
                                tempdata = stackPop(tempstack);
                                continue;
                        }
                }
                queuePush(tempqueue,tempdata);
#if DEBUG
                printf("new queue size: %d\n",queueSize(tempqueue));
#endif
                tempdata = stackPop(tempstack);
        }

	stackClean(tempstack);
        data* result_data = stackPop(calcStack);
        float result = result_data->val - '0';
        free(result_data);
        stackClean(calcStack);
        tempqueue->ll->tail->d->val = first_char;
        *q = *tempqueue;
        return result;
}
