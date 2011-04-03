/*
 * install thrust library by just unziping it's content to
 * /usr/local/cuda/include/ 
 * compile using : nvcc  version.cu -o version
 * WARNING: requires cuda 3.2 or greater 
 */
#include <thrust/version.h>
#include <iostream>

int main(void) {

	int major = THRUST_MAJOR_VERSION;
	int minor = THRUST_MINOR_VERSION;

	std::cout << "Thrust v" << major <<" . "<< minor << std::endl;

return 0;
}
