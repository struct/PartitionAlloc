#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include "config.h"
#include "PartitionAlloc.h"

PartitionAllocatorGeneric my_partition;

int main(int argc, char *argv[]) {

	printf("Root @ %p\n", my_partition.root());
	my_partition.init();
	printf("Root @ %p initialized\n", my_partition.root());

	void *p = partitionAllocGeneric(my_partition.root(), 16);
	printf("PartitionAlloc memory allocated @ %p\n", p);
	partitionFreeGeneric(my_partition.root(), p);

	void *t = malloc(1024);
	printf("Memory allocated with malloc @ %p\n", t);
	free(t);

	return 0;
}
