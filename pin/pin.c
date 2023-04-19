#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
char** get_pins(const char* observed, size_t* count);
void free_pins(char ** pins);

int main () {
	const char * observed = "344";
	size_t expected_count = 0;
	char ** result = get_pins(observed, &expected_count);

	for (int k = 0; k < expected_count; k++){
		printf("%s\n", result[k]);
	}
	free_pins(result);
	return 0;
}


char** get_pins(const char* observed, size_t* count) {
	*count = 1;
	char** numpad = calloc(10, sizeof(char*));
	numpad[0] = "08";
	numpad[1] = "124";
        numpad[2] = "1235";
        numpad[3] = "236";
        numpad[4] = "1457";
        numpad[5] = "24568";
        numpad[6] = "3569";
        numpad[7] = "478";
        numpad[8] = "05789";
        numpad[9] = "689";
	int aObserved [strlen(observed)];
	int totalPins = 1;
	printf("%c\n", numpad[8][0]);
	for (int i = 0; i<sizeof(aObserved)/sizeof(aObserved[0]); i++){
		aObserved[i] = (int)observed[i]-48;
		totalPins *= strlen(numpad[(int)observed[i]-48]);
		printf("%i,%i\n", aObserved[i], totalPins);
	}
	*count = totalPins;
	//char arr[totalPins][strlen(observed)+1];
	char **arr = calloc(totalPins+1, sizeof(char *));
	
	int div = 1;
	for (int j = 0; j< totalPins; j++){
		arr [j]= calloc(strlen(observed)+1, sizeof(char));
		memset(arr[j]+(strlen(observed)+1)*sizeof(char), 0, sizeof(char));

	}
	for (int l = 0; l<strlen(observed); l++){
	
		div  *= strlen(numpad[aObserved[l]]);
		int counter = 0;
		int counterOff = 1;
		for (int j = 0; j<totalPins; j++){
			if (j>=totalPins/div*(counterOff+counter)){
				counter++;
			}
			if (counter>strlen(numpad[aObserved[l]])-1){
				counterOff +=counter;
                                counter = 0;
			}
			arr[j][l] = numpad[aObserved[l]][counter];
                        printf("%s---%i---%i\n", arr[j],j,counter);

		}
	}

	free(numpad);
	return arr;
}

//This function will be called once per every call to get_pins
//with a pointer value returned by such call.
void free_pins(char ** pins) {
    //...do your cleanup, if necessary
    for(int i=0; i<strlen(pins[0]);i++)
    {
        free(pins[i]);
    }

    free(pins);

}
