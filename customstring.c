
#include "customstring.h"
#include "types.h"


/************** string manipulation functions ***************************/
/*************** By Josko Radic Dec / 2018 **********************************/


t_str_result string_length(uint8_t* buff, uint32_t* length)
{
	uint32_t result_state = RESULT_OK;

	if (length != NULL && buff != NULL)
	{
		*length = 0;
		while ((*buff != NULL) && (*length < sizeof(uint32_t)))
		{
			buff++;
			(*length)++;
		}

		if (*length >= sizeof(uint32_t))
		{
			result_state |= BUFFER_SIZE_ERROR;
		}
		else
		{
			; /* calculation is ok */
		}
	}
	else
	{
		if (buff == NULL)
		{
			result_state |= INVALID_PARAM_1;
		}
		else
		{
			;
		}

		if (length == NULL)
		{
			result_state |= INVALID_PARAM_2;
		}
		else
		{
			;
		}
	}

	return (t_str_result)result_state;
}




int32_t string_length_ver2(uint8_t* buff)
{
	int32_t result = 0;

	if (buff != NULL)
	{
		while ((*buff != 0) && (result < sizeof(int32_t)))
		{
			buff++;
			result++;
		}

		if (result > sizeof(uint32_t))
		{
			result = -2; /* data is to big  */
		}
		else
		{
			; /* calculation is ok */
		}
	}
	else
	{
		result = -1; /* null pointer */
	}
	return result;
}



/* it return position of founded string , if the string doesnt exist or error happens it returns 0xffffffff */
int32_t string_find(uint8_t* input_buffer, uint8_t* searched_string)
{
	int32_t length = 0;

	uint32_t result = -1;

	uint32_t counter_new = 0;

	int32_t counter_old = 0;

	uint8_t* temp = searched_string;

	if (input_buffer != NULL && temp != NULL)
	{
		length = string_length_ver2(temp);

		if (length > 0)
		{
			while (input_buffer[counter_new] != NULL)
			{
				if (input_buffer[counter_new] == *temp)
				{
					counter_old++;
					temp++;
					if (counter_old == length)
					{
						result = (counter_new - length) + 1;
						break;
					}
					else
					{
						;
					}
				}
				else
				{
					counter_old = 0;
					temp = searched_string;
				}

				counter_new++;
			}
		}
		else
		{
			; // result = -1;
		}

	}
	else
	{
		; // result = -1;
	}

	return result;
}



int32_t string_substring(uint8_t* buff_in, uint8_t* buff_out, int32_t start, int32_t stop)
{
	int32_t counter = 0;

	while ((counter < (stop - start)) && (buff_out[counter] != '\0'))
	{
		buff_out[counter] = buff_in[start + counter];
		counter++;
	}
	buff_out[counter] = '\0';

	return counter;
}



int32_t string_substring_to(uint8_t* buff_in, uint8_t* buff_out, int32_t start, uint8_t* end_str)
{
	int32_t counter = 0;

	int32_t stop = string_find(&buff_in[start], end_str);

	if (stop > 0)
	{
		for (counter = start; counter < start + stop; counter++)
		{
			buff_out[counter - start] = buff_in[counter];
		}

		buff_out[counter - start] = '\0';
	}
	else
	{
		counter = -1;
	}


	return counter;
}






int32_t str_trim(uint8_t* buff, uint8_t* buff2)
{
	uint32_t counter = 0;

	uint32_t counter_out = 0;

	if (buff != NULL && buff2 != NULL)
	{
		uint32_t length = string_length_ver2(buff);

		if (length > 0)
		{
			for (counter = 0; counter < length + 1; counter++)
			{
				if (buff[counter] == ' ')
				{
					while (buff[counter] == ' ')
					{
						counter++;
					}
					buff2[counter_out] = buff[counter];
					counter_out++;
				}
				else
				{
					buff2[counter_out] = buff[counter];
					counter_out++;
				}
			}
		}
		else
		{
			counter_out = -1;
		}
	}
	else
	{
		counter_out = -1;
	}

	return counter_out;
}




bool string_compare(uint8_t* str1, uint8_t* str2)
{
	bool result = false;

	if (str1 != NULL && str2 != NULL)
	{
		while (*str1 == *str2)
		{
			str1++;
			str2++;
		}

		if (*str1 == '\0' && *str2 == '\0')
		{
			result = true;
		}
		else
		{
		}
	}
	else
	{
	}
    return result;
}





