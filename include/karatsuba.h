#ifndef KARATSUBA_H
#define KARATSUBA_H

typedef struct karatsuba_s {
    number_t *aHigh;
    number_t *aLow;
    number_t *bHigh;
    number_t *bLow;
    number_t *abHigh;
    number_t *abLow;
    number_t *aHL;
    number_t *bHL;
    number_t *res;
} karatsuba_t;

#endif // KARATSUBA_H
