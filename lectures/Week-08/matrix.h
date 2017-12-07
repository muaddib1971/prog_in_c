
struct matrix
{
    int ** array;
    unsigned width, height;
};

void matrix_init(struct matrix *);
struct matrix * rand_matrix(const unsigned width, const unsigned height);
void print_matrix(struct matrix *);
void free_matrix(struct matrix *);
