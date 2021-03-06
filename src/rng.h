// TODO: change tensor_generator to rng (random number generator)
// RNG: Random Number Generator
#ifndef SIMPLE_NN_RNG_H
#define SIMPLE_NN_RNG_H

#include <pcg_variants.h>

// ENUM: RNG_UNIFORM, RNG_NORMAL
enum rng_distribution {
    RNG_UNIFORM,
    RNG_NORMAL,
    RNG_GAUSSIAN = RNG_NORMAL
};
typedef enum rng_distribution rng_dist_t;

struct rng {
    pcg32_random_t *pcg_rng; // pcg random number generator
    uint64_t pcg_initial_state;
    uint64_t pcg_seed_value;
    rng_dist_t distribution;
};
typedef struct rng rng_t;

rng_t *allocate_rng(rng_dist_t rngd);

void free_rng(rng_t *rng);

int set_random_seed_rng(rng_t *rng, uint64_t seed_value);
int get_random_value_rng(rng_t *rng, double *output);

#endif