void str_integer_to_string(uint8_t* string_out, int32_t value)
{
	int32_t counter = 0;

	int32_t temp = 0;

	int32_t length = 0;


	bool negative = false;

	if (value != 0)
	{
		if (value < 0)
		{
			value = value * -1;

			negative = true;
		}
		else
		{
			;
		}

		temp = value;

		while (temp != 0)
		{
			temp = temp / 10;
			length++;
		}

		if (negative)
		{
			length++;
		}
		else
		{
			;
		}


		for (counter = 0; counter < length; counter++)
		{
			temp = value % 10;
			value = value / 10;
			string_out[length - (counter + 1)] = temp + '0';
		}

		string_out[length] = '\0';


		if (negative)
		{
			string_out[0] = '-';
		}
		else
		{
			;
		}
	}
	else
	{
		string_out[0] = '0';
		string_out[1] = '\0';
	}
}



//this function convert float to string
void str_float_to_string(uint8_t* str, float float_num)
{
	bool negative = false;

	int fraction = 0;

	int32_t temp = (int32_t)float_num;


	if (temp < float_num)
	{

		if (float_num < 0)
		{
			negative = true;
		}

		float_num = float_num - temp;

		fraction = (int32_t)float_num;


		while (float_num > fraction)
		{
			float_num = float_num * 10;
			fraction = (int32_t)float_num;
		}

	}
	else
	{
		//cijeli float bez decimale 132.00
	}


	temp = str_string_add_integer(str, temp, 0);

	temp = str_string_concatanate(str, (uint8_t*)".", temp);

	str_string_add_integer(str, fraction, temp);

}


/**
@brief str_hex_to_string - This function is used for converting integer to ascii string
*/
void str_hex_to_string(uint8_t* hex, int hex_buff_size, uint32_t data)
{
	uint8_t temp = data;

	uint8_t counter = (sizeof(uint32_t)* 2) + 2;

	if (counter < hex_buff_size)
	{
		hex[counter] = '\0';
		do
		{
			temp = 0x0000000F & data;

			data = data >> 4;

			if (temp < 10)
			{
				hex[counter - 1] = temp + '0';
			}
			else if (temp == 10)
			{
				hex[counter - 1] = 'A';
			}
			else if (temp == 11)
			{
				hex[counter - 1] = 'B';
			}
			else if (temp == 12)
			{
				hex[counter - 1] = 'C';
			}
			else if (temp == 13)
			{
				hex[counter - 1] = 'D';
			}
			else if (temp == 14)
			{
				hex[counter - 1] = 'E';
			}
			else if (temp == 15)
			{
				hex[counter - 1] = 'F';
			}
			else
			{

			}
			counter--;
		} while (counter - 2 > 0);

		hex[counter - 1] = 'x';
		hex[counter - 2] = '0';
	}
	else
	{

	}
}



//it concatanate strings
int32_t str_string_concatanate(uint8_t* existing_str, uint8_t* new_str, int32_t first_position)
{
	if (existing_str != NULL && new_str != NULL && first_position >= 0)
	{
		if (first_position == 0)
		{
			while (*existing_str != '\0')
			{
				existing_str++;
				first_position++;
			}

			while (*new_str != '\0')
			{
				*existing_str = *new_str;
				existing_str++;
				new_str++;
				first_position++;
			}

			*existing_str = '\0';
		}
		else
		{
			while (*new_str != '\0')
			{
				existing_str[first_position] = *new_str;
				new_str++;
				first_position++;
			}

			existing_str[first_position] = '\0';
		}
	}
	else
	{
		first_position = -1; /* error */
	}


	return first_position;
}


//it adds append integer to string
int32_t str_string_add_integer(uint8_t* existing_str, int32_t integer, int32_t first_position)
{
	uint8_t integ[10];

	str_integer_to_string(integ, integer);

	first_position = str_string_concatanate(existing_str, integ, first_position);

	return first_position;
}



//it adds append float point number as string
int32_t str_add_float(uint8_t* existing_str, float float_var, int32_t first_position)
{
	uint8_t integ[10];

	str_float_to_string(integ, float_var);

	first_position = str_string_concatanate(existing_str, integ, first_position);

	return first_position;
}
