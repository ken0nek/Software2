#include <stdio.h>
#include <sys/time.h>
double gettimeofday_sec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}
int main(int argc, char *argv[]) {
    int c, length, *num;
    char *fname="rand.txt";
    double t0;

    enum {SELECTION, SELECTION2, BUBBLE, HEAP, MERGE, QUICK}
    sort_algorithm = SELECTION;
    char *sort_algorithm_str[] = {"SELECTION",
        "SELECTION2", "BUBBLE", "HEAP", "MERGE", "QUICK"};
    while ((c = getopt(argc, argv, "f:s2bhmq")) != -1) {
        switch (c) {
            case 'f':
                fname = argv[1]; break;
            case 's':
                sort_algorithm = SELECTION; break;
            case '2':
                sort_algorithm = SELECTION2; break;
            case 'b':
                sort_algorithm = BUBBLE; break;
            case 'h':
                sort_algorithm = HEAP; break;
            case 'm':
                sort_algorithm = MERGE; break;
            case 'q':
                sort_algorithm = QUICK; break;
        }
    }
    fprintf(stderr, "reading from %s\n", fname);
    num = read_array(fname, num, &length);
    print_array(num, length);

    fprintf(stderr, "using %s algorithm\n",
            sort_algorithm_str[sort_algorithm]);
    t0 = gettimeofday_sec();
    switch (sort_algorithm) {
        case SELECTION:
            selection_sort(num, length); break;
        case SELECTION2:
            selection_sort2(num, 0, length-1); break;
        case BUBBLE:
            bubble_sort(num, length); break;
        case HEAP:
            heap_sort(num, length); break;
        case MERGE:
            merge_sort(num, 0, length-1); break;
        case QUICK:
            quick_sort(num, 0, length-1); break;
    }
    printf("%lf[sec]\n", gettimeofday_sec()-t0);
    print_array(num, length);
    free(num);
    return 0;
}
