static unsigned int seed = 1;

void srand(unsigned int s) {
    seed = s;
}

int rand(void) {
    seed = seed * 1103515245 + 12345;
    return ((seed / 65536) % 12)+1;
}