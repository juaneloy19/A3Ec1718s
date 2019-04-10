#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

FILE* input_i = NULL;
FILE* output_o = NULL;

void source_init_message()
{
	input_i = fopen("example_input.txt", "r");

	if(input_i == NULL)
	{
		printf("Unable to open file %s\nExit\n", "example_input.txt");
		fclose(input_i);
		exit(0);
	}
	else {
		printf("Opened file %s\n", "example_input.txt");
	}

}

char source_read_i()
{
	char sample = 0;

	if(input_i != NULL)
	{
		sample = fgetc(input_i);
		printf("Read %c\n", sample);

		if(sample == EOF)
		{
			fclose(input_i);
			input_i = NULL;
		}
	}
	return sample;
}

int source_sizeOfFile_message()
{
	fseek(input_i, 0, SEEK_END);
	int size = ftell(input_i);
	fseek(input_i, 0, SEEK_SET);
	printf("Size %d\n", size);
	return size - 2;
}

void write_init()
{
	output_o = fopen("example_output.txt", "w");

	if(output_o == NULL)
	{
		printf("Unable to open file %s\nExit\n", "example_output.txt");
		fclose(output_o);
		exit(0);
	}
	else {
		printf("Opened file %s\n", "example_output.txt");
	}
}

void write_o(char sample)
{
	if(output_o != NULL)
	{
		if (fputc(sample, output_o) != EOF) {
			printf("Write %c\n", sample);
		}
		else {
			printf("Failed to write %c\n", sample);
		}
	}
}

void write_close()
{
	if(output_o != NULL)
	{
		fputc('\n', output_o);
		fclose(output_o);
		output_o = NULL;
	}
}

int char_to_ascii(char message)
{
	int encrypted_message = (int) message;
	printf("Inside char_to_ascii\n");
	return encrypted_message;
}

char ascii_to_char(int encrypted_message)
{
	char decrypted_message = encrypted_message;
	return decrypted_message;
}

bool check_last_idx(int b)
{
	bool isOdd;

	if (b % 2){
		isOdd = true;
		printf("check_last_idx: %d is Odd\n", b);
	}
	else{
        	
		isOdd = false;
		printf("check_last_idx: %d is Even\n", b);
        }
	return isOdd;
}

int power_of_2 (int n)
{
	return pow(2,n);
}	
