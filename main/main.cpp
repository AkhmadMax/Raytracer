#include <iostream>
#include <main\statistics.h>
#include <time.h>


void a_julia();
void a_cameras();
void a_solids();
void a_indexing();
void a_teapot();

int main(int argc, char* argv[])
{
	clock_t timeStart = clock();
	//a_indexing();
	a_teapot();
	clock_t timeEnd = clock();
	
	printf("Render time                                 : %04.2f (sec)\n", (float)(timeEnd - timeStart) / CLOCKS_PER_SEC);
	printf("Total number of triangles                   : %d\n", Statistics::totalNumTris);
	printf("Total number of primary rays                : %lu\n", Statistics::numPrimaryRays);
	printf("Total number of ray-triangles tests         : %lu\n", Statistics::numRayTrianglesTests);
	printf("Total number of ray-triangles intersections : %lu\n", Statistics::numRayTrianglesIsect);
	std::cin.get();

	return 0;
}
