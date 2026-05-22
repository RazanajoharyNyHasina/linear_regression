#include <unistd.h>

int main(void)
{
	write(STDOUT_FILENO, "PREDICTION PROGRAM\n", 19);
	return (0);
}